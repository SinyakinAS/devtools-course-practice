// Copyright 2022 Sinyakin Andrey

#include <gtest/gtest.h>

#include <algorithm>
#include <cmath>
#include <functional>
#include <utility>
#include <vector>

#include "include/simpson_calc.h"

TEST(Sinkyakin_Andrey_SimpsonCalcTest, DefaultConstructor) {
  ASSERT_NO_THROW(SimpsonCalc());
}

TEST(Sinkyakin_Andrey_SimpsonCalcTest, Getters) {
  ASSERT_NO_THROW(SimpsonCalc());

  SimpsonCalc a;
  vector<int> test_n = {1};
  vector<pair<double, double>> test_limits = {{1, 2}};
  function<double(vector<double>)> test_func = [](vector<double> vec) {
    double x = vec[0];
    return x;
  };

  ASSERT_EQ(a.getD(), 1);
  ASSERT_EQ(a.getN(), test_n);
  ASSERT_EQ(a.getL(), test_limits);
  ASSERT_EQ(a.getFunc()({100}), test_func({100}));
}

TEST(Sinkyakin_Andrey_SimpsonCalcTest, ParamConstructor) {
  vector<int> test_n = {1};
  vector<pair<double, double>> test_limits = {{1, 2}};
  function<double(vector<double>)> test_func = [](vector<double> vec) {
    double x = vec[0];
    return x;
  };

  SimpsonCalc a(1, test_func, test_limits, test_n);

  ASSERT_EQ(a.getD(), 1);
  ASSERT_EQ(a.getN(), test_n);
  ASSERT_EQ(a.getL(), test_limits);
  ASSERT_EQ(a.getFunc()({100}), test_func({100}));
}

TEST(Sinkyakin_Andrey_SimpsonCalcTest, CopyConstructor) {
  vector<int> test_n = {1};
  vector<pair<double, double>> test_limits = {{1, 2}};
  function<double(vector<double>)> test_func = [](vector<double> vec) {
    double x = vec[0];
    return x;
  };

  SimpsonCalc a(1, test_func, test_limits, test_n);
  SimpsonCalc b(a);

  ASSERT_EQ(b.getD(), 1);
  ASSERT_EQ(b.getN(), test_n);
  ASSERT_EQ(b.getL(), test_limits);
  ASSERT_EQ(b.getFunc()({100}), test_func({100}));
}

TEST(Sinkyakin_Andrey_SimpsonCalcTest, CopyAssignment) {
  vector<int> test_n = {1};
  vector<pair<double, double>> test_limits = {{1, 2}};
  function<double(vector<double>)> test_func = [](vector<double> vec) {
    double x = vec[0];
    return x;
  };

  SimpsonCalc a(1, test_func, test_limits, test_n);
  SimpsonCalc b;
  b = a;

  ASSERT_EQ(b.getD(), 1);
  ASSERT_EQ(b.getN(), test_n);
  ASSERT_EQ(b.getL(), test_limits);
  ASSERT_EQ(b.getFunc()({100}), test_func({100}));
}

TEST(Sinkyakin_Andrey_SimpsonCalcTest, Setters) {
  SimpsonCalc a;

  int test_dim = 2;
  vector<int> test_n = {2, 2};
  vector<pair<double, double>> test_limits = {{1, 2}, {3, 4}};
  function<double(vector<double>)> test_func = [](vector<double> vec) {
    double x = vec[0];
    double y = vec[1];
    return x * y;
  };

  a.setD(test_dim);
  a.setN(test_n);
  a.setL(test_limits);
  a.setFunc(test_func);

  ASSERT_EQ(a.getD(), test_dim);
  ASSERT_EQ(a.getN(), test_n);
  ASSERT_EQ(a.getL(), test_limits);
  ASSERT_EQ(a.getFunc()({2, 3}), test_func({2, 3}));
}

TEST(Sinkyakin_Andrey_SimpsonCalcTest, Solve1) {
  printf("----- f(x,y) = x * x - 2 * y\n");

  int dim = 2;

  const std::function<double(std::vector<double>)> f =
      [](std::vector<double> vec) {
        double x = vec[0];
        double y = vec[1];
        return x * x - 2 * y;
      };

  std::vector<std::pair<double, double>> limits({{4, 10}, {1, 2}});
  std::vector<int> n({10, 10});

  SimpsonCalc solver(dim, f, limits, n);

  ASSERT_NO_THROW(solver.solve());

  double result = solver.solve();
  printf("----- %f\n", result);
}

TEST(Sinkyakin_Andrey_SimpsonCalcTest, Solve2) {
  printf("----- f(x,y) = log10(2 * x * x) + 5 * y\n");

  int dim = 2;

  const std::function<double(std::vector<double>)> f =
      [](std::vector<double> vec) {
        double x = vec[0];
        double y = vec[1];
        return log10(2 * x * x) + 5 * y;
      };

  std::vector<std::pair<double, double>> limits({{4, 10}, {1, 2}});
  std::vector<int> n({10, 10});

  SimpsonCalc solver(dim, f, limits, n);

  ASSERT_NO_THROW(solver.solve());

  double result = solver.solve();
  printf("----- %f\n", result);
}

TEST(Sinkyakin_Andrey_SimpsonCalcTest, Solve3) {
  printf("----- f(x,y) = log10(2 * x * x) + 5 * y\n");

  int dim = 3;

  const std::function<double(std::vector<double>)> f =
      [](std::vector<double> vec) {
        double x = vec[0];
        double y = vec[1];
        double z = vec[2];
        return x * y * z;
      };

  std::vector<std::pair<double, double>> limits({{4, 10}, {1, 2}, {4, 5}});
  std::vector<int> n({3, 2, 2});

  SimpsonCalc solver(dim, f, limits, n);

  ASSERT_NO_THROW(solver.solve());

  double result = solver.solve();
  printf("----- %f\n", result);
}

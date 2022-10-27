// Copyright 2022 Sinyakin Andrey

#ifndef MODULES_SINYAKIN_A_SIMPSON_CALC_INCLUDE_SIMPSON_CALC_H_
#define MODULES_SINYAKIN_A_SIMPSON_CALC_INCLUDE_SIMPSON_CALC_H_

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

using std::function;
using std::pair;
using std::vector;

class SimpsonCalc {
 public:
  SimpsonCalc();
  SimpsonCalc(const int& dim, const function<double(vector<double>)>& f,
              const vector<pair<double, double>>& limits, const vector<int>& n);
  SimpsonCalc(const SimpsonCalc& other);

  SimpsonCalc& operator=(const SimpsonCalc& other);

  function<double(vector<double>)> getFunc() const;
  vector<pair<double, double>> getL() const;
  vector<int> getN() const;
  int getD() const;

  void setFunc(const function<double(vector<double>)>& f);
  void setL(const vector<pair<double, double>>& limits);
  void setN(const vector<int>& n);
  void setD(const int& dim);

  double solve();

 private:
  function<double(vector<double>)> f;
  vector<pair<double, double>> limits;
  vector<int> n;

  int dim;
};

#endif  // MODULES_SINYAKIN_A_SIMPSON_CALC_INCLUDE_SIMPSON_CALC_H_

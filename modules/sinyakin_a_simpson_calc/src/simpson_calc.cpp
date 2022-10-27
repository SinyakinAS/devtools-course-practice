// Copyright 2022 Sinyakin Andrey

#include "include/simpson_calc.h"

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

SimpsonCalc::SimpsonCalc() {
  dim = 1;
  f = [](vector<double> vec) {
    double x = vec[0];
    return x;
  };
  limits = {{1, 2}};
  n = {1};
}

SimpsonCalc::SimpsonCalc(const int& dim,
                         const function<double(vector<double>)>& f,
                         const vector<pair<double, double>>& limits,
                         const vector<int>& n) {
  this->dim = dim;
  this->f = f;
  this->limits = limits;
  this->n = n;
}

SimpsonCalc::SimpsonCalc(const SimpsonCalc& other) {
  this->dim = other.dim;
  this->f = other.f;
  this->limits = other.limits;
  this->n = other.n;
}

SimpsonCalc& SimpsonCalc::operator=(const SimpsonCalc& other) {
  if (this == &other) return *this;

  this->dim = other.dim;
  this->f = other.f;
  this->limits = other.limits;
  this->n = other.n;
  return *this;
}

function<double(vector<double>)> SimpsonCalc::getFunc() const {
  return this->f;
}

vector<pair<double, double>> SimpsonCalc::getL() const { return this->limits; }

vector<int> SimpsonCalc::getN() const { return this->n; }

int SimpsonCalc::getD() const { return this->dim; }

void SimpsonCalc::setFunc(const function<double(vector<double>)>& f) {
  this->f = f;
}

void SimpsonCalc::setL(const vector<pair<double, double>>& limits) {
  this->limits = limits;
}

void SimpsonCalc::setN(const vector<int>& n) { this->n = n; }

void SimpsonCalc::setD(const int& dim) { this->dim = dim; }

double SimpsonCalc::solve() {
  std::vector<double> h(dim);
  int64_t counter = 1;
  for (int i = 0; i < dim; ++i) {
    h[i] = (limits[i].second - limits[i].first) / n[i];
    counter *= n[i];
  }
  double result = 0.0;
  for (int i = 0; i < counter; ++i) {
    std::vector<std::vector<double>> params(dim);
    int temp = i;
    params.reserve(dim * 6);
    for (int j = 0; j < dim; ++j) {
      auto x = limits[j].first + temp % n[j] * h[j];
      auto y = x + h[j] / 2;
      auto z = x + h[j];
      params[j].push_back(x);
      params[j].push_back(y);
      // params[j].push_back(y);
      // params[j].push_back(y);
      // params[j].push_back(y);
      params[j].push_back(z);
      temp /= n[j];
    }

    std::vector<double> point;
    int six_pow = pow(6, dim);
    for (int i = 0; i < six_pow; ++i) {
      int temp = i;
      for (int j = 0; j < dim; ++j) {
        auto x = temp % 6;
        if (x > 0 && x < 5) x = 1;
        if (x == 5) x = 2;
        point.push_back(params[j][x]);
        temp /= 6;
      }

      result += f(point);
      point.clear();
    }
    params.clear();
  }
  for (int i = 0; i < dim; ++i) {
    result *= h[i] / 6.0;
  }
  return result;
}

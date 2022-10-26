// Copyright 2022 Sinyakin Andrey

#ifndef MODULES_ANDRICH_MARIA_SORT_FACILITY_INCLUDE_SORTFACILITY_H_
#define MODULES_ANDRICH_MARIA_SORT_FACILITY_INCLUDE_SORTFACILITY_H_

#include <string>

class CLPApplication {
 public:
  CLPApplication();
  std::string operator()(int argc, const char** argv);

 private:
  std::string help();
  std::string argument_error();
};

#endif  //  MODULES_ANDRICH_MARIA_SORT_FACILITY_INCLUDE_SORTFACILITY_H_

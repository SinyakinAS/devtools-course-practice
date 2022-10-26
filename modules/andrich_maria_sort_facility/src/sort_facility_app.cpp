// Copyright 2022 Sinyakin Andrey

#include "include/sort_facility_app.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "include/SortFacility.h"

CLPApplication::CLPApplication() {}

std::string CLPApplication::operator()(int argc, const char** argv) {
  std::ostringstream os;

  if (argc == 1) {
    return this->argument_error();
  }
  if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
    return this->help();
  }
  int i = 1;

  if (std::string(argv[i]) == "--test1" || std::string(argv[i]) == "-t1") {
    Sort s;
    const char* input = argv[2];
    char output[128];

    s.shunting_yard(input, output);

    const char* answer = output;

    if (*answer == *input) os << "true";
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test2" || std::string(argv[i]) == "-t2") {
    Sort s;
    const char* input = argv[2];
    char output[128];

    s.shunting_yard(input, output);

    const char* answer = output;

    if (*answer == *input) os << "true";
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test3" || std::string(argv[i]) == "-t3") {
    Sort s;
    const char* input = argv[2];
    char output[128];

    s.shunting_yard(input, output);

    const char* answer = output;

    if (*answer == *input) os << "true";
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test4" || std::string(argv[i]) == "-t4") {
    Sort s;
    const char* input = argv[2];
    char output[128];

    s.shunting_yard(input, output);

    const char* answer = output;

    if (*answer == *input) os << "true";
    std::cout << os.str() << std::endl;
    return "success";
  }
  return "success";
}

std::string CLPApplication::help() {
  std::string help = "This program considers the integral";
  return help;
}

std::string CLPApplication::argument_error() {
  std::string error = "Invalid argument amount, try --help or -h commands";
  return error;
}

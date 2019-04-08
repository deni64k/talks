#pragma once

#include <array>
#include <string>
#include <tuple>
#include <vector>

#include "common.hxx"

struct employee {
  std::string name;
  int salary;

  EXPOSE_MEMBERS(name, salary);
};

struct organization {
  std::string name;
  std::vector<employee> employees;

  EXPOSE_MEMBERS(name, employees);
};

#pragma once

#include "common.hxx"
#include "data.hxx"

#include <yaml-cpp/yaml.h>

//
// YAML-cpp adapters
//
YAML::Emitter& operator << (YAML::Emitter& out, employee const& e) {
  out << YAML::Flow;
  out << YAML::Key << "name" << YAML::Value << e.name;
  out << YAML::Key << "salary" << YAML::Value << e.salary;
  return out;
}

YAML::Emitter& operator << (YAML::Emitter& out, organization const& e) {
  out << YAML::Flow;
  out << YAML::Key << "name" << YAML::Value << e.name;
  out << YAML::Key << "employees" << YAML::Value << e.employees;
  return out;
}

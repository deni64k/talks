#include <benchmark/benchmark.h>

#include "common.hxx"

#include "data.hxx"

#include "metayamlfmt.hxx"
#include "metayamlcpp.hxx"
#include "yamlcpp.hxx"

namespace {
int number = 42;

employee steve_jobs = {"Steve Jobs", 1};
employee tim_cook = {"Steve Jobs", 1};

organization apple = {"Apple", {steve_jobs, tim_cook}};
}

static void BM_serialize_single_integer_metayamlfmt(benchmark::State& state) {
  for (auto _ : state) {
    std::string rv [[maybe_unused]];
    rv = metayamlfmt_encoder(number);
  }
}
BENCHMARK(BM_serialize_single_integer_metayamlfmt);

static void BM_serialize_single_integer_metayamlcpp(benchmark::State& state) {
  for (auto _ : state) {
    std::string rv [[maybe_unused]];
    rv = metayamlcpp_encoder(number);
  }
}
BENCHMARK(BM_serialize_single_integer_metayamlcpp);

static void BM_serialize_single_integer_yamlcpp(benchmark::State& state) {
  for (auto _ : state) {
    YAML::Emitter out [[maybe_unused]];
    out << number;
  }
}
BENCHMARK(BM_serialize_single_integer_yamlcpp);

static void BM_serialize_single_employee_metayamlfmt(benchmark::State& state) {
  for (auto _ : state) {
    std::string rv [[maybe_unused]];
    rv = metayamlfmt_encoder(steve_jobs);
  }
}
BENCHMARK(BM_serialize_single_employee_metayamlfmt);

static void BM_serialize_single_employee_metayamlcpp(benchmark::State& state) {
  for (auto _ : state) {
    std::string rv [[maybe_unused]];
    rv = metayamlcpp_encoder(steve_jobs);
  }
}
BENCHMARK(BM_serialize_single_employee_metayamlcpp);

static void BM_serialize_single_employee_yamlcpp(benchmark::State& state) {
  for (auto _ : state) {
    YAML::Emitter out [[maybe_unused]];
    out << steve_jobs;
  }
}
BENCHMARK(BM_serialize_single_employee_yamlcpp);

static void BM_serialize_apple_employees_metayamlfmt(benchmark::State& state) {
  for (auto _ : state) {
    std::string rv [[maybe_unused]];
    rv = metayamlfmt_encoder(apple);
  }
}
BENCHMARK(BM_serialize_apple_employees_metayamlfmt);

static void BM_serialize_apple_employees_metayamlcpp(benchmark::State& state) {
  for (auto _ : state) {
    std::string rv [[maybe_unused]];
    rv = metayamlcpp_encoder(apple);
  }
}
BENCHMARK(BM_serialize_apple_employees_metayamlcpp);

static void BM_serialize_apple_employees_yamlcpp(benchmark::State& state) {
  for (auto _ : state) {
    YAML::Emitter out [[maybe_unused]];
    out << apple;
  }
}
BENCHMARK(BM_serialize_apple_employees_yamlcpp);

BENCHMARK_MAIN();

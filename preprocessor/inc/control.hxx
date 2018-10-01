#pragma once

#include "boolean.hxx"
#include "concat.hxx"

#define IF(cond, true_clause, false_clause)  IFF(BOOLEAN(cond), true_clause, false_clause)
#define IFF(cond, true_clause, false_clause) CONCAT(IFF_BOOM_, cond)(true_clause, false_clause)

#define IFF_BOOM_0(true_clause, false_clause) false_clause
#define IFF_BOOM_1(true_clause, false_clause) true_clause

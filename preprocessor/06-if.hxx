#include "inc/boolean.hxx"
#include "inc/concat.hxx"

#define IF_BOOM_0(true_clause, false_clause)  false_clause
#define IF_BOOM_1(true_clause, false_clause)  true_clause
#define IIF(cond, t, f)  CONCAT(IF_BOOM_, cond)(t, f)
#define IF(cond, t, f)   IIF(BOOLEAN(cond), t, f)

IIF(1, true, false)  //-> true
IIF(0, true, false)  //-> false
IIF(8, true, false)  //-> IF_BOOM_8(true, false)
IF (8, true, false)  //-> true

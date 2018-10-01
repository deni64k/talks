#include "inc/concat.hxx"

#define SUM_BOOM_4_2  6
#define SUM(x, y)     SUM_I(CONCAT(SUM_BOOM_, x), CONCAT(_, y))
#define SUM_I(x, y)   CONCAT(x, y)

SUM(4, 2)  //-> 6
SUM(2, 4)  //-> SUM_BOOM_2_4

#define CONCAT(x, y)  x ## y

CONCAT(1, 2)  //-> 12

#define alpha a
#define beta  b

CONCAT(alpha, beta)  //-> alphabeta

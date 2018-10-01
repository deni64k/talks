#define Q(x) #x

#define one 1

Q(1)    //-> "1"
Q(one)  //-> "one"

#define STRINGIZE(x) Q(x)

STRINGIZE(1)    //-> "1"
STRINGIZE(one)  //-> "1"

#define STRINGIZE_Q(x) #x Q(x)

STRINGIZE_Q(1)    //-> "1" "1"
STRINGIZE_Q(one)  //-> "one" "1"

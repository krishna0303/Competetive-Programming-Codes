//in binary operator it is neccessaary to write caller object to left of operator like a+b here a is caller object
//we can write this as a.operator+(b)

//but in unary operator a=-b we can write this as b.operator-();
//but it is not necessary that in unary operator operator will comes left to the caller object
//it totaly depend on operator behaviour before overloading letc ex: a=-3 so if write minus then operator ciomes before value
//similarly when we overload unary operator operator will come left side of caller objects
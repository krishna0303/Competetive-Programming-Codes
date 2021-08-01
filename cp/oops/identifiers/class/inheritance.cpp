
/*
lets say there is one class Car with some properties and some behaviours or actions now we want to create another sportsCar class 
which contain all the properties and function or behaviours of Car and also has some extra properties and behaviours 
so in this case if we are making class car anjd sportscar speperate so to reperesent a sportscar object we need two object one for CAr class and another
for SportsCar which violate the rules of encapsulation because encapsulation says all the properties and functions should be in same class for 
an object so to satisy the encapsulation we will make two seperate class but inherit proprtdios and functions of car class in sportsCar class

*/

//for multilevel inheritance we can use real life example like person->student->A div student
// or we can also take example of furniture->dining table->rounded dinnning table
//hierarchical inheritance example person->student,person->faculyt. similarly vehicle->two wheeler,vehicle->three wheeler
class A
{

} class B : A
{ //if don't write anything before A then it should be considered as private by defualt
}

//constructor inheritance order of execution of construcot from parent to child but order of call of constructot from child to parent
//destructor inheritance order of execution of destructor from child to parent and order of call of destructot from child to parent
//in destrcutors no arghumenmts needed so if we we wriote the code for destructors in parent class then we don't need to write the
//code for call of parent destrcutor because there is no arguments in destrcutors it can be called via compiler automatically

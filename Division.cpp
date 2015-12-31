/*

* Name: Abeed Alibhai, Rahul Bablani, Natasha DeCoste

* MacID: alibhaa, bablanr, decostn

* Student Number: 1428809, 1418434, 1206976

* Description: The Division class is created from the Arithmetic Expression parent class. It allocates a new left side
	and right side and then evaluates them with the AritmeticExpression::evaluate method whild dividing 
	the left by the right. 
*/

#include <iostream>
#include <string>
#include "Division.h"

using namespace std;

Division::Division(string a, string b) : ArithmeticExpression(a) {	//creating a division object from arithmetic expression parent class
	left = new ArithmeticExpression(a);			//assigning left to a new object using parameter 1
	right = new ArithmeticExpression(b);		//right pointer is a new arithmetic expression with parameter 2
}
Division::~Division() {							//the destructor
	//delete
}
float Division::evaluate() {					//the division evaluate function
	return (left->evaluate()/right->evaluate());		//calls the ArithmeticExpression::evaluate on left and right side and divides them

}
void Division::print() {					//prints out the left side divided by the right side (unevaluated)
	//print
	cout <<left<<" /"<<right<<endl;			//console print
}
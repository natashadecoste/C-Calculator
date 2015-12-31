/*

* Name: Abeed Alibhai, Rahul Bablani, Natasha DeCoste

* MacID: alibhaa, bablanr, decostn

* Student Number: 1428809, 1418434, 1206976

* Description: The Subtraction class. Creates a subtraction object (child object of the 
	Arithmetic Class). Recursively calls ArithmeticExpression::evaluate on the left and right side
	of the equation and subtracts them.

*/


#include <iostream>
#include <string>
#include "Subtraction.h"

using namespace std;

Subtraction::Subtraction(string a, string b) : ArithmeticExpression(a) {		//creates the object from the parent Arithmetic Expression
	left = new ArithmeticExpression(a);		//left pointer assigned to the first parameter, creates an Arithmetic Expression object from it
	right = new ArithmeticExpression(b);	//right pointer assigneed to the second parameter, creates an Arithmetic Expression object from it
}
Subtraction::~Subtraction() {			//the destructor method
	//delete
}
float Subtraction::evaluate() {			//the evaluate for subtraction
	return (left->evaluate() - right->evaluate());		//subtracts the Arithmetic evaluate of both sides 

}
void Subtraction::print() {	//to print out the equation
	//print
	cout <<left<<" - "<<right<<endl;	//prints the left side, then a minus and then the right side
}

//end 
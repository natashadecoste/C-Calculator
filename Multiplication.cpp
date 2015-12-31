/*

* Name: Abeed Alibhai, Rahul Bablani, Natasha DeCoste

* MacID: alibhaa, bablanr, decostn

* Student Number: 1428809, 1418434, 1206976

* Description: The multiplication class is a child class of the Arithmetic Expression class. It recursively 
	multplies the evaluate of both the left side and the right side.

*/


#include <iostream>
#include <string>
#include "Multiplication.h"						//header has the declaration of the defintions listed below

using namespace std;

Multiplication::Multiplication(string a, string b) : ArithmeticExpression(a) {		//constructs the multiplication object from the Aritmetic Expression
	left = new ArithmeticExpression(a);								//assigning left and right pointers to the 2 strings
	right = new ArithmeticExpression(b);							//assigning the right pointer to the right side of equation (second string)
}
Multiplication::~Multiplication() {									//destructor
	//delete
}
float Multiplication::evaluate() {									//completes the multiplication while reevaluating both sides through arithmetic expression
	return (left->evaluate() * right->evaluate());					//left and right are pointers to arithmetic Expression objects, it evaluates through that class

}
void Multiplication::print() {										//prints the left side and then a multiply and then right side
	//print
	cout <<left<<" * "<<right<<endl;
}
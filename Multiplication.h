#include <iostream>
#include <string>
#include "ArithmeticExpression.h"
#include "Expression.h"
using namespace std;

/*********************************************
The header file for the Multiplication class. 
Defines all functions and constructors for the
multiplication child class

*********************************************/

#ifndef MULTIPLICATION_H_
#define MULTIPLICATION_H_


class Multiplication : public ArithmeticExpression {	//child class of Arithmetic Class (therefore grandchild of Expression class)
	Expression* left;									//pointers for the left and right parts of the Expression
	Expression* right;									//right pointer
public:
	Multiplication(string, string);						//constructed with 2 parameters 
	~Multiplication();									//destructor
	float evaluate();									//evaluate function to complete the multliplication 
	void print();										//prints back the function
};														//end of class

#endif
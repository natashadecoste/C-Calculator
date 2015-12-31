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


#ifndef DIVISION_H_
#define DIVISION_H_


class Division : public ArithmeticExpression {		//child class of Arithmetic Class (therefore grandchild of Expression class)
	Expression* left;								//left side pointer
	Expression* right;								//right side pointer
public:
	Division(string, string);						//constructor with 2 parameters
	~Division();									//object destructor
	float evaluate();								//evaluate function for division
	void print();									//prints the division expression
};

#endif
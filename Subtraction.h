#include <iostream>
#include <string>
#include "ArithmeticExpression.h"
#include "Expression.h"
using namespace std;

/*********************************************
The header file for the Subtraction class. 
Defines all functions and constructors for the
multiplication child class

*********************************************/

#ifndef SUBTRACTION_H_
#define SUBTRACTION_H_


class Subtraction : public ArithmeticExpression { 	//child class of Arithmetic Class (therefore grandchild of Expression class)
	Expression* left;						//pointers for evaluating the left and right side
	Expression* right;						//right side pointer
public:
	Subtraction(string, string);			//constructor takes 2 parameters
	~Subtraction();							//destructor
	float evaluate();						//evaluate function to subtract the sides
	void print();							//prints out left side then ' - ' then the right side
};

#endif
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

#ifndef ADDITION_H_
#define ADDITION_H_


class Addition : public ArithmeticExpression {	//child class of Arithmetic Class (therefore grandchild of Expression class)
	Expression* left;							//left pointer will be assigned to the first parameter later
	Expression* right;							//right pointer will be assigned to the second parameter later
public:
	Addition(string, string);					//constructor takes 2 parameters
	~Addition();								//the destructor for the object
	float evaluate();							//evaluate for addition
	void print();								//prints the equation out
};

#endif
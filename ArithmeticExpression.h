#include <iostream>
#include <stack>
#include "Expression.h"

using namespace std;


#ifndef ARITHMETICEXPRESSION_H_
#define ARITHMETICEXPRESSION_H_

class ArithmeticExpression : public Expression {	//child class of Expression, parent to Mult, add, sub, div classes
	string exp;										//private variable to hold the string from which the expression is made
	Expression* left;								//Expression pointers for left side and right side
	Expression* right;								//right side expression pointer
	char* rahul;									//rahul pointer
public:
	ArithmeticExpression(string);					//constructor(takes one parameter)
	~ArithmeticExpression();						//destructor
	float evaluate();								//the evaluate function
	virtual void print();							//print method


};
#endif
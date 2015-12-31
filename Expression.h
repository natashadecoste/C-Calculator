#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

/*********************************************
The header file for the Multiplication class. 
Defines all functions and constructors for the
multiplication child class

*********************************************/

#ifndef EXPRESSION_H_
#define EXPRESSION_H_


class Expression {
	string exp;	//private string variable holds the user input expression
public:
	Expression(string);	//constructor takes one parameter (string)
	~Expression();			//destructor for object
	int getSize();			//returns int of the size of the string (exp)
	virtual float evaluate();	//calls evaluate which calls the evaluate in Arithmetic Expression
	int toInt();				//returns an int of a character in exp
	char getChar(int);			//gets the character at an index 
	bool isNumber();			//checks if there is a number
	Expression brkupleft(char);	//to break up expressions at a character and return a new expression from the left side
	Expression brkupright(char);//to breakup expression at a character and return a new expression from the right side
	void increment();			//used to increment all the numbers in the expression
	virtual void print();		//prints the expression
	bool isOperand(char);		//checks for allowed operands
	string returnExp();			//returns the expression


};

#endif
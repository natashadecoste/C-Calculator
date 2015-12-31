/*

* Name: Abeed Alibhai, Rahul Bablani, Natasha DeCoste

* MacID: alibhaa, bablanr, decostn

* Student Number: 1428809, 1418434, 1206976

* Description: This is the Arithmetic Expression class (which inherits) from the
	Espression class. The evaluate creates objects of the child classes (addition,
	subtraction, division and multiplication).

*/


#include "ArithmeticExpression.h"
#include "Expression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;



ArithmeticExpression::ArithmeticExpression(string a) : Expression( a ){	//constructs the object from Expression class (its parent)
	exp = a;	//storing the string in exp
	rahul = &exp[0];	//rahul pointer pointing to the first of the characters in exp

}

ArithmeticExpression::~ArithmeticExpression(){ 	//the destructor
	//delete
	delete rahul; 

}

float ArithmeticExpression::evaluate() {	//the evaluate function
	stack<char> s;	//creates a stack in order to track the sets of brackets in the expression
	int counter = 0;//init counter

	int digits = 0;	//to count digits so we can evaluate the base case
	for (size_t i = 0; i < exp.length(); i++) {		//parse though expression
		if (isdigit(exp[i])) {						//if it is a digit 
			digits += 1;							//add to the digit counter
		}											
	}
	if (digits == exp.size()) {						//to check if digit number is =  to the size of the expression, it means that the expression is JUST a number
		int value = atoi(exp.c_str());				//conversions
		float val = (float)value;
		return val;									//returns the values because there isnt anything to perform a calulation with (no operands)
	}
	else if (exp == "") {							//if the person inputs nothing, just presses enter
		return 0;									// = 0 like a regular calculator
	}

	for (size_t x = 0; x < exp.size();x++) {	//parses through using the character pointer (until it has gone through the whole string)
		if (*rahul == '(') {			//for left brackets it pushes the bracket onto the stack
			s.push(*rahul);
		}
		else if (*rahul == ')') {		//right brackets pop the stack
			if (s.empty()) {		//if there is a right bracket without there being atleast 1 left bracket in the stack
				cout << "incorrect input 3" << endl;		//the brackets are wrong
			}
			else { s.pop(); }	//if there is atleast one left bracket on the stack, we pop it
		}
		else {
			//do nothing, its a digit or other character
		}
		if (s.empty() && *rahul == '+') {
			Addition x = Addition(exp.substr(0,counter), exp.substr(counter+1,exp.length())); //if it is addition we split it at the addition sign and use left side as paramter 1 and right as parameter 2
			return x.evaluate();	//evaluate the new addition object, calls Addition::evaluate on the object
		}

		rahul++;		//incrementing the char pointer
		counter++;		//incrementing the counter
	} //end of for loop

	rahul = &exp[exp.size()-1];		//need to reassign the pointer location to the last char
	counter = exp.size()-1;			//re initalize the counter to size of exp


	for (size_t x = 0; x < exp.size();x++) {	//parses through using the character pointer (until it has gone through the whole string)
		if (*rahul == ')') {			//for left brackets it pushes the bracket onto the stack
			s.push(*rahul);
		}
		else if (*rahul == '(') {		//right brackets pop the stack
			if (s.empty()) {		//if there is a right bracket without there being atleast 1 left bracket in the stack
				cout << "incorrect input 3" << endl;		//the brackets are wrong
			}
			else { s.pop(); }	//if there is atleast one left bracket on the stack, we pop it
		}
		else {
			//do nothing, its a digit or other character
		}

		if (s.empty() && *rahul == '-') {	//if there is a minus sign we need to split it up at
			Subtraction x = Subtraction(exp.substr(0, counter), exp.substr(counter+1, exp.length()-1));		//creates a subtraction object
			return x.evaluate();  //evalautes that subtraction object, uses Subtraction::evaluate()
		}

		rahul--;		//decrementing the char pointer
		counter--;
	} //end of for loop
	
	  
	
	rahul = &exp[0];
	counter = 0;
	
	for (size_t x = 0; x < exp.size();x++) {	//parses through using the character pointer (until it has gone through the whole string)
		//cout << *rahul << endl;
		if (*rahul == '(') {			//for left brackets it pushes the bracket onto the stack
			s.push(*rahul);
		}
		else if (*rahul == ')') {		//right brackets pop the stack
			if (s.empty()) {		//if there is a right bracket without there being atleast 1 left bracket in the stack
				cout << "incorrect input 3" << endl;		//the brackets are wrong
			}
			else { s.pop(); }	//if there is atleast one left bracket on the stack, we pop it
		}
		else {
			//do nothing, its a digit or other character
		}

		if (s.empty() && *rahul == '/') {			//find divisor
		Division x = Division(exp.substr(0,counter), exp.substr(counter+1,exp.length()));		//create division object
		return x.evaluate();		//evaluate the Division object with Division::evaluate()
		}

		rahul++;		//incrementing the char pointer
		counter++;
	} //end of for loop
	


	rahul = &exp[0];	//reassign pointer location
	counter = 0; 		//reinitiate counter

	
	for (size_t x = 0; x < exp.size();x++) {	//parses through using the character pointer (until it has gone through the whole string)
			if (*rahul == '(') {			//for left brackets it pushes the bracket onto the stack
				s.push(*rahul);
			}
			else if (*rahul == ')') {		//right brackets pop the stack
				if (s.empty()) {		//if there is a right bracket without there being atleast 1 left bracket in the stack
					cout << "incorrect input 3" << endl;		//the brackets are wrong
				}
				else { s.pop(); }	//if there is atleast one left bracket on the stack, we pop it
			}
			else {
				//do nothing, its a digit or other character
			}

			if (s.empty() && *rahul == '*') {		//for multiplication
			Multiplication x = Multiplication(exp.substr(0,counter),exp.substr(counter+1,exp.length()));	//creating an object of Multiplication Class
			return x.evaluate();	//evaluating with Multiplication::evaluate()
			}


			rahul++;		//incrementing the char pointer
			counter++;
	} //end of for loop 

		if (exp[0] == '(' && exp[exp.size() - 1] == ')') {	//this is going to strip the brackets
			exp = exp.substr(1, exp.size() - 2);
			ArithmeticExpression temp = ArithmeticExpression(exp);	//reevaluate without the brackets
			return temp.evaluate();		//ArithmeticExpression::evaluate on the new one without the brackets
		}

		return 0.0;	//escape return function

}

void ArithmeticExpression::print(){		//prints out the arithmetic Expression
	cout<< exp<<endl;					//console print
}

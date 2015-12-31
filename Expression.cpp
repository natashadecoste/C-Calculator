/*

* Name: Abeed Alibhai, Rahul Bablani, Natasha DeCoste

* MacID: alibhaa, bablanr, decostn

* Student Number: 1428809, 1418434, 1206976

* Description: The Expession class is the parent of all the other classes (highest in the hierachy). The evaluate prints 
	out the expression and then it uses creates the Arithmetic Expression and evaluates with that class. 
*/


#include <iostream>
#include <string>
#include <algorithm>
#include "Expression.h"
#include "ArithmeticExpression.h"
#include <stdlib.h>
#include <iomanip>
#include <sstream>


using namespace std;

Expression::Expression(string a) {	//creating the parent class (takes in a string as a parameter)
	exp = a;	//storing the expression string as a variable in the object
}

Expression::~Expression() {		//destructor for the object
	//delete
}

float Expression::evaluate() {//the evaluate for Expression, creates Arithmetic Expression objects and evaluates those
	print();
	cout <<" = ";		//prints out the original string input and the equals sign
	ArithmeticExpression a = ArithmeticExpression(exp);		//makes an Arithmetric Expression object with the same string
	cout << fixed << setprecision(2);		//sets the precision for cout for the output of the result
	cout << a.evaluate();				//evaluate function
	return 0;							//escape
}

int Expression::toInt() {				//changes exp to an integer
	int value = atoi(exp.c_str());		//stores it in value variable
	return value;						//returns the int
}

int Expression::getSize() {				//method to return the size of the exp string
	return exp.size();					//returns the int
}

char Expression::getChar(int a) {		//gets the character at an index a
	return exp[a];						//returns the character
}
Expression Expression::brkupleft(char a) {		//breaks apart the function at a character and returns an expression with the first half
	return Expression(exp.substr(0,exp.find(a)));
}

Expression Expression::brkupright(char a) {		//breaks apart the function at a character and returns an expression with the second half
	return Expression(exp.substr(exp.find(a)+1,exp.length()));
}

bool Expression::isOperand(char s){
	if ((s == ')') || (s == '(') || (s == '*') || (s == '+') || (s == '-') || (s == '/')) {		//to check for valid operand for this calculator
		return true;	//returns true if the operand is acceptable
	}
	else
		return false;			//returns false for other non valid operands
}		//close bracket for the isOperand function


void Expression::increment(){		//this is to increment the expression if the user input @
			string newEx;			//variable for the newexpression
			string stringVal;		//will hold the temporary string of the new value (the old value + 1)	
			string num;				//we will build a string here for the seperate numbers


			for(size_t abeed = 0; abeed < exp.size(); abeed++){		//initialize a counter to parse through the expression

				if(isOperand(exp[abeed])){		//if its an operand
					if (isdigit(exp[abeed-1])){		//and the one before is a digit

						int value = atoi(num.c_str());	//we change it to an integer
						value +=1;						//we increment it by one
						stringVal = static_cast<ostringstream*>( &(ostringstream() << value) )->str();	//cast it back into a string
						newEx.insert(newEx.size(), stringVal);		//insert the new string into the newEx
						num = "";	//clear the number string
						newEx.push_back(exp[abeed]);	//we push the operand into the string after we have added the string of the new number


					}
					else{
						newEx.push_back(exp[abeed]);	//if not beside a digit, we just add the operand onto the newEx

					}

				}//if isOperand end
				else{ //if theres a digit 
						num.push_back(exp[abeed]);	//adding all numbers to num, building a string of numbers to cast into integer when we find an operand
					} //end of if start is true

			}//end of abeed for loop
			if(num !=""){	//means that we are at the end of the string and it ends with a number, ex 9+8, num would be ="8"
				int value = atoi(num.c_str());	//make num into an integer
				value +=1;			//increment the value of the number +1
				stringVal = static_cast<ostringstream*>( &(ostringstream() << value) )->str();		//parse back into a string
				newEx.insert(newEx.size(), stringVal);		//insert it into the newEx string
				num = "";		//clear num again

			}
			//time to evaluate
			exp = newEx;	//assigning the object variable to exp so we can call Expression::evaluate() on it
}

string Expression::returnExp(){	//to return the expression String
	return exp;
}

void Expression::print(){		//prints out the Expression
	cout << exp;		//console print
}


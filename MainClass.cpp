/*

* Name: Abeed Alibhai, Rahul Bablani, Natasha DeCoste

* MacID: alibhaa, bablanr, decostn

* Student Number: 1428809, 1418434, 1206976

* Description: This is the main class for calling all the math classes to evaluate an expression. It takes in an 
	Expression from the user and then it calls the other classes in order to evaluate it. This class does all the checks for the input
	to make sure that brackets match, the spacing is good and that there aren't any illegal operations.

*/

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <algorithm>
#include "Expression.h"
#include "ArithmeticExpression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"

using namespace std;

/*this function checks if a character is an acceptable operand for this C++ calculator */
bool isOperand(char s) {
	if ((s == ')') || (s == '(') || (s == '*') || (s == '+') || (s == '-') || (s == '/')) {		//to check for valid operand for this calculator
		return true;	//returns true if the operand is acceptable
	}
	else
		return false;			//returns false for other non valid operands
}		//close bracket for the isOperand function



/*this checks that for every function that has an open bracket, there is a close bracket */
bool bracketCheck(char* sPtr, int stringSize) {	//takes a character pointer and the actual string
	stack<char> s;	//creates a stack

	for (int x = 0; x< stringSize;x++) {	//parses through using the character pointer (until it has gone through the whole string)
		if (*sPtr == '(') {					//checks if it is a left bracket
			s.push(*sPtr);					//for left brackets it pushes the bracket onto the stack
		}
		else if (*sPtr == ')') {		//right brackets pops the stack
			if (s.empty()) {			//if there is a right bracket without there being atleast 1 left bracket in the stack
				//delete sPtr;						//the brackets are wrong
				return false;			//return false =  the brackets are incorrect
			}
			else { s.pop(); }	//if there is atleast one left bracket on the stack, we pop it 
		}
		else {
			//do nothing, its a digit or other character
		}
		sPtr++;		//incrementing the char pointer
	}


	if (s.empty()) {			//at the end if the stack is empty then it is all matched
		//delete sPtr;
		return true; 	//all brackets are matched
	}
	else {
		//delete sPtr;
		return false;	//if the stack isnt empty then brackets are unmatched 
	}

}

bool expAllowed(string exprs) {				//tests for all inputs that are not allowed like letters and unavailable characters

	/* LOOP TO TEST FOR ALL THE UNALLOWED INPUTS */
	for (size_t i = 0; i<exprs.length();i++) {


		//checks the first character is not a ), /, *
		if ((isdigit(exprs[0]) || exprs[0] == '(') == false) {	//check if the first character is a digit or a left bracket
			cout << "Expression is not well formed." << endl;		//error statement
			return false;							//expression isnt acceptable
		}


		//checks the last character
		if ((isdigit(exprs[exprs.size() - 1]) || exprs[exprs.size() - 1] == ')') == false) { 		//checks if the last character is a digit or right bracket
			cout << "Expression is not well formed." << endl;	//error statement
			return false;
		}

		//to check if there are () without integers inside
		if ((exprs[i]) == '(') {	//finds a left bracket
			if (exprs[i + 1] == ')') {	//checks that the character beside it isnt a right bracket
				cout << "Expression is not well formed." << endl;	//error statement
				return false;
			}
			if ((i != 0) && isdigit(exprs[i - 1])) {		//checks that there isnt a number right before a opening left bracket '8('
				cout << "Expression is not well formed." << endl;	//error statement
				return false;
			}
		}

		if (exprs[i] == ')') {				//check that there arent any )( because our program doesnt allow that
			if (exprs[i + 1] == '(') {		//to check that the next character isnt a left bracket
				cout << "Expression is not well formed." << endl;	//error statement
				return false;
			}
			if (isdigit(exprs[i + 1]) && (exprs[i + 1] != ')')) { //checking that after a right bracket there isnt a digit ')9' but double right is allowed '))'
				cout << "Expression is not well formed." << endl; //error statement
				return false;
			}
		}

		if ((isOperand(exprs[i])) && (exprs[i] != '(') || (exprs[i] == ')')) {
			if ((isOperand(exprs[i - 1])) && (exprs[i - 1] != '(') && (exprs[i - 1] != ')')) {
				cout << "Expression is not well formed." << endl; 	//error statement
				return false;
			}
		}

		//if its not an accepted symbol
		if (!(isdigit(exprs[i])) && (isOperand(exprs[i]) == false)) {
			cout << "Expression is not well formed." << endl;	//error statement
			return false;
		}

		// checks the brackets match
		char* sPtr = &exprs[0]; //assigns a pointer to the expression entered

		if (bracketCheck(sPtr, exprs.size()) == false) { //checks with the bracketCheck function
			cout << "Expression is not well formed." << endl; 	//error statement if bracketCheck returns false
			return false;
		}

	} // end of the check for validity
	return true;		//if it goes through all the tests then it is returned true for good inputs


}


bool checkSpaces(string exprs) {
	for (size_t i = 0;i < exprs.length();i++) {
		if ((exprs[i] == ' ') && (isdigit(exprs[i-1]))) {
			for (size_t j = i; j < exprs.length();j++) {
				if (isdigit(exprs[j])) {
					//there is spaces in between numbers 
					cout << "Expression is not well formed." << endl;
					return false;
				}
				if ((isOperand(exprs[j])) && (exprs[j] != '(') &&( exprs[j] != ')')) {
					break;
				}
				if (exprs[j] == ' ') {
					//nothing
				}
			}

		}	//end of if loop

	} //end of for loop

	return true;
}

int main() {
	string exprs;	//string variable to hold the expression to be evaluated
	string pre = "";	//empty string (but will later hold the previous expression as a string in order to use @)
	do {				//we want to keep repeating the loop of calculations until the user inputs a #


		
		cout << endl;
		cout << "-------------------------------------------" << endl;
		cout << endl;
		cout << "Please input your Integer arithmetic expression:" << endl;	//message to get input
		cout << endl;
		getline(cin, exprs);				//assigning the input to exprs variable


		if (exprs == "@"){		//bonus question, the user inputs each number by 1 in the previous ewuation
			
			if(pre == ""){		//if they enter it without there being a previous answer
				cout<< "There is no last Expression"<<endl;		//error message
			}
			else{				//if they enter @ we need to increment the last expression and reprint 
			Expression a = Expression(pre);		//creates an expression with the last expression
			a.increment();						//increments all the numbers in the expression
			pre = a.returnExp();				//re assigns the pre string so you can use the @ function over and over, we created a new method called returnExp that returns the stringg
			a.evaluate();						//calling Expression::evaluate() to evaluate it
			}
						
		} //end of if expression is @

		else if (exprs =="#"){		//if they input a #, they want to exit the calculator 
			break;					//break
		}

		else {						//they entered an expression to evaluate
			if (checkSpaces(exprs)) {		//check that spaces are correct, they only matter when they are in between 2 digits
				exprs.erase(std::remove(exprs.begin(), exprs.end(), ' '), exprs.end());		//we then erase the spaces so we can work with a string of operands and digits

				if (expAllowed(exprs)) { //this does all other checks (incorrect ordering of operands, bracket checks, check for characters, etc)
					//the expression is legit
					//do stuff with expr
					pre = exprs;	//so that we can use it if the user inputs @ the next time
					Expression a = Expression(exprs);	//creating an expression from the string
					a.evaluate();						//calling Expression::evaluate() to evaluate it

				} //end of expAllowed loop

			} //end of check spaces
		
		}//end of else statement

	} while (exprs != "#"); //exprs do while loop that lets user keep inputing things 
	
	return 0;	//terminate the main
}

/*

* Name: Abeed Alibhai, Rahul Bablani, Natasha DeCoste

* MacID: alibhaa, bablanr, decostn

* Student Number: 1428809, 1418434, 1206976

* Description: The Addition class. Creates an addition object (child object of the 
	Arithmetic Class). Recursively calls ArithmeticExpression::evaluate on the left and right side
	of the equation.

*/

#include <iostream>
#include <string>
#include "Addition.h"

using namespace std;

Addition::Addition(string a, string b) : ArithmeticExpression( a ){		//creates the object from its parent Arithmetic Expression
	left = new ArithmeticExpression(a);								//assigning the first parameter to the left side pointer, creating an Arithmetic Expression object from it
	right = new ArithmeticExpression(b);							//assigning right pointer to the right parameter creating an Arithmetic Expression
}
Addition::~Addition() {							//the destructor for the object
	//delete
}
float Addition::evaluate() {					//the evaluate for addition class
	return (left-> evaluate() + right-> evaluate());		//returns the ArithmeticExpression::evaluate of the the left side and the one for right side

}
void Addition::print() {					//prints the left side and then a plus and then right side
	cout <<left<<" + "<<right<<endl;
	//print
}

//end
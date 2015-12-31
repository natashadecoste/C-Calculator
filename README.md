# C-Calculator
THIS IS THE README FILE FOR c++ CALCULATOR

The purpose of this was to learn and use OOP logic and work with memory allocation and deallocation. 

This calculator takes input from the user, validates the expression (legal arithmetic expression, no exponents, no characters) and then it evaluates it using Expression Tree logic. 


********************************

Valid Inputs

Includes the operands *, /, +, -
Includes the rounded bracket symbols () but excludes all others [],{}

Excludes all other symbols and excludes all Letters/Characters

There cannot be double operands "*-" unless one is a bracket ")-" ,"+("

There cannot be spaces in between digits, "8       9" is incorrect input and not evaluated as 89.

There can be spaces in between operands and numbers; "1+      99" is legal

Operand "#" is valid because it allows the program to exit (otherwise it is a continuous loop requiring inputs from the user)

Operand "@" is valid because it allows the user to re-evaluate the last expression but incrementing the numbers by 1.
Note: -55 becomes -56 NOT -54. It solely increments the number and not the integer value

**********************************

Class Files

There is a parent class Expression which consists mostly of virtual methods to be overridden. Inheriting from the parent class is the ArithmeticExpression class. This parses through and reassigns left and right side pointers to the left/right side and also reclasses them under their apropriate mathematic class (Multiplication, Division, Addition, Subtraction).


**********************************

To Run

via CMD:

$ c++ MainClass.cpp -o MainClass.exe
$ MainClass


***********************************

Final Notes:
There are some memory leakages evident in the program as it is.


***********************************

This project was made with the collaboration of Rahul Bablani and Abeed Alibhai.

/*
	Jeffrey Carson
	CS302
	9/13/20
	Reading postfix form of arithmetic expression and calculating result
*/
#include <iostream>
#include <string>

using namespace std;

#include "config.h"

#if !LAB6_TEST1
#  include "StackArray.cpp"
#else
#  include "StackLinked.cpp"
#endif
//MAX SIZE OF ARRAY
const int MAX_SIZE = 100;
//PROMPTS USER AND GETS INPUT
void getPostfix(char array[]){
	cout << "\nEquation: ";
	cin.get(array, MAX_SIZE);
}
//PRINTS STRING INPUTTED BY USER
void print(char array[]){
	
	for ( int i = 0; array[i] != '\0'; ++i){
		cout << array[i];
	}
	cout << endl;
}
//TAKES A NUMBER AND A POWER TO RAISE IT TO, RETURNS RESULT
double exponent(double num, double exp){
	double temp = num;
	for (int i = 0; i < exp-1; ++i){
		//cout << num << " ";
		num *= temp;
	}
	return num;
}
//PROMPTS USER AND GETS CHOICE
int userMenu(int choice){
	cout << "---POSTFIX CALCULATOR---\n";
	cout << "1) - Evaluate Postfix Expression\n2) - Exit Program\nChoice: ";
	cin >> choice;

	return choice;
}
//EVALUATES POSTFIX EXPRESSION
double evaluate(char array[]){
	//allowing config.h to determine use of array implementation or linked implementation.
	#if !LAB6_TEST1
	StackArray<double> operand;
	#else
	StackLinked<double> operand;
	#endif
	
	double result = 0;
	double num1 = 0, num2 = 0;
	
	//int temp;
	
	//looping through array passed into function
	for (int i = 0; array[i] != '\0'; ++i){
		//Ignores value if white space
		if (array[i] != ' '){
			//if a number character, pass into stack as int.
			switch (array[i]){
				case '0':
					operand.push(0);
					break;
				case '1': 
					operand.push(1);
					break;
				case '2': 
					operand.push(2);
					break;
				case '3': 
					operand.push(3);
					break;
				case '4': 
					operand.push(4);
					break;
				case '5':
					operand.push(5);
					break;
				case '6': 
					operand.push(6);
					break;
				case '7': 
					operand.push(7);
					break;
				case '8': 
					operand.push(8);
					break;
				case '9':
					operand.push(9);
					break;
				//If character is an operator, perform corresponding task
				case '+' :
					num1 = operand.pop();				
					num2 = operand.pop();					
					result = num1 + num2;
					operand.push(result);				
					break;
				case '-' :
					num1 = operand.pop();
					num2 = operand.pop();
					result = num2 - num1;
					operand.push(result);
					break;
				case '*':
					num1 = operand.pop();
					num2 = operand.pop();
					result = num1 * num2;
					operand.push(result);
					break;
				case '/':
					num1 = operand.pop();
					num2 = operand.pop();
					result = num2 / num1;
					operand.push(result);
					break;
				case '^':
					num1 = operand.pop();
					num2 = operand.pop();
					result = exponent(num2, num1);
					operand.push(result);
					break;
				default:
					cout << "INCORRECT INPUT\n";
					break;
			}
		}
	}
	return result;
}

int main(){
	//Letting user know what stack implementation is being utilized.
	#if !LAB6_TEST1
		cout << "--USING ARRAY STACK IMPLEMENTATION--\n";
	#else
		cout << "--USING LINKED STACK IMPLEMENTATION--\n";
	#endif
	char postA[MAX_SIZE];
	double result;
	int menu;
	/*do {
		menu = userMenu(menu);
		switch (menu){
			case 1:*/
	getPostfix(postA);
	result = evaluate(postA);
	cout << "Result: " << result << endl << endl;
	/*			break;
			case 2:
				break;
			default:
				cout << "\nWrong Input\n";
				break;
			
		}	
	}while (menu != 2);
	
*/
	return 0;
}

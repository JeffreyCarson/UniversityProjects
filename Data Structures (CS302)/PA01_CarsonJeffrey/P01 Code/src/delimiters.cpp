//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>

#include "config.h"

#if LAB6_TEST1
#   include "StackLinked.cpp"
#else
#   include "StackArray.cpp"
#endif

//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main()
{
	//Letting user know what implementation is being used.
	#if !LAB6_TEST1
		cout << "--USING ARRAY STACK IMPLEMENTATION--\n";
	#else
		cout << "--USING LINKED STACK IMPLEMENTATION--\n";
	#endif
	//
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;
    
        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below

bool delimitersOk ( const string &expression ){
	//allowing config.h to determine use of array implementation or linked implementation.
	#if !LAB6_TEST1
	StackArray<char> s;
	#else
	StackLinked<char> s;
	#endif
	char temp;
	//Looping through string until null character is hit
	for (int i = 0; expression[i] != '\0'; ++i){
		switch (expression[i]){
			case '(' : case '{' : case '[' :
				s.push(expression[i]);
				break;
			case ')' : case '}' : case ']' :
				//Checking to see if array is empty before popping. If it is empty, return false
				if (!s.isEmpty()){
					temp = s.pop();
					//Checing if brackets match, if not, return false
					if (temp == '{' && expression[i] == '}'){break;}
					if (temp == '[' && expression[i] == ']'){break;}
					if (temp == '(' && expression[i] == ')'){break;}
					else {
						return false;
					}
				}
				else {
					return false;
				}	
				break;
			default:
				break;
		}   
	}
	if (s.isEmpty()){
		return true;
	}
	else {
		return false;
	}
}

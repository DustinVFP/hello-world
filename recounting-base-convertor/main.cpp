/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following disclaimer
 *   in the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name of the  nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

/* recounting base convertor Version 1.0
 * 
 * the purpose of this code is to convert one number base to another (example: convert base 10 to base 8)
 * 
 * this code is probably not useful to anything because of how it works and that its output is an array
 * also it couldn't even be included in another application without modification because of how it works
 */

#include <iostream>
#include <stdio.h>

using namespace std;

// Initialise Values
int Input[100];
int InputInvers[100];
int BaseFrom;
int BaseTo;
int Count1[100] = {0};
int Count2[100] = {0};
int DigitAMT;
int DigitAMT2 = 0;
bool IsSame;

void Function_int_Count2() {for (int i; i < 100; ++i) {Count2[i]=0;};}	// function to set all values in the variable Count2 to 0 (will probably be removed as its unnecessary)

//bool debug = true; // debug value bool (not really used)

// Function for getting input values
void GetInput(){
	cout << "Enter base you want to convert from" << endl;			// display info for user
	cin >> BaseFrom;												// get base type to convert from
	cout << "Enter base you want to convert to" << endl;			// display info for user
	cin >> BaseTo;													// get base type to convert to
	cout << "Enter input value" << endl;							//|display instructions for user
	cout << "Note you have to enter each digit seperatly" << endl;	//|
	cout << "this is because of how the program works" << endl;		//|

	//if (BaseFrom > 10) {		// display note for numbers higher than base 10
	//	cout << "note with numbers higher than base 10 you have to enter each digit as a base 10 number (eg hex:A would be entered as 10)" << endl;
	//	}
		
	cout << "enter -1 to continue" << endl;		// display instruction for user
	
	for (int i = 0, x ; i < 100 ; ++i) {		// main input loop to get input number
		cin >> x;								// enter input instruction
		if (x == -1) {break;} else {			// check if input digit is higher than allowed by selected base and display warning if so
			if (x >= BaseFrom) {x = (BaseFrom-1); cout << "the number you inputed is higher than the selected base the number was automatically reduced to the max allowed by your input base" << endl;}; 
			Input[i] = x;						// add input number to array
			DigitAMT = i; 						// set digit count (this is mainly for the display function)
			// cout << DigitAMT << endl;		// debug code
		};
	};
	// if (debug == true) {for (int i = 0 ; i < (DigitAMT+1) ; ++i) {cout << Input[i];}; cout << endl;}; // debug code
}

	// function to compare number to base
int Function_CheckNum(int b , int num , bool opt) {					// compare and return function
	//cout <<"b: "<< b <<" num: "<< num <<" opt: "<< opt << endl;	// debug code
	if (num > (b - 1)) {											// check if number is higher than the base number if yes then run next line
		if (opt == true) {return 0;} else {return 1;};				// if opt is true then return 0, if bool is false then return command to add to next digit
		} else {													// if number is not higher than base then run next line
		if (opt == true) {return num;} else {return 0;};			// if opt is true return number. if bool is false return 0
		};
}

	// main function
int main() {
	Function_int_Count2();	// run function (will probably be removed as its purpose is unnecessary)
	GetInput(); 			// run getinput function
	for (int c = 0, x = DigitAMT ; c <= DigitAMT ; ++c) {InputInvers[c] = Input[x]; --x;};	// copy Input array to InputInverse and reverse order for calculations
	for (unsigned int cycleC = 0 ; cycleC < 2147483647 ; ++cycleC) {						// main loop also a failsafe to prevent an infinite loop
	
	Count1[0] = Count1[0] + 1; 						// increment reference number 
	//cout << Count1[0] << " digit" << endl; 		// debug code
	
	// check reference counter for overflow
	for (int c = 0, C1, C2; c <= DigitAMT ; ++c) {
		C1 = Function_CheckNum(BaseFrom, Count1[c], true);		// run digit through overflow check function
		C2 = Function_CheckNum(BaseFrom, Count1[c], false);		// repeat with different argument to get second output
		
		//cout << C1 << " <C1 " << C2 << " <C2 " << (c+1) << " " << DigitAMT << endl << "Current Count: ";	// debug code
		//if (debug == true) {for (int i = DigitAMT ; i >= 0 ; --i) {cout << Count1[i];}; cout << endl;}; 	// debug code
		
		Count1[c] = C1;								// finalize number after check
		Count1[c+1] = Count1[c+1] + C2;				// add to next digit if overflow is true
		};
		
	//cout << endl; // line break. primarly exists to make debug output easier to read
		
	Count2[0] = Count2[0] + 1; 						// increment main counter
	//cout << "Counter2: " << Count2[0] << endl;	// debug code
	
	// check main counter for overflow
	for (int c = 0, y, C1 ,C2 ; c <= DigitAMT2 ; ++c) {
		if (DigitAMT2 == 0) {y = (BaseTo - 1);}
		C1 = Function_CheckNum(BaseTo, Count2[c], true);	// run digit through overflow check function
		C2 = Function_CheckNum(BaseTo, Count2[c], false);	// repeat with different argument to get second output
		//cout << C1 << " <C1 " << C2 << " <C2 " << (c+1) << " " << DigitAMT2 << endl << "2: Current Count: ";		// debug code
		//if (debug == true) {for (int i = DigitAMT2 ; i >= 0 ; --i) {cout << Count2[i] << ",";}; cout << endl;};	// debug code
		Count2[c] = C1;										// finalize digit after check
		Count2[c+1] = Count2[c+1] + C2; 					// add to next digit if overflow is true
		//if (debug == true) {for (int i = DigitAMT2 ; i >= 0 ; --i) {cout << Count2[i] << ",";}; cout << endl;};	// debug code
		//cout << "y " << y << " DigitAMT2 " << DigitAMT2 << endl;													// debug code 
		if (C2 >= 1) {++y;};								// digit count calculation
		if (y >= BaseTo) {++DigitAMT2; y = 0;};				// digit count calculation
		};
	
	//cout << endl; // line break. primarly exists to make debug code easier to read
	
													// check if reference counter and input are the same
	for (int c = 0, x = 0 ; c <= DigitAMT ; ++c) {
		if (Count1[c] == InputInvers[c]) {++x;};			// check if array entrys match and increment x if they do
		if (x == (DigitAMT+1)) {IsSame = true;};			// send break command if all digits match
		
		//for (int i = DigitAMT ; i >= 0 ; --i) {cout << Input[i] << ",";}; cout << endl;	//debug code
		//for (int i = DigitAMT ; i >= 0 ; --i) {cout << Count1[i] << ",";}; cout << endl;	//debug code
		//cout << x << endl;	//debug code
		};
		
	if (IsSame == true) {break;};							// break counter loop if input and reference counter match
	};
	
	// output code
	cout << "counting complete" << endl << "input: ";						// display text
	for (int i = DigitAMT ; i >= 0 ; --i) {cout << InputInvers[i] << ",";}; // display input
	cout << " Base " << BaseFrom;											// display input base
	cout << endl << "Counted to: ";											// display text
	for (int i = DigitAMT ; i >= 0 ; --i) {cout << Count1[i] << ",";};		// display reference counter (somewhat redundent mainly exists just as an alert just in case the counter makes a mistake)
	cout << endl << "End Result: ";											// display text
	for (int i = DigitAMT2 ; i >= 0 ; --i) {cout << Count2[i] << ",";};		// display converted counter
	cout << " Base: " << BaseTo << endl;									// display output base
	return 0;	// return 0 (i might change this to return output so this code can be used within another program in the future)
}

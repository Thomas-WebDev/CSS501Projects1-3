// --------------------------------------------------Poly.h------------------------------------------------------------
// Kevin Thomas Kehoe CSS502A
// Jan. 7, 0218
// Jan. 13, 0218
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Declaration of the methods to create a ADT for a Polynomial and overloads common operators (+, -, *), 
//          assignment operators (=, *=, +=, -=) and comparison operators (!+, ==) to allow polynomial calculations
// --------------------------------------------------------------------------------------------------------------------
// Notes: Only handles positive exponents 
// --------------------------------------------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

class Poly
{
public:

	Poly(); // Constructor
	// ------------------------------------ReadyToQuit----------------------------------------------------
	// Description: Creates a polynomial with the int being the coefficient and the power as 0
	// ---------------------------------------------------------------------------------------------------
	Poly(int);
	// ------------------------------------ReadyToQuit----------------------------------------------------
	// Description: Creates a polynomial with the first int being the coefficient and the second being 
	//              the exponenet
	// ---------------------------------------------------------------------------------------------------
	Poly(int, int);
	Poly(const Poly&); // Copy constructor
	~Poly(); // Destructor
	// ------------------------------------operator+------------------------------------------------------
	// Description: Overloads the addition operator and returns a Poly object
	// ---------------------------------------------------------------------------------------------------
	Poly operator+ (const Poly&);
	// ------------------------------------operator-------------------------------------------------------
	// Description: Overloads the subtraction operator and returns a Poly object
	// ---------------------------------------------------------------------------------------------------
	Poly operator- (const Poly&);
	// ------------------------------------operator*------------------------------------------------------
	// Description: Overloads the multiplication operator and returns a Poly object
	// ---------------------------------------------------------------------------------------------------
	Poly operator* (const Poly&);
	Poly& operator=(const Poly&); //The assignment operator
	// ------------------------------------operator+=-----------------------------------------------------
	// Description: Overloads the  addition assignment operator and returns a Poly by reference
	// ---------------------------------------------------------------------------------------------------
	Poly& operator+=(const Poly&);
	// ------------------------------------operator-=-----------------------------------------------------
	// Description: Overloads the  subtraction assignment operator and returns a Poly by reference
	// ---------------------------------------------------------------------------------------------------
	Poly& operator-=(const Poly&);
	// ------------------------------------operator*=-----------------------------------------------------
	// Description: Overloads the  multiplication assignment operator and returns a Poly by reference
	// ---------------------------------------------------------------------------------------------------
	Poly& operator*=(const Poly&);
	// ------------------------------------operator==-----------------------------------------------------
	// Description: Returns true if the two polynomials are equal. Else, returns false
	// ---------------------------------------------------------------------------------------------------
	bool operator== (const Poly&);
	// ------------------------------------operator!=-----------------------------------------------------
	// Description: Returns true if the two polynomials are not equal. Else, returns false
	// ---------------------------------------------------------------------------------------------------
	bool operator!= (const Poly&);
	// ------------------------------------getCoeff-------------------------------------------------------
	// Description: Returns the coefficeinet value of the power of the passed int if in range. 
	//              Else returns 0
	// ---------------------------------------------------------------------------------------------------
	int getCoeff(int);
	// ------------------------------------getCoeff-------------------------------------------------------
	// Description: Sets the coefficeinet value (the first int) to the index of the second int which 
	//              represents the power. If it is negative it does nothing, if it is out of range it 
	//              creates a new array of that size and assigns all values to it 
	// ---------------------------------------------------------------------------------------------------
	void setCoeff(int, int);
	// ------------------------------------operator>>-----------------------------------------------------
	// Description: Reads integers and assigns the first to as the coefficient and the second as the 
	//              exponet until it reads two consecutive values of  -1 
	// ---------------------------------------------------------------------------------------------------
	friend istream& operator>>(istream&, Poly&);
	// ------------------------------------operator<<-----------------------------------------------------
	// Description: Outputs a formated polynomial
	// ---------------------------------------------------------------------------------------------------
	friend ostream& operator<<(ostream&, Poly&);

private:

	int size; // stores number of elements in polynomial
	int* polynmial; // stores polynomial equation where the index is the exponent value

};

ostream& operator<<(ostream&, Poly&);
istream& operator>> (istream&, Poly&);
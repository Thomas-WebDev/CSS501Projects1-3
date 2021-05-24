// --------------------------------------------------Poly.cpp-----------------------------------------------------------
// Kevin Thomas Kehoe CSS502A
// Jan. 7, 0218
// Jan. 13, 0218
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Instantiation of the methods to create a ADT for a Polynomial and overloads common operators (+, -, *), 
//          assignment operators (=, *=, +=, -=) and comparison operators (!+, ==) to allow polynomial calculations
// --------------------------------------------------------------------------------------------------------------------
// Notes: Only handles positive exponents 
// --------------------------------------------------------------------------------------------------------------------

#include "poly.h"

using namespace std;

Poly::Poly() {
	polynmial = new int[1];
	polynmial[0] = 0;
	size = 1;
}

Poly::Poly(int coefficient) {
	polynmial = new int[1];
	polynmial[0] = coefficient;
	size = 1;
}

Poly::Poly(int coefficient, int power) {
	polynmial = new int[power + 1];
	size = power + 1;
	for (int i = 0; i < power; i++) {
		polynmial[i] = 0;
	}
	polynmial[power] = coefficient;
}

Poly::Poly(const Poly &original) {
	polynmial = new int[original.size];
	size = original.size;
	for (int i = 0; i < original.size; i++) {
		polynmial[i] = original.polynmial[i];
	}
}

Poly::~Poly() {
	delete [] polynmial;  // Free memory pointed to by polynmial.
	polynmial = NULL;     // Clear polynmial to prevent using invalid memory reference.
}


Poly Poly::operator+ (const Poly& p) {
	int largest = size;
	if (p.size < size) {
		largest = p.size; // Finds largest exponenet
		Poly sum = *this;
		// Cycles through all values of p.polynomial and adds them to sum
		for (int i = 0; i < p.size; i++)
			sum.setCoeff(sum.getCoeff(i) + p.polynmial[i], i);
		return sum;
	}
	Poly sum = p;
	for (int i = 0; i < size; i++)
		sum.setCoeff(sum.getCoeff(i) + polynmial[i], i);
	return sum;
}

Poly Poly::operator-(const Poly &p) {
	int largest = size;
	if (p.size > size)
		largest = p.size; // Finds largest exponenet
	Poly difference(0, largest);
	for (int i = 0; i < size; i++)  // Assigns values of minuen
		difference.setCoeff(polynmial[i], i);
	// Cycles through all values of p.polynomial and subtracts them from difference
	for (int i = 0; i < p.size; i++) {
		if (i < size) // Check if i is still in the range of the polynomial array
			difference.setCoeff(difference.getCoeff(i) - p.polynmial[i], i);
		else
			difference.setCoeff(0 - p.polynmial[i], i);
	}
	return difference;
}

Poly Poly::operator*(const Poly &p) {
	Poly product(0, size + p.size - 2); // Finds largest exponenet
	// Cycles through all values in both polnomials and multiplies them together
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < p.size; j++)
			product.setCoeff(product.getCoeff(i + j) + (polynmial[i] * p.polynmial[j]), i + j);
	}
	return product;
}

Poly & Poly::operator=(const Poly &original) { // Assignment operator
	if (this == &original) // Checks if it is assigning to itself
		return *this;
	delete []polynmial;
	polynmial = new int[original.size];
	size = original.size;
	for (int i = 0; i < original.size; i++)
		polynmial[i] = original.polynmial[i];
	return *this;
}

Poly & Poly::operator+=(const Poly &p) {
	int largest = size;
	if (p.size > size)
		largest = p.size; // Finds largest exponenet
	Poly sum(0, largest);
	// Assigns polynomial to sum
	for (int i = 0; i < size; i++) {
		sum.polynmial[i] = polynmial[i];
	}
	// Adds p.polynomial to sum
	for (int i = 0; i < p.size; i++) {
		sum.polynmial[i] = (sum.polynmial[i] + p.polynmial[i]); // Addition occurs
	}
	// Assigns sum to current object
	delete[] polynmial;
	polynmial = new int[largest];
	size = largest;
	for (int i = 0; i < sum.size; i++)
		polynmial[i] = sum.polynmial[i];
	return *this;
}

Poly & Poly::operator-=(const Poly &p) {
	int largest = size;
	if (p.size > size)
		largest = p.size; // Finds largest exponenet
	Poly difference(0, largest);
	for (int i = 0; i < size; i++)
		difference.setCoeff(polynmial[i], i);
	// Cycles through all values in both polnomials and subtracts one from the other
	for (int i = 0; i < p.size; i++) {
		if (i < size) // Check if i is still in the range of the polynomial array
			difference.setCoeff(polynmial[i] - p.polynmial[i], i);
		else
			difference.setCoeff(0 - p.polynmial[i], i);
	}
	// Assigns difference to current object
	delete[] polynmial;
	polynmial = new int[largest];
	size = largest;
	for (int i = 0; i < difference.size; i++)
		polynmial[i] = difference.polynmial[i];
	return *this;
}

Poly & Poly::operator*=(const Poly &p) {
	int largest = size + p.size - 1;  // Finds largest exponenet and assigns it as size
	Poly product(0, largest);
	// Cycles through all values in both polnomials and multiplies them together
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < p.size; j++)
			product.setCoeff(product.getCoeff(i + j) + (polynmial[i] * p.polynmial[j]), i + j);
	}
	// Assigns product to current object
	delete[] polynmial;
	polynmial = new int[largest];
	size = largest;
	for (int i = 0; i < product.size; i++)
		polynmial[i] = product.polynmial[i];
	return *this;
}

bool Poly::operator==(const Poly &original) {
	if (size != original.size) // Checks if size is the same
		return false;
	for (int i = 0; i < size; i++) { // Compares all values in both arrays
		if (polynmial[i] != original.polynmial[i])
			return false;
	}
	return true;
}

bool Poly::operator!=(const Poly &original) {
	if (size != original.size) // Checks if size is different
		return true;
	for (int i = 0; i < size; i++) { // Compares all values in both arrays
		if (polynmial[i] != original.polynmial[i])
			return true;
	}
	return false;
}

int Poly::getCoeff(int power) {
	if (power > -1 && power < size) // Test if in range
		return polynmial[power];
	return 0; // Returns 0 if not in range
}

void Poly::setCoeff(int coefficient, int power) {
	if (power > -1 && power < size) // Test if in range
		polynmial[power] = coefficient;
	else if (power > size) { // Test if larger than range
		int newSize = power + 1;
		int* newPoly = new int[newSize];
		newPoly[power] = coefficient;
		for (int i = 0; i < power; i++) {
			newPoly[i] = 0;
			if (i < size)
				newPoly[i] = polynmial[i];
		}
		size = newSize;
		delete[] polynmial;
		polynmial = newPoly;
	}
}

ostream & operator<<(ostream &out, Poly &polnom) {
	out << " ";
	for (int x = polnom.size - 1; x > 1; x--) { // Cycles through array
		if (polnom.polynmial[x] != 0) { // Does not display values of 0
			if (polnom.polynmial[x] > 0)
				out << "+" << polnom.polynmial[x] << "x^" << x << " ";
			else
				out << polnom.polynmial[x] << "x^" << x << " ";
		}
	}
	// Formats value of x^1
	if (polnom.polynmial[1] != 0) {
		if (polnom.polynmial[1] > 0)
			out << "+" << polnom.polynmial[1] << "x ";
		else
			out << polnom.polynmial[1] << "x ";
	}
	// Formats value of x^0
	if (polnom.polynmial[0] != 0) {
		if (polnom.polynmial[0] > 0)
			out << "+" << polnom.polynmial[0];
		else
			out << polnom.polynmial[0];
	}
	// Returns 0 if no values is in the array
	if ((polnom.polynmial[0] == 0) && (polnom.size == 1))
		out << "0";
	return out;
}

istream & operator>>(istream &in, Poly &polnom) {
	int coefficient = 0;
	int power = 0;
	bool end = false;
	string temp1 = "";

	while (!end) {
		char temp = in.get();
		if (temp == '-' || isdigit(temp)) { // Get Coefficient
			// Get Coefficient if positive
			if (isdigit(temp)) {
				temp1 = temp;
				temp = in.get();
				while (isdigit(temp)) { // Loops to get all digits
					temp1 += temp;
					temp = in.get();
				}
				coefficient = atoi(temp1.c_str()); // Converts ascii to integer
				temp1.empty();
				char temp = in.get();
				while (!(temp != '-' || !isdigit(temp))) { // Get exponent
					char temp = in.get();
				}
				if (isdigit(temp)) { // Get exponent if positive
					temp1 = temp;
					temp = in.get();
					while (isdigit(temp)) { // Loops to get all digits
						temp1 += temp;
						temp = in.get();
					}
					power = atoi(temp1.c_str()); // Converts ascii to integer
					temp1.empty();
					polnom.setCoeff(coefficient, power);
				}
				if (temp == '-') { // Get exponent if negative
					while (!isdigit(temp))
						temp = in.get();
					temp1 = temp; 
					temp = in.get();
					while (isdigit(temp)) { // Loops to get all digits
						temp1 += temp;
						temp = in.get();
					}
					power = atoi(temp1.c_str()); // Converts ascii to integer
					power = power * -1;
					temp1.empty();
					if (power >= 0) // Check for end values
						polnom.setCoeff(coefficient, power);
				}
			}
			// Get Coefficient if negative
			if (temp == '-') {
				while (!isdigit(temp))
					temp = in.get();
				temp1 = temp;
				temp = in.get();
				while (isdigit(temp)) {
					temp1 += temp;
					temp = in.get();
				}
				coefficient = atoi(temp1.c_str()); // Converts ascii to integer
				coefficient = coefficient * -1;
				temp1.empty();
				char temp = in.get();
				while (!(temp != '-' || !isdigit(temp))) // Get exponent
					char temp = in.get();
				if (isdigit(temp)) { // Get exponent if positive
					temp1 = temp;
					temp = in.get();
					while (isdigit(temp)) { // Loops to get all digits
						temp1 += temp;
						temp = in.get();
					}
					power = atoi(temp1.c_str()); // Converts ascii to integer
					temp1.empty();
					polnom.setCoeff(coefficient, power);
				}
				if (temp == '-') { // Get exponent if negative
					while (!isdigit(temp))
						temp = in.get();
					temp1 = temp;
					temp = in.get();
					while (isdigit(temp)) { // Loops to get all digits
						temp1 += temp;
						temp = in.get();
					}
					power = atoi(temp1.c_str()); // Converts ascii to integer
					power = power * -1;
					temp1.empty();
					if (((power == -1) && (coefficient == -1))) // Check for end values
						end = true;
					else 
						polnom.setCoeff(coefficient, power);
				}
			}
		}
	}
	return in;
}
#include "complex.h"

namespace Ch8 {

	ostream& operator <<(ostream& out, Complex c) {
		double rPart = c.getRealPart();
		double iPart = c.getImaginaryPart();
		out << rPart << "+";
		if (iPart < 0) 
			out << "(" << iPart << ")𝒊";
		else
			out << iPart << "𝒊";
		return out;
	}

	istream& operator >>(istream& in, Complex& c) {
	 	double real = 0, imag = 0;
		in >> real;
		in >> imag;
		c.setRealPart(real);
		c.setImaginaryPart(imag);
		return in;
	}

	bool operator ==(Complex c1, Complex c2) {
		return (c1.getRealPart() == c2.getRealPart() and c1.getImaginaryPart() == c2.getImaginaryPart());
	}

	Complex operator +(Complex c1, Complex c2) {
		double real = c1.getRealPart() + c2.getRealPart();
		double imag = c1.getImaginaryPart() + c2.getImaginaryPart();
		return Complex(real, imag);
	}

	Complex operator -(Complex c1, Complex c2) {
		double real = c1.getRealPart() - c2.getRealPart();
		double imag = c1.getImaginaryPart() - c2.getImaginaryPart();
		return Complex(real, imag);
	}

	Complex operator *(Complex c1, Complex c2) {
		double a = c1.getRealPart(), b = c1.getImaginaryPart();
		double c = c2.getRealPart(), d = c2.getImaginaryPart();
		return Complex(a*c-b*d, a*d+b*c);
	}


};// Ch8

/*
 * 2018203023 박민근
 * Class for complex number
 * */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

namespace Ch8 {

	class Complex {
		private:
			double real;
			double _imaginary;
		public:
			double getRealPart() { return real; }
			double getImaginaryPart() { return _imaginary; }
			void setRealPart(double real) { this->real = real; }
			void setImaginaryPart(double _imaginary) { this->_imaginary = _imaginary; }
			Complex(): real(0), _imaginary(0) {}
			Complex(double r, double i): real(r), _imaginary(i) {}
			Complex(double r): real(r), _imaginary(0) {}
			friend ostream& operator <<(ostream& out, Complex c);
			friend istream& operator >>(istream& in, Complex& c);
			friend bool operator ==(Complex c1, Complex c2);
			friend Complex operator +(Complex c1, Complex c2);
			friend Complex operator -(Complex c1, Complex c2);
			friend Complex operator *(Complex c1, Complex c2);

	};// Complex

};// Ch8

#endif // COMPLEX_H_

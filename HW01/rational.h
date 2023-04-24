/*
 * 2018203023 박민근
 * Class for rational number
 * */

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;

namespace Ch8 {

	class Rational {
		private:
			int numerator; 		// 분자
			int denominator; 	// 분모
		public:
			Rational(int n, int d): numerator(n), denominator(d) {}
			Rational(int wholeNumber): numerator(1), denominator(wholeNumber) {}
			Rational(): numerator(0), denominator(0) {}
			int getNumerator() const { return numerator; }
			int getDenominator() const { return denominator; }
			void setNumerator(int n) { this->numerator = n; }
			void setDenominator(int n) { this->denominator = n; }
			friend ostream& operator <<(ostream& outputStream, Rational n);
			friend istream& operator >>(istream& inputStream, Rational& n);
			friend const bool operator==(Rational n1, Rational n2);
			friend const bool operator<(Rational n1, Rational n2);
			friend const bool operator<=(Rational n1, Rational n2);
			friend const bool operator>(Rational n1, Rational n2);
			friend const bool operator>=(Rational n1, Rational n2);
			friend Rational operator+(Rational n1, Rational n2);
			friend Rational operator-(Rational n1, Rational n2);
			friend Rational operator-(Rational n);
			friend Rational operator*(Rational n1, Rational n2);
	};

	Rational& normalize(Rational& n);
	int lcm(int, int);

}; // Ch8

#endif

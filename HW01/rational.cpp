/*
 * 2018203023 박민근
 *
 * */

#include <cmath>
#include "rational.h"

namespace Ch8 {
			ostream& operator <<(ostream& outputStream, Rational n) {
				outputStream << n.getNumerator() << '/' << n.getDenominator();
				return outputStream;
			}

			istream& operator >>(istream& inputStream, Rational& n) {
				int nominator = 0, denominator = 0;
				inputStream >> nominator;
				inputStream >> denominator;
				n.setNumerator(nominator);
				n.setDenominator(denominator);
				return inputStream;
			}

			const bool operator==(Rational n1, Rational n2) {
				int ad = n1.getNumerator()*n2.getDenominator();
				int bc = n1.getDenominator()*n2.getNumerator();
				return ad == bc;
			}

			const bool operator<(Rational n1, Rational n2) {
				int a = n1.getNumerator(), b = n1.getDenominator();
				int c = n2.getNumerator(), d = n2.getDenominator();
				// b*d > 0
				if(b*d > 0)
					return a*d < b*c;
				// b*d < 0
				else
					return a*d > b*c;
			}

			const bool operator<=(Rational n1, Rational n2) {
				int a = n1.getNumerator(), b = n1.getDenominator();
				int c = n2.getNumerator(), d = n2.getDenominator();
				// b*d > 0
				if(b*d > 0)
					return a*d <= b*c;
				// b*d < 0
				else
					return a*d >= b*c;
			}

			const bool operator>(Rational n1, Rational n2) {
				int a = n1.getNumerator(), b = n1.getDenominator();
				int c = n2.getNumerator(), d = n2.getDenominator();
				// b*d > 0
				if(b*d > 0)
					return a*d > b*c;
				// b*d < 0
				else
					return a*d < b*c;
			}

			const bool operator>=(Rational n1, Rational n2) {
				int a = n1.getNumerator(), b = n1.getDenominator();
				int c = n2.getNumerator(), d = n2.getDenominator();
				// b*d > 0
				if(b*d > 0)
					return a*d >= b*c;
				// b*d < 0
				else
					return a*d <= b*c;
			}

			// 두 자연수 n1, n2의 최소공배수 반환
			int lcm(int n1, int n2) {
				int max = 0;
				max = (n1>n2) ? n1 : n2;
				while (true) {
					if ((max%n1==0) && (max%n2==0))
						break;
					max++;
				}
				return max;
			}

			Rational operator+(Rational n1, Rational n2) {
				// 통분
				int denom = lcm(abs(n1.getDenominator()), abs(n2.getDenominator()));
				int m1 = denom/n1.getDenominator(), m2 = denom/n2.getDenominator();
				int num1 = n1.getNumerator()*m1;
				int num2 = n2.getNumerator()*m2;
				// 사칙연산
				return Rational(num1+num2, denom);
			}

			Rational operator-(Rational n1, Rational n2) {
				// 통분
				int denom = lcm(abs(n1.getDenominator()), abs(n2.getDenominator()));
				int m1 = denom/n1.getDenominator(), m2 = denom/n2.getDenominator();
				int num1 = n1.getNumerator()*m1;
				int num2 = n2.getNumerator()*m2;
				// 사칙연산
				return Rational(num1-num2, denom);
			}

			Rational operator-(Rational n) {
				return Rational(-1*n.getNumerator(), n.getDenominator());
			}

			Rational operator*(Rational n1, Rational n2) {
				int ac = n1.getNumerator()*n2.getDenominator();
				int bd = n1.getDenominator()*n2.getNumerator();
				return Rational(ac, bd);
			}

			Rational& normalize(Rational& n) {
				int nsign = n.getNumerator()/abs(n.getNumerator());
				int dsign = n.getDenominator()/abs(n.getDenominator());
				int numerator = abs(n.getNumerator());
				int denominator = abs(n.getDenominator());
				int gcd = 0;
				for (int i=1; i<=numerator && i<=denominator; i++)
					if (numerator%i==0 and denominator%i==0)
						gcd = i;
				n.setNumerator(nsign*numerator/gcd);
				n.setDenominator(dsign*denominator/gcd);
				return n;
			}
};// Ch8

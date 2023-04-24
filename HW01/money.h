/*
 * 2018203023 박민근
 * Programming Projects in chapter 8 and chapter 9
 * */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
using namespace std;

namespace Ch8 {

	class Money {
		private:
			int dollars, cents;

			int dollarsPart(double amount) const;
			int centsPart(double amount) const;
			int round(double number) const;

		public:
			Money(): dollars(0), cents(0) {}
			Money(double amount)
				: dollars(dollarsPart(amount)), cents(centsPart(amount)) {}
			Money(int theDollars, int theCents): dollars(theDollars), cents(theCents) {}
			Money(int theDollars): dollars(theDollars), cents(0) {}
			double getAmount( ) const { return dollars + cents*0.01; }
			int getDollars( ) const { return dollars; }
			int getCents( ) const { return cents; }
			const Money percent(int percentFigure) const;
			friend const Money operator +(const Money& amount1,
					const Money& amount2);
			friend const Money operator -(const Money& amount1,
					const Money& amount2);
			friend const Money operator ==(const Money& amount1,
					const Money& amount2);
			friend const Money operator -(const Money& amount1);
			friend ostream& operator <<(ostream& outputStream, 
					const Money& amount);
			friend istream& operator >>(istream& inputStream, Money& amount);
			friend const bool operator <(const Money& m1,
					const Money& m2) {
				return m1.getAmount() < m2.getAmount();
			}
			friend const bool operator <=(const Money& m1, 
					const Money& m2) {
				return m1.getAmount() <= m2.getAmount();
			}
			friend const bool operator >(const Money& m1,
					const Money& m2) {
				return m1.getAmount() > m2.getAmount();
			}
			friend const bool operator >=(const Money& m1,
					const Money& m2) {
				return m1.getAmount() >= m2.getAmount();
			}

	};

}; // Ch8

#endif

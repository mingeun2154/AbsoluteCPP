/*
 * 2018203023 박민근
 * Implementation for solution.h
 * */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "money.h"

using namespace std;

namespace Ch8 {

	int Money::dollarsPart(double amount) const {
		return static_cast<int>(amount);
	}

	int Money::centsPart(double amount) const {
		double doubleCents = amount * 100;
		int intCents = (round(fabs(doubleCents))) % 100;
        //% can misbehave on negatives
		if (amount < 0)
			intCents = -intCents;
		return intCents;
	}

	int Money::round(double number) const {
		return static_cast<int>(floor(number + 0.5));
	}

	const Money operator +(const Money& amount1,
		const Money& amount2) {
		int allCents1 = amount1.cents + amount1.dollars*100;
		int allCents2 = amount2.cents + amount2.dollars*100;
		int sumAllCents = allCents1 + allCents2;
		int absAllCents = abs(sumAllCents); //Money can be negative.
		int finalDollars = absAllCents/100;
		int finalCents = absAllCents%100;
		if (sumAllCents < 0)
		{
			finalDollars = -finalDollars;
			finalCents = -finalCents;
		}
		return Money(finalDollars, finalCents);

	}

	const Money operator -(const Money& amount1,
			const Money& amount2) {
		int allCents1 = amount1.cents - amount1.dollars*100;
		int allCents2 = amount2.cents - amount2.dollars*100;
		int sumAllCents = allCents1 - allCents2;
		int absAllCents = abs(sumAllCents); //Money can be negative.
		int finalDollars = absAllCents/100;
		int finalCents = absAllCents%100;
		if (sumAllCents < 0)
		{
			finalDollars = -finalDollars;
			finalCents = -finalCents;
		}
		return Money(finalDollars, finalCents);

	}

	const Money operator ==(const Money& amount1,
			const Money& amount2) {
		if (&amount1 == &amount2)
			return true;
		else {
			return amount1.dollars == amount2.dollars && 
				amount1.cents == amount2.cents;
		}
	}

	const Money operator -(const Money& amount) {
		return Money(-amount.dollars, -amount.cents);
	}

	ostream& operator <<(ostream& outputStream, 
			const Money& amount) {
		int absDollars = abs(amount.dollars);
		int absCents = abs(amount.cents);
		if (amount.dollars < 0 || amount.cents < 0)
			outputStream << "$-";
		else
			outputStream << '$';
		outputStream << absDollars;

		if (absCents >= 10)
			outputStream << '.' << absCents;
		else
			outputStream << '.' << '0' << absCents;
		return outputStream;
	}

	istream& operator >>(istream& inputStream, Money& amount) {
		char dollarSign;
		inputStream >> dollarSign;
		if (dollarSign != '$') {
			cout << "No dollar sign in Money input. \n";
			exit(1);
		}
		double amountAsDouble;
		inputStream >> amountAsDouble;
		amount.dollars = amount.dollarsPart(amountAsDouble);
		amount.cents = amount.centsPart(amountAsDouble);
		return inputStream;
	}

	const Money Money::percent(int percentFigure) const {
		return Money(this->getAmount()*percentFigure/100);
	}

}

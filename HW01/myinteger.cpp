/*
 * 2018203023
 * MyInteger.cpp
 * */

#include <cmath>
#include <cstdlib>
#include "myinteger.h"

namespace Ch8 {

	MyInteger::MyInteger(int n) {
		this->value = n;
		this->digit = digitOf(n);
	}

	int MyInteger::operator[](int index) {
		int p = static_cast<int>(pow(10, index));
		return this->value/p%10;
	}

	int digitOf(int value) {
		int n = 0;
		while (value > 0) {
			value = value / 10;
			n++;
		}
		return n;
	}

};// Ch8

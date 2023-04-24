/*
 * 2018203023
 * PrimeNumber.cpp
 * */

#include <cmath>
#include "primenumber.h"

namespace Ch8 {

	// prefix --
	PrimeNumber& PrimeNumber::operator --() {
		this->number = primeBefore(this->number);
		return *this;
	}

	// prefix ++
	PrimeNumber& PrimeNumber::operator ++() {
		this->number = nextPrime(this->number);
		return *this;
	}

	// postfix --
	PrimeNumber PrimeNumber::operator --(int) {
		PrimeNumber tmp(this->number);
		--(*this);
		return tmp;
	}

	// postfix ++
	PrimeNumber PrimeNumber::operator ++(int) {
		PrimeNumber tmp(this->number);
		++(*this);
		return tmp;
	}

	// n이 소수인지 아닌지 판별
	bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


	// n 다음 소수 반환
	int nextPrime(int n) {
		int prime = n;
		while (!isPrime(++prime)) {}
		return prime;
	}

	// n 이전 소수 반환
	int primeBefore(int n) {
		if (n==2)
			return 2;
		int prime = n;
		while (!isPrime(--prime)) {}
		return prime;
	}

};// Ch8

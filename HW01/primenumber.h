/*
 * 2018203023
 * PrimeNumber.h
 * */

namespace Ch8 {

	class PrimeNumber {

		private:
			int number;
		public:
			PrimeNumber(): number(1) {}
			PrimeNumber(int n): number(n) {}
			int getPrimeNumber() { return this->number; }
			PrimeNumber& operator --(); 	// prefix --
			PrimeNumber& operator ++(); 	// prefix ++
			PrimeNumber operator --(int); 	// postfix -- 
			PrimeNumber operator ++(int); 	// postfix ++

	};// PrimeNumber
	
	bool isPrime(int n);
	int nextPrime(int n);
	int primeBefore(int n);

};// Ch8

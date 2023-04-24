/*
 * 2018203023
 * MyInteger
 * */

namespace Ch8 {

	class MyInteger {
		private:
			int value;
			int digit;
		public:
			MyInteger(): value(0), digit(0) {}
			MyInteger(int n);
			int operator [](int index);

	};// MyInteger
	
	int digitOf(int value);

};// Ch8

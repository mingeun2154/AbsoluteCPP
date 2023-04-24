/*
 * 2018203023 박민근
 * Display 8.7 ++
 * */

#ifndef CHAR_PAIR_H_
#define CHAR_PAIR_H_

#include <iostream>
#include <cstdlib>
using namespace std;

namespace Ch8 {

	class CharPair {
		private:
			char arr[100];
			int size;
		public:
			CharPair();
			CharPair(int sz);
			CharPair(int sz, char in[]);
			int getSize() const { return size; } 
			char& operator[](int index);
			friend ostream& operator<<(ostream& out, CharPair pair);

	};// CharPair

};// Ch8

#endif// CHAR_PAIR_H_

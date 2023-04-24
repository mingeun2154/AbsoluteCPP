/*
 * 2018203023
 * BoxOfProduce.h
 * */

# ifndef BOX_OF_PRODUCE_H_
# define BOX_OF_PRODUCE_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Ch8 {

	class BoxOfProduce {

		private:
			vector<string> items;
		public:
			BoxOfProduce() { }
			BoxOfProduce(string arr[3]);
			string& operator [](int index) { return this->items[index]; }
			friend BoxOfProduce operator +(BoxOfProduce b1, BoxOfProduce b2);
			void output();
			void add(string item);

	};// BoxOfProduce

};// Ch8

#endif// BOX_OF_PRODUCE_H_

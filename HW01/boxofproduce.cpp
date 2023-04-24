/*
 * 2018203023
 * BoxOfProduce.cpp
 * */

#include "boxofproduce.h"

namespace Ch8 {

	BoxOfProduce::BoxOfProduce(string arr[3]) {
		for(int i=0; i<3; i++)
			this->items.push_back(arr[i]);
	}

	void BoxOfProduce::output() {
		int sz = this->items.size();
		for(int i=0; i<sz; i++)
			cout << this->items[i] << ' ';
		cout << endl;
	}

	void BoxOfProduce::add(string item) {
		this->items.push_back(item);
	}
	
	BoxOfProduce operator +(BoxOfProduce b1, BoxOfProduce b2) {
		BoxOfProduce result = BoxOfProduce();
		for(int i=0; i<b1.items.size(); i++) 
			result.items.push_back(b1.items[i]);
		for(int i=0; i<b2.items.size(); i++) 
			result.items.push_back(b2.items[i]);
		return result;
	}

};// Ch8

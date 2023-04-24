#include "charpair.h"

namespace Ch8 {

	CharPair::CharPair() {
		this->size = 10;
		for(int i=0; i<size; i++)
			this->arr[i] = '#';
	}

	CharPair::CharPair(int sz) {
		this->size = sz;
		for(int i=0; i<size; i++)
			this->arr[i] = '#';
	}

	CharPair::CharPair(int sz, char in[]) {
		this->size = sz;
		for(int i=0; i<size; i++)
			this->arr[i] = in[i];
	}

	char& CharPair::operator[](int index) {
		if (index >= this->size or index < 0) {
			cout << "\033[31mIndexError!\033[0m" << endl;
			exit(1);
		}
		return this->arr[index];
	}

	ostream& operator <<(ostream& out, CharPair pair) {
		int sz = pair.size;
		char first = pair.arr[0];
		char last = pair.arr[sz-1];
		out << "size: " << sz;
		out << ", arr[0]: " << first;
		out << ", arr[" << sz-1 << "]: " << last;
		return out;
	}

};// Ch8

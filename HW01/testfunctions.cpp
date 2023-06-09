/*
 * 2018203023
 * test functions
 */

#include "testfunctions.h"
#include "ch9.h"
#include <string>

const char* G = "\033[32;1m";
const char* R = "\033[31;1m";
const char* DEFAULT = "\033[0m";

void successed(const char* msg) { cout << G << msg << DEFAULT <<  endl; }
void failed(const char* msg) { cout << R << msg << DEFAULT << endl ; }
// T는 반드시 << 연산자를 오버로딩 해야한다.
template <typename T>
void successed(T obj) {
	cout << G << obj << DEFAULT << endl;
}
template <typename T>
void failed(T obj) {
	cout << R << obj << DEFAULT << endl;
}

void printTestInfo(int ch, int qNumber, char qChar) {
	printf("[Chapter%d project%d.%c]\n", ch, qNumber, qChar);
}

void printTestInfo(int ch, int qNumber) {
	printf("[Chapter%d project%d]\n", ch, qNumber);
}

namespace Ch8 {

	// Chapter8 Question1.a
	void testCh8Q1a() {
		printTestInfo(8, 1, 'a');
		// <
		printf("%-50s .... ", "Money(100, 1) < Money(100, 2)");
		if(Money(100, 1) < Money(100, 2)) 
			successed("true");
		else
			failed("false");
		// <=
		printf("%-50s .... ", "Money(100, 1) <= Money(100, 2)");
		if(Money(100, 1) <= Money(100, 2)) 
			successed("true");
		else
			failed("false");
		// >
		printf("%-50s .... ", "Money(100, 1) > Money(100, 2)");
		if(Money(100, 1) > Money(100, 2)) 
			failed("true");
		else
			successed("false");
		// >=
		printf("%-50s .... ", "Money(100, 1) >= Money(100, 2)");
		if(Money(100, 1) >= Money(100, 2)) 
			failed("true");
		else
			successed("false");
	}

	// Chapter8 Question1.b
	void testCh8Q1b() {
		printTestInfo(8, 1, 'b');
		printf("%-50s .... ", "Money(100.10).percent(10)");
		if(Money(100.10).percent(10).getAmount() == 10.01) 
			cout << G <<Money(100.10).percent(10).getAmount() << DEFAULT << endl;
		else
			cout << R <<Money(100.10).percent(10).getAmount() << DEFAULT << endl;
	}

	// Chapter8 Question2
	void testCh8Q2() {
		printTestInfo(8, 2);
		// a/b = c/d if a*d = b*c
		printf("%-50s .... ", "Rational(1,4) == Rational(2,8)");
		if(Rational(1, 4) == Rational(2, 8)) 
			successed("true");
		else
			failed("false");
		// a/b < c/d if a*d < b*c and b>0 and d>0
		printf("%-50s .... ", "Rational(-1,3) < Raiontal(-2,9)");
		if(Rational(-1, 3) < Rational(-2, 9)) 
			successed("true");
		else
			failed("false");
		// +
		printf("%-50s .... ", "Rational(-1,3) + Rational(2,9) == Rational(-1, 9)");
		Rational answer1 = Rational(-1, 3) + Rational(2, 9);
		if (answer1 == Rational(-1, 9)) 
			successed(answer1);
		else
			failed(answer1);
		// -
		printf("%-50s .... ", "Rational(-1,3) - Rational(-2,9) == Raiontal(-1,9)");
		Rational answer2 = Rational(-1, 3) - Rational(-2, 9);
		if(answer2 == Rational(-1, 9)) 
			successed(answer2);
		else
			failed(answer2);
		// normalize
		printf("%-50s .... ", "normalize(Rational(-24,256))");
		Rational r(-24, 256);
		int a = normalize(r).getNumerator();
		int b = normalize(r).getDenominator();
		if(a == -3 and b == 32) 
			successed("-3/32");
		else
			failed("false");
	}

	void testCh8Q3() {
		printTestInfo(8, 3);
		// ==
		printf("%-50s .... ", "Complex(1,3) == Complex(1,3)");
		if (Complex(1, 3) == Complex(1, 3)) 
			successed("true");
		else
			failed("false");
		// +
		printf("%-50s .... ", "Complex(-1,3) + Complex(1,-3))");
		Complex answer1 = Complex(-1, 3) + Complex(1, -3);
		if (answer1 == Complex(0)) 
			successed(answer1);
		else
			failed(answer1);
		// -
		printf("%-50s .... ", "Complex(-1,-9) - Complex(1,-3))");
		Complex answer2 = Complex(-1, -9) - Complex(1, -3);
		if (answer2 == Complex(-2, -6)) 
			successed(answer2);
		else
			failed(answer2);
		// *
		printf("%-50s .... ", "Complex(-1,2) * Complex(-1,-2))");
		Complex answer3 = Complex(-1, 2) * Complex(-1, -2);
		if (answer3 == Complex(5)) 
			successed(answer3);
		else
			failed(answer3);
	}

	void testCh8Q4a() {
		printTestInfo(8, 4, 'a');
		printf("%-50s .... ", "CharPair()");
		CharPair answer = CharPair();
		int sz = answer.getSize();
		if (sz == 10 && answer[sz-1] == '#' && answer[0] == '#')
			successed(answer);
		else
			failed(answer);
	}

	void testCh8Q4b() {
		printTestInfo(8, 4, 'b');
		printf("%-50s .... ", "CharPair(23)[3] ");
		char answer = CharPair(23)[3];
		if (answer == '#') 
			successed("#");
		else
			failed("✗");
	}

	void testCh8Q4c() {
		printTestInfo(8, 4, 'c');
		printf("%-50s .... ", "CharPair(99)");
		CharPair answer = CharPair(99);
		int sz = answer.getSize();
		if (sz == 99 && answer[sz-1] == '#' && answer[0] == '#')
			successed(answer);
		else
			failed(answer);
	}

	void testCh8Q4d() {
		printTestInfo(8, 4, 'd');
		printf("%-50s .... ", "CharPair(3, {'a', 'b', 'c'})");
		char a[] = {'a', 'b', 'c'};
		CharPair answer = CharPair(3, a);
		if (answer.getSize() == 3)
			successed(answer);
		else
			failed(answer);
	}

	void testCh8Q5() {
		printTestInfo(8, 5);
		printf("%-50s .... ", "Vector2D(1, -10) * Vector2D(-1, 100)");
		int result = Vector2D(1, -10) * Vector2D(-1, 100);
		if (result == -1001)
			successed(result);
		else
			failed(result);
	}

	void testCh8Q6() {
		printTestInfo(8, 6);
		for(int i=0;i<9;i++) {
			printf("MyInteger(123456789)[%d]                            .... ", i);
			int result = MyInteger(123456789)[i];
			if (result == 9-i)
				successed(result);
			else
				failed(result);
		}
	}

	void testCh8Q7() {
		printTestInfo(8, 7);
		PrimeNumber answer;
		// prefix ++
		printf("%-50s .... ", "++PrimeNumber(7)");
		answer = PrimeNumber(7);
		if ((++answer).getPrimeNumber() == 11)
			successed(answer.getPrimeNumber());
		else
			failed(answer.getPrimeNumber());
		// prefix --
		printf("%-50s .... ", "--PrimeNumber(7)");
		answer = PrimeNumber(7);
		if ((--answer).getPrimeNumber() == 5)
			successed(answer.getPrimeNumber());
		else
			failed(answer.getPrimeNumber());
		// posfix ++
		printf("%-50s .... ", "PrimeNumber(113)++");
		answer = PrimeNumber(113);
		if ((answer++).getPrimeNumber() == 113 && 
				answer.getPrimeNumber() == 127)
			successed((--answer).getPrimeNumber());
		else
			failed((answer).getPrimeNumber());
		// postfix --
		printf("%-50s .... ", "PrimeNumber(7)--");
		answer = PrimeNumber(7);
		if ((answer--).getPrimeNumber() == 7 &&
				(++answer).getPrimeNumber() == 7)
			successed(answer.getPrimeNumber());
		else
			failed(answer.getPrimeNumber());
	}

	void testCh8Q8() {
		printTestInfo(8, 8);
		printf("%-50s .... ", "cout<<Temperature().setTempFahrenheit(77)");
		Temperature temp = Temperature();
		temp.setTempFahrenheit(77);
		if (temp.getTempFahrenheit() == 77)
			successed(temp);
		else
			failed(temp);
	}

	void testCh8Q9() {
		printTestInfo(8, 9);
		string s1[3] = {"Broccoli", "Tomato", "Kiwi"};
		string s2[3] = {"Kale", "Cabbage", "Carrot"};
		BoxOfProduce b1 = BoxOfProduce(s1);
		BoxOfProduce b2 = BoxOfProduce(s2);
		printf("%-50s .... ", "BoxOfProduce b1({\"Broccoli\", \"Tomato\", \"Kiwi\"})");
		b1.output();
		printf("%-50s .... ", "BoxOfProduce b2({\"Kale\", \"Cabbage\", \"Carrot\"})");
		b2.output();
		printf("%-50s .... ", "b1+b2");
		(b1+b2).output();
		printf("%-50s .... ", "(b1+b2).add(\"Lettuce\")");
		BoxOfProduce b3 = b1 + b2;
		b3.add("Lettuce");
		b3.output();
	}

};// Ch8

namespace Ch9 {

	void testCh9Q1() {
		printTestInfo(9, 1);
		cout << "input >> ";
		char input[101];
		cin.getline(input, 101);
		successed(project1(input));
	}

	void testCh9Q2() {
		printTestInfo(9, 2);
		cout << "input >> ";
		string str;
		getline(cin, str);
		project2(str);
	}

	void testCh9Q3() {
		printTestInfo(9, 3);
		cout << "input >> ";
		string str;
		getline(cin, str);
		project3(str);
		cout << endl;
	}

	void testCh9Q4() {
		printTestInfo(9, 4);
		cout << "input >> ";
		string str;
		getline(cin, str);
		project4(str);
		cout << endl;
	}

	void testCh9Q5() {
		printTestInfo(9, 5);
		char input[101];
		while (true) {
			cout << "input (press 'Q' for exit) >> ";
			cin.getline(input, 101);
			if (input[0] == 'Q' && input[1] == '\0')
				break;
			project5(input);
			cout << endl;
		}
	}

	void testCh9Q6() {
		printTestInfo(9, 6);
	}

	void testCh9Q7() {
		printTestInfo(9, 7);
		string input;
		while (true) {
			cout << "input (empty string to quit) >> ";
			getline(cin, input);
			if (input == "")
				break;
			project7(input);
			cout << endl;
		}
	}

	void testCh9Q8() {
		printTestInfo(9, 8);
		string input;
		cout << "input >> ";
		cin >> input;
		project8(input);
	}

	void testCh9Q9() {
		printTestInfo(9, 9);
		// true
		printf("%-24s  %-24s .... ", "\"Hello, world!\"", "\"hello, world!\"");
		const char* t11 = "Hello world!";
		const char* t12 = "hello, world!";
		project9(t11, t12);
		cout << endl;
		// true
		printf("%-24s  %-24s .... ", "\"Hello !\"", "\"hello\"");
		const char* t31 = "Hello !";
		const char* t32 = "hello";
		project9(t31, t32);
		cout << endl;
		// false
		printf("%-24s  %-24s .... ", "\"abcd\"", "\"bcda\"");
		const char* t21 = "abcd";
		const char* t22 = "bcda";
		project9(t21, t22);
		cout << endl;
	}

	void testCh9Q10() {
		printTestInfo(9, 10);
		project10();
	}

	void testCh9Q11() {
		printTestInfo(9, 11);
		printf("%-50s .... ", "\"Eleven plus two.\" \"Twelve plus one!\"");
		string str1 = "Eleven plus two.";
		string str2 = "Twelve plus one!";
		project11(str1, str2);
		printf("\n%-50s .... ", "\"one plus two.\" \"Twelve plus one!\"");
		str1 = "one plus two.";
		str2 = "Twelve plus one!";
		project11(str1, str2);
		cout << endl;
	}

	void testCh9Q12() {
		printTestInfo(9, 12);
		string str;
		cout << "input >> ";
		getline(cin, str);
		project12(str);
	}

	void testCh9Q13() {
		printTestInfo(9, 13);
		string str;
		cout << "input >> ";
		getline(cin, str);
		project13(str);
	}

};// Ch9

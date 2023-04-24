/*
 * 2018203023
 * test functions
 */

#ifndef TEST_FUNCTIONS_H_
#define TEST_FUNCTIONS_H_

#include <iostream>
#include "boxofproduce.h"
#include "money.h"
#include "rational.h"
#include "complex.h"
#include "charpair.h"
#include "vector2d.h"
#include "myinteger.h"
#include "primenumber.h"
#include "temperature.h"
#include "boxofproduce.h"
#include "ch9.h"
using namespace Ch8;
using namespace Ch9;

extern const char* G;
extern const char* R;
extern const char* DEFAULT;

void successed(const char* msg);
void failed(const char* msg);
// T는 반드시 << 연산자를 오버로딩 해야한다.
template <typename T>
void successed(T obj);
template <typename T>
void failed(T obj);

void printTestInfo(int, int, char);
void printTestInfo(int, int);

namespace Ch8 {
	void testCh8Q1a();
	void testCh8Q1b();
	void testCh8Q2();
	void testCh8Q3();
	void testCh8Q4a();
	void testCh8Q4b();
	void testCh8Q4c();
	void testCh8Q4d();
	void testCh8Q5();
	void testCh8Q6();
	void testCh8Q7();
	void testCh8Q8();
	void testCh8Q9();
};// Ch8

namespace Ch9 {
	void testCh9Q1();
	void testCh9Q2a();
	void testCh9Q2b();
	void testCh9Q2c();
	void testCh9Q2d();
	void testCh9Q3();
	void testCh9Q4();
	void testCh9Q5();
	void testCh9Q6a();
	void testCh9Q6b();
	void testCh9Q6c();
	void testCh9Q6d();
	void testCh9Q6e();
	void testCh9Q6f();
	void testCh9Q6g();
	void testCh9Q6h();
	void testCh9Q6i();
	void testCh9Q6j();
	void testCh9Q8a();
	void testCh9Q8b();
	void testCh9Q9();
	void testCh9Q10();
	void testCh9Q11();
	void testCh9Q12();
	void testCh9Q13();
	void testCh9Q14();
}

#endif// TEST_FUNCTIONS_H_

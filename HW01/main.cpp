/*
 * 2018203023
 */

#include "testfunctions.h"
using namespace Ch8;

void greeting();

int main(void) {
	greeting();
	// Chapter8
	testCh8Q1a();
	testCh8Q1b();
	testCh8Q2();
	testCh8Q3();
	testCh8Q4a();
	testCh8Q4b();
	testCh8Q4c();
	testCh8Q4d();
	testCh8Q5();
	testCh8Q6();
	testCh8Q7();
	testCh8Q8();
	testCh8Q9();
	// Chapter9
	// testCh9Q1();
	
	cout << endl;
	return 0;
}

void greeting() {
	cout << "\033[2J" << "\033[H";
	cout << "\033[;1m";
	cout << "  ____ ____  ____    _   ___        _____  _ \n";
    cout << " / ___|  _ \\|  _ \\  | | | \\ \\      / / _ \\/ |\n";
    cout << "| |   | |_) | |_) | | |_| |\\ \\ /\\ / / | | | |\n";
    cout << "| |___|  __/|  __/  |  _  | \\ V  V /| |_| | |\n";
    cout << " \\____|_|   |_|     |_| |_|  \\_/\\_/  \\___/|_|\t";
	cout << "\033[0m";
	cout << "2018203023" << endl << endl;
}
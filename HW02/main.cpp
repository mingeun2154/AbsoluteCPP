/**
 * @file main.cpp
 * @brief 고급프로그래밍 HW02
 * @author 2018203023 박민근
 * @date 2023-06-14
 */

#include <iostream>

#include "salariedemployee.h"

using namespace hw02;
using namespace std;


namespace ANSI_CONTROL {
    const char* DEFAULT = "\033[0m";
    const char* RED = "\033[31m";
    const char* GREEN = "\033[32m";
    const char* BOLD = "\033[;1m";
	const char* CLEAR = "\033[2J\033[H";
} // ANSI_CONTROL


namespace ch14 {
    void project1();
    void project3();
    void project5();
    void project7();
    void project9();
} // ch14


namespace ch15 {
    
} // ch15


void greeting() {
    using namespace ANSI_CONTROL;
    cout << BOLD;
    cout << "   __________  ____     __  ___       ______ ___ \n";
    cout << "  / ____/ __ \\/ __ \\   / / / / |     / / __ \\__ \\\n";
    cout << " / /   / /_/ / /_/ /  / /_/ /| | /| / / / / /_/ /\n";
    cout << "/ /___/ ____/ ____/  / __  / | |/ |/ / /_/ / __/ \n";
    cout << "\\____/_/   /_/      /_/ /_/  |__/|__/\\____/____/ \n";
    cout << DEFAULT << endl;
}


int main() {

    greeting();
    return 0;
}

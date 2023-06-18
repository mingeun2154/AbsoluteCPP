/**
 * @file administrator.h
 * @author 2018203023 박민근
 * @date 2023-06-16
 */

#ifndef _ADMINISTRATOR_H_
#define _ADMINISTRATOR_H_

#include <iostream>
#include <string>
#include "salariedemployee.h"

using namespace std;

namespace hw02 {

    namespace ch14 {

        class Administrator : public SalariedEmployee {
            
            public:
                Administrator() {}
                /**
                 * @param string Title
                 * @param string Area
                 * @param string Immediate supervisor
                 * @param double Annual salary
                 */
                Administrator(string, string, string, double);


                /**
                 * @brief Changes the supervisor name.
                 */
                void setSupervior(const string&);


                /**
                 * @brief Read in an administrator's data from the keyboard.
                 */
                void getFromKeyboard();


                /**
                 * @brief Outputs the object's data to the screen.
                 */
                void print();


                /**
                 * @brief Ovearload the SalariedEmployee::printCheck().
                 */
                void printCheck();

            private:
                string title; // Administrator's title.
                string area; // Company area of responsibility.
                string supervisor; // The name of this administrator's immediate supervisor.
        }; // Administrator
    } // ch14
    
} // hw02

#endif // _ADMINISTRATOR_H_

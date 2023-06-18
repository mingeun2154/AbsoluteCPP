/**
 * @file administrator.cpp
 * @author 2018203023 박민근
 * @date 2023-06-16
 */

#include <iostream>

#include "administrator.h"
#include "salariedemployee.h"

using namespace std;

namespace hw02 {

    namespace ch14 {
        
        /**
         * @param title The administrator's title.
         * @param area The company area of responsibility.
         * @param supervisor The name of this administrator's immediate supervisor.
         * @param salary The administrator's annual salary.
         */
        Administrator::Administrator(string title,
            string area, string supervisor,
            double salary)
        : SalariedEmployee(), title(title), area(area), supervisor(supervisor) {
            this->salary = salary;
        }


        void Administrator::setSupervior(const string& name) {
            this->name = name;
        }


        /**
         * @brief Read in an administrator's data from keyboard.
         */
        void Administrator::getFromKeyboard() {

            cout << "Input administrator's data.\n";
            cout << "name: ";
            cin >> this->name;
            cout << "ssn: ";
            cin >> this->ssn;
            cout << "title: ";
            cin >> this->title;
            cout << "area: ";
            cin >> this->area;
            cout << "annual salary(KRW): ";
            cin >> this->salary;
            cout << "supervisor's name: ";
            cin >> this->supervisor;
        }


        void Administrator::print() {
           cout << "Administrator " << this->name
               << "\'s data\n";
           cout << "name: " << this->name << endl;
           cout << "ssn: " << this->ssn << endl;
           cout << "title: " << this->title << endl;
           cout << "area: " << this->area << endl;
           cout << "annual salary: " << this->salary << endl;
        }


        void Administrator::printCheck() {
            setNetPay(salary);
            cout << "\n__________________________________________________\n";
            cout << "Pay to the order of " << getName( ) << endl;
            cout << "The sum of " << getNetPay( ) << " KRW\n";
            cout << "_________________________________________________\n";
            cout << "Check Stub NOT NEGOTIABLE \n";
            cout << "Employee Number: " << getSsn( ) << endl;
            cout << "Salaried Employee. Regular Pay: "
                 << salary << "￦\n";
            cout << "_________________________________________________\n";
        }
    } // ch14
    
} // hw02

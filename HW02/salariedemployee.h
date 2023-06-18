//This is the header file salariedemployee.h.
//This is the interface for the class SalariedEmployee.
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "employee.h"

using std::string;

namespace hw02 {

    namespace ch14 {

        class SalariedEmployee : public Employee
        {
        public:
            SalariedEmployee( );
            SalariedEmployee (const string&  theName, const string&  theSsn,
                                      double theWeeklySalary);
            double getSalary( ) const;
            void setSalary(double newSalary);
            void printCheck( );
        protected:
            double salary;
        };

    } // ch14
} // hw02

#endif //SALARIEDEMPLOYEE_H

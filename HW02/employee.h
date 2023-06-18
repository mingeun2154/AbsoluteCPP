//This is the header file employee.h.
//This is the interface for the class Employee.
//This is primarily intended to be used as a base class to derive
//classes for different kinds of employees.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

namespace hw02
{
    namespace ch14 {

        class Employee
        {
        public:
            Employee( );
            Employee(const string& theName, const string& theSsn);
            string getName( ) const;
            string getSsn( ) const;
            double getNetPay( ) const;
            void setName(const string& newName);
            void setSsn(const string& newSsn);
            void setNetPay(double newNetPay);
            void printCheck( ) const;
        protected:
            string name;
            string ssn;
            double netPay;
        };
    } // ch14

} // hw02

#endif //EMPLOYEE_H

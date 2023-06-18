/**
 * @file p5Classes.h
 * @author 2018203023 박민근 
 * @date 2023-06-17
 */

#ifndef _P5_CLASSES_
#define _P5_CLASSES_

#include <iostream>
using namespace std;

#include "doctor.h"

namespace hw02 {

    namespace ch14 {

        class Person {

            public:
                Person ( ) { name = "none"; }
                Person (string theName): name(theName) {  }
                Person (const Person& theObject)
                    : name(theObject.getName()) {  }
                string getName ( ) const { return name; }
                Person& operator= (const Person& rtSide) { name = rtSide.getName(); return *this; }
                void setName(const string& name) { this->name = name; }
            private:
                string name;
        };


        class Patient: public Person {
            public:
                Patient(): Person() {}
                Patient(const Patient&);
                Patient(const string& name,
                    const Doctor& doctor)
                : Person(name), primaryPhysician(doctor) {  }
                Doctor getPrimaryPhysician() const { return primaryPhysician; }
                Patient& operator=(const Patient& r);
            private:
                Doctor primaryPhysician;
        }; // Patient


        class Billing {
            public:
                Billing(const Patient& patient,
                    const Doctor& doctor)
                    : patient(patient), doctor(doctor), due(doctor.getFee()) {  }
                Billing(const Billing&);
                Patient getPatient() const { return patient; }
                Doctor getPrimaryPhysician() const { return doctor; }
                double getDue() const{ return due; }
                void printInfo();
            
            private:
                Patient patient;
                Doctor doctor;
                double due;
        }; // Billing

    } // ch14
    
}

#endif

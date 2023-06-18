/**
 * @file doctor.h
 * @brief Chapter14 programming project2
 * @author 2018203023 박민근
 * @date 2023-06-17
 */
#ifndef _DOCTOR_H_
#define _DOCTOR_H_

#include "salariedemployee.h"

namespace hw02 {

    namespace ch14 {

        class Doctor : public SalariedEmployee {
            
            public:
                Doctor(): SalariedEmployee(), specialty("none"), fee(0) {}
                Doctor(const Doctor&);
                Doctor(const string& name,
                    const string& ssn,
                    const string& specialty,
                    double fee)
                    : SalariedEmployee(name, ssn, 0), specialty(specialty), fee(fee) {}
                void setSpecialty(const string& s) { specialty = s; }
                void setFee(double f) { fee = f; }
                string getSpecialty() const { return specialty; }
                double getFee() const { return fee; }

                Doctor& operator =(const Doctor&);
                void printInfo();

            private:
                string specialty;
                double fee;
        }; // Doctor
        
    } // ch14
      //
} // hw02

#endif

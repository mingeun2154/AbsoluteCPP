/**
 * @file ch14Classes.cpp
 * @author 2018203023 박민근
 * @date 2023-06-17
 */

#include <random>

#include "ch14P5Classes.h"
#include "ch14P9Classes.h"

using namespace std;

namespace hw02 {
    
    namespace ch14 {

        /* Doctor */
        // Copy constructor
        Doctor::Doctor(const Doctor& r) {
            // Employee
            name = r.getName();
            ssn = r.getSsn();
            // SalariedEmployee
            salary = r.getSalary();
            // Doctor
            specialty = r.getSpecialty();
            fee = r.getFee();
        }


        /* Overloaded assignment operator */
        Doctor& Doctor::operator =(const Doctor& r) {
            // Employee
            name = r.getName();
            ssn = r.getSsn();
            // SalariedEmployee
            salary = r.getSalary();
            // Doctor
            specialty = r.getSpecialty();
            fee = r.getFee();

            return *this;
        }


        void Doctor::printInfo() {
            cout << "_____Doctor info_____\n";
            cout << "name: " << this->name << endl;
            cout << "ssn: " <<
                this->ssn << endl;
            cout << "specialty: "
                << this->specialty << endl;
            cout << "office visit fee: "
                << this->fee << endl;
            cout << "━━━━━━━━━━━━━━━━━━━━━\n";
        }


        /* Person */


        /* Patient */
        // copy constructor
        Patient::Patient(const Patient& patient) {
            this->setName(patient.getName());
            primaryPhysician = patient.getPrimaryPhysician();
        }

        // Operator overloading
        Patient& Patient::operator =(const Patient& r) {
            this->primaryPhysician = r.getPrimaryPhysician();
            this->setName(r.getName());

            return *this;
        }

        /* Billing */
        // copy constructor
        Billing::Billing(const Billing& bill) {
            this->patient = bill.getPatient();
            this->doctor = bill.getPrimaryPhysician();
            this->due = bill.getDue();
        }

        void Billing::printInfo() {
            cout << "_____Billing info_____\n"
                << "Patient: "
                << patient.getName() << endl
                << "Primary Physician: "
                << doctor.getName() << endl;
            cout << "━━━━━━━━━━━━━━━━━━━━━━\n";
        }


        /**
         * @brief 일정한 확률로 true를 반환한다.
         * @param p 확률(단위: %, included)
         */
        bool Creature::triggeredByProbability(double p) const {
            random_device rd;
            mt19937 gen(rd());
            uniform_real_distribution<> dis(0.0, 1.0);

            if (dis(gen) <= p / 100)
                return true;
            else
                return false;
        }


        int Creature::randomNumber(int limit) const {
            random_device rd;
            mt19937 gen(rd());
            uniform_real_distribution<> dis(0.0, static_cast<double>(limit+1));
            return static_cast<int>(dis(gen));
        }



        /**
         * @brief All creatures inflict damage.
         * which is a random number up to their
         * strength.
         *
         * @return Damage inflicted by the class.
         */
        int Creature::getDamage() const {
            return randomNumber(strength);
        }


        int Human::getDamage() const {
            return Creature::getDamage();
        }


        /**
         * @brief Elves inflict double magical
         * damage with a 10% chance.
         *
         * @return Total damage Elves can inflict.
         */
        int Elf::getDamage() const {
            int damage = Creature::getDamage();
            if (Creature::triggeredByProbability(10.0))
                return 2*damage;
            else
                return damage;
        }


        int Demon::getDamage() const {
            int damage = Creature::getDamage();
            if (Creature::triggeredByProbability(5.0))
                return damage + 5;
            else
                return damage;
        }



        int CyberDemon::getDamage() const {
            return Demon::getDamage();
        }



        /**
         * @brief Balrog들은 두 번 공격한다.
         *
         * @return Balrog이 적에게 입히는 데미지.
         */
        int Balrog::getDamage() const {
            return Demon::getDamage() + Demon::getDamage();
        }
        
    } // ch14

} // hw02

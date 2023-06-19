/**
 * @file testcase.h
 * @brief Programming Project들에 대한 테스트케이스
 * @author 2018203023 박민근
 * @date 2023-06-16
 */

#ifndef _TESTCASE_H_
#define _TESTCASE_H_

#include <iostream>
#include <vector>

// ch14
#include "administrator.h"
#include "doctor.h"
#include "ch14P5Classes.h"
#include "ch14P7Classes.h"
#include "ch14P9Classes.h"

// ch15
#include "figure.h"
#include "ch15P4Classes.h"
#include "ch15P5Classes.h"
#include "ch15P6Classes.h"
#include "ch15P7Classes.h"

using namespace std;

namespace ANSI_CONTROL {
    const char* DEFAULT = "\033[0m";
    const char* RED = "\033[31m";
    const char* GREEN = "\033[32m";
    const char* CYAN = "\033[36m";
    const char* YELLOW = "\033[33m";
    const char* BOLD = "\033[;1m";
	const char* CLEAR = "\033[2J\033[H";
} // ANSI_CONTROL


namespace util {

    void greeting() {
        using namespace ANSI_CONTROL;
        cout << CLEAR;
        cout << BOLD;
        cout << "   __________  ____     __  ___       ______ ___ \n";
        cout << "  / ____/ __ \\/ __ \\   / / / / |     / / __ \\__ \\\n";
        cout << " / /   / /_/ / /_/ /  / /_/ /| | /| / / / / /_/ /\n";
        cout << "/ /___/ ____/ ____/  / __  / | |/ |/ / /_/ / __/ \n";
        cout << "\\____/_/   /_/      /_/ /_/  |__/|__/\\____/____/ \n";
        cout << DEFAULT << endl;
    }


    void failed(string msg) {
        // cout << ANSI_CONTROL::RED << "\t...failed\n" << msg << ANSI_CONTROL::DEFAULT;
        cout << "\t... " << ANSI_CONTROL::RED << "✗\n" <<ANSI_CONTROL::DEFAULT << msg << endl;
    }


    void failed() {
        cout << "\t... " << ANSI_CONTROL::RED << "✗\n" <<ANSI_CONTROL::DEFAULT;
    }


    void successed() {
        cout << "\t... "  << ANSI_CONTROL:: GREEN << "✓\n" << ANSI_CONTROL::DEFAULT;
    }
} // util


namespace  hw02 {
    
    namespace ch14 {

        void project1() {
            cout << ANSI_CONTROL::GREEN
                << "CAPTER14 project01 "
                << ANSI_CONTROL::DEFAULT;
            cout << "SalariedEmployee\n";
            Administrator ad;
            ad.getFromKeyboard();
            ad.print();
            ad.printCheck();
            cout << endl;
        }


        void project3() {
            cout << ANSI_CONTROL::GREEN
                << "CAPTER14 project03 "
                << ANSI_CONTROL::DEFAULT << "Doctor" << endl;
            cout << "Testing overloaded assignment operator ";
            Doctor d1("Charlie", "311",
                "Pediatrician", 100000000);
            Doctor d2 = d1;

            if ( d2.getName() == d1.getName() &&
                d2.getSsn() == d1.getSsn() &&
                d2.getSalary() == d1.getSalary() &&
                d2.getSpecialty() == d1.getSpecialty() &&
                d2.getFee() == d1.getFee() )
                util::successed();
            else
                util::failed();
            
            cout << "Testing copy constructor ";
            Doctor d3(d1);

            if ( d3.getName() == d1.getName() &&
                d3.getSsn() == d1.getSsn() &&
                d3.getSalary() == d1.getSalary() &&
                d3.getSpecialty() == d1.getSpecialty() &&
                d3.getFee() == d1.getFee() )
                util::successed();
            else
                util::failed();
            cout << endl;
        }


        void project5() {
            cout << ANSI_CONTROL::GREEN
                << "CAPTER14 project05 "
                << ANSI_CONTROL::DEFAULT
                << "Patient "
                << "Billing"
                << endl;
            cout << "[Patient] Testing Overloaded assignment operator ";
            Doctor d1("Charlie", "311",
                "Pediatrician", 100000000);
            Patient p1("Dennis", d1);
            Patient assignedP1 = p1;
            if ( p1.getName() == assignedP1.getName() &&
                p1.getPrimaryPhysician().getName() == assignedP1.getPrimaryPhysician().getName())
                util::successed();
            else
                util::failed();

            cout << "[Billing] Testing Overloaded assignment operator ";
            Billing bill1(p1, d1);
            Billing bill2 = bill1;
            if (bill1.getPrimaryPhysician().getName() == bill2.getPrimaryPhysician().getName() &&
                bill1.getDue() == bill2.getDue() &&
                bill1.getPatient().getName() == bill2.getPatient().getName())
                util::successed();
            else
                util::failed();

            cout << "[Patient] Testing Copy constructor ";
            Patient copiedP1(p1);
            if ( p1.getName() == copiedP1.getName() &&
                p1.getPrimaryPhysician().getName() == copiedP1.getPrimaryPhysician().getName())
                util::successed();
            else
                util::failed();


            cout << "[Billing] Testing Copy constructor ";
            Billing copiedBill(bill1);
            if (bill1.getPrimaryPhysician().getName() == copiedBill.getPrimaryPhysician().getName() &&
                bill1.getDue() == copiedBill.getDue() &&
                bill1.getPatient().getName() == copiedBill.getPatient().getName())
                util::successed();
            else
                util::failed();


            Doctor doctor1("Frank", "13579",
                "pediatrics", 15000);
            Billing b1(Patient("Alice", doctor1), doctor1);
            Doctor doctor2("George", "13580",
                "otolaryngologist", 14000);
            Billing b2(Patient("Amy", doctor2), doctor1);
            cout << endl;
            doctor1.printInfo();
            doctor2.printInfo();
            b1.printInfo();
            b2.printInfo();
            cout << " │\n"
                << " ╰➝ TOTAL INCOME: "
                << b1.getDue() + b2.getDue()
                << endl;
            cout << endl;
        }


        bool _ContainsKeyword(const Document& doc, string keyword) {
            if (doc.getText().find(keyword) != string::npos)
                return true;
            return false;
        }

        void project7() {
            cout << ANSI_CONTROL::GREEN
                << "CAPTER14 project07 "
                << ANSI_CONTROL::DEFAULT
                << "Document Email File\n";
            Email email("sender@naver.com",
                "receiver@google.com",
                "Hello Email instance");
            File f("/path/to/file",
                "Hello File instance");

            cout << "[Email] Testing subroutine ";
            if (_ContainsKeyword(static_cast<Document>(email), "Hello") &&
                !_ContainsKeyword(static_cast<Document>(email), "Yellow") )
                util::successed();
            else
                util::failed();
            cout << "[File] Testing subroutine ";
            if (_ContainsKeyword(static_cast<Document>(f), "Hell") &&
                !_ContainsKeyword(static_cast<Document>(f), "insance") )
                util::successed();
            else
                util::failed();
            cout << endl;
        }


        void project9() {
            cout << ANSI_CONTROL::GREEN
                << "CAPTER14 project09 "
                << ANSI_CONTROL::DEFAULT
                << "Fantasy role-playing game\n";

            int str = 100;
            int hp = 500;
            int vsize = 100;

#define DEBUG
            
            Human human(str, hp);           vector<int> hDmg = vector<int>();
            Elf elf(str, hp);               vector<int> eDmg = vector<int>();
            CyberDemon cyberDemon(str, hp); vector<int> cDmg = vector<int>();
            Balrog balrog(str, hp);         vector<int> bDmg = vector<int>();

            bool tf = true;
            // Validation for Human class.
            // 모든 데미지는 str보다 작거나 같아야 한다.
            cout << "[Human] Vadlidating damage ";
            for (int i=0; i<vsize; i++) {
                int dmg = human.getDamage();
                if (dmg > str)
                    tf = false;
                if (dmg > str/2)
                    hDmg.push_back(dmg);
            }
            if (tf)
                util::successed();
            else
                util::failed();

            tf = false;
            // Valication for Elf
            // str보다 큰 데미지가 발생해야 한다.
            cout << "[Elf] Vadlidating damage ";
            for (int i=0; i<vsize; i++) {
                int dmg = elf.getDamage();
                if (dmg > str) {
                    tf = true;
                    eDmg.push_back(dmg);
                }
            }
            if (tf)
                util::successed();
            else
                util::failed();

            // Valication for Balrog
            // str의 두 배 이상의 데미지가 발생해야 한다.
            tf = false;
            cout << "[Balrog] Vadlidating damage ";
            for (int i=0; i<vsize; i++) {
                int dmg = balrog.getDamage();
                if (dmg > 50) {
                    tf = true;
                    bDmg.push_back(dmg);
                }
            }
            if (tf)
                util::successed();
            else
                util::failed();

            // Valication for CyberDemon
            // 5% 확률로 데미지 50 추가
            tf = false;
            cout << "[CyberDemon] Vadlidating damage ";
            for (int i=0; i<vsize; i++) {
                int dmg = cyberDemon.getDamage();
                if (dmg > 50) {
                    tf = true;
                    cDmg.push_back(dmg);
                }
            }
            if (tf)
                util::successed();
            else
                util::failed();
            cout << endl;

#ifdef DEBUG
            using namespace ANSI_CONTROL;
            cout << "Acutal results of getDamage()\n";
            cout << CYAN <<  "Human(strength=100):\n" << DEFAULT;
            for (const auto& d : hDmg)
                cout << d << " ";
            cout << endl;
            cout << CYAN << "Elf(strength=100, 10% 확률로 데미지 2배):\n" << DEFAULT;
            for (const auto& d : eDmg)
                cout << d << " ";
            cout << endl;
            cout << CYAN << "Balrog(strength=100, 두 번 공격):\n" << DEFAULT;
            for (const auto& d : bDmg)
                cout << d << " ";
            cout << endl;
            cout << CYAN << "CyberDemon(strength=100, 5% 확률로 데미지 50 추가):\n" << DEFAULT;
            for (const auto& d : cDmg)
                cout << d << " ";
            cout << endl;
#endif

            cout << endl;
        }
    } // ch14


    namespace ch15 {

        void project1() {
            using namespace p1;
            using namespace ANSI_CONTROL;
            cout << GREEN
                << "CAPTER15 project01\n"
                << DEFAULT;
            
            cout << YELLOW << "Base class "
                << CYAN << "Derived class \n"
                << DEFAULT;

            Figure* triangle = new Triangle();
            Figure* rectangle =new Rectangle();

            cout << "Figure* triangle = new Triangle();\n"
                << "Figure* rectangle = new Rectangle();\n";

            cout << "triangle->" << CYAN << "vDraw()" << DEFAULT << " ➠  ";
            triangle->vDraw();
            cout << "triangle->" << YELLOW << "draw()" << DEFAULT << " ➠  ";
            triangle->draw();

            cout << "rectangle->" << CYAN << "vDraw()" << DEFAULT << " ➠  ";
            rectangle->vDraw();
            cout << "rectangle->" << YELLOW << "draw()" << DEFAULT << " ➠  ";
            rectangle->draw();

            cout << "\nvirtual function 호출 ➠ 실제 클래스의 함수가 호출된다.\n"
                << "non-virtual function 호출 ➠ base class의 함수가 호출된다.\n"
                << RED
                << "🚨 virtual function은 동적으로 결정되기 때문에 동적으로 생성된 인스턴스에 대해서만 유효하다.\n" << DEFAULT;

            cout << endl;
        }


        void project2() {
            using namespace ANSI_CONTROL;
            cout << GREEN
                << "CAPTER15 project02 "
                << DEFAULT
                << "draw()\n";

            p2::Rectangle(5, 2).draw();
            p2::Rectangle(3, 3).draw();

            p2::Triangle().draw();
            p2::Triangle(3, 4).draw();
            // p2::Triangle(9, 3).draw();

            cout << endl;
        }
        

        void project4() {
            cout << ANSI_CONTROL::GREEN
                << "CAPTER15 project04 "
                << ANSI_CONTROL::DEFAULT
                << "Fantasy role-playing game "
                << ANSI_CONTROL::CYAN << "virtual getDamage() ver.\n"
                << ANSI_CONTROL::DEFAULT;

            int str = 100;
            int hp = 500;
            int vsize = 100;

#define DEBUG
            
            Human human(str, hp);           vector<int> hDmg = vector<int>();
            Elf elf(str, hp);               vector<int> eDmg = vector<int>();
            CyberDemon cyberDemon(str, hp); vector<int> cDmg = vector<int>();
            Balrog balrog(str, hp);         vector<int> bDmg = vector<int>();

            bool tf = true;
            // Validation for Human class.
            // 모든 데미지는 str보다 작거나 같아야 한다.
            cout << "[Human] Vadlidating damage ";
            for (int i=0; i<vsize; i++) {
                int dmg = human.getDamage();
                if (dmg > str)
                    tf = false;
                if (dmg > str/2)
                    hDmg.push_back(dmg);
            }
            if (tf)
                util::successed();
            else
                util::failed();

            tf = false;
            // Valication for Elf
            // str보다 큰 데미지가 발생해야 한다.
            cout << "[Elf] Vadlidating damage ";
            for (int i=0; i<vsize; i++) {
                int dmg = elf.getDamage();
                if (dmg > str) {
                    tf = true;
                    eDmg.push_back(dmg);
                }
            }
            if (tf)
                util::successed();
            else
                util::failed();

            // Valication for Balrog
            // str의 두 배 이상의 데미지가 발생해야 한다.
            tf = false;
            cout << "[Balrog] Vadlidating damage ";
            for (int i=0; i<vsize; i++) {
                int dmg = balrog.getDamage();
                if (dmg > 50) {
                    tf = true;
                    bDmg.push_back(dmg);
                }
            }
            if (tf)
                util::successed();
            else
                util::failed();

            // Valication for CyberDemon
            // 5% 확률로 데미지 50 추가
            tf = false;
            cout << "[CyberDemon] Vadlidating damage ";
            for (int i=0; i<vsize; i++) {
                int dmg = cyberDemon.getDamage();
                if (dmg > 50) {
                    tf = true;
                    cDmg.push_back(dmg);
                }
            }
            if (tf)
                util::successed();
            else
                util::failed();
            cout << endl;

#ifdef DEBUG
            using namespace ANSI_CONTROL;
            cout << "Acutal results of getDamage()\n";
            cout << CYAN <<  "Human(strength=100):\n" << DEFAULT;
            for (const auto& d : hDmg)
                cout << d << " ";
            cout << endl;
            cout << CYAN << "Elf(strength=100, 10% 확률로 데미지 2배):\n" << DEFAULT;
            for (const auto& d : eDmg)
                cout << d << " ";
            cout << endl;
            cout << CYAN << "Balrog(strength=100, 두 번 공격):\n" << DEFAULT;
            for (const auto& d : bDmg)
                cout << d << " ";
            cout << endl;
            cout << CYAN << "CyberDemon(strength=100, 5% 확률로 데미지 50 추가):\n" << DEFAULT;
            for (const auto& d : cDmg)
                cout << d << " ";
            cout << endl;
#endif

            cout << endl;
        }


        void project5() {
            cout << ANSI_CONTROL::GREEN
                << "CAPTER15 project05 "
                << ANSI_CONTROL::DEFAULT << "guessing game" << endl;

            p5::Player* human = new p5::HumanPlayer();
            p5::Player* computer = new p5::ComputerPlayer();
            p5::play(*human, *computer);
            
        }


        void project6() {
            cout << ANSI_CONTROL::GREEN
                << "CAPTER15 project06 "
                << ANSI_CONTROL::DEFAULT << "guessing game"
                << ANSI_CONTROL::GREEN
                << " revising ver. " << ANSI_CONTROL::DEFAULT
                << endl;

            p6::Player* human = new p6::HumanPlayer();
            p6::Player* computer = new p6::ComputerPlayer();
            p6::play(*human, *computer);
            
        }


        void project7() {
            cout << ANSI_CONTROL::GREEN
                << "CAPTER15 project07 "
                << ANSI_CONTROL::DEFAULT << "Dice"
                << endl;

            Dice dice1 = Dice(3);
            Dice dice2 = Dice(6);

            cout << "Verifying rollTwoDice function";
            for (int i=0; i<10; i++)
                if (rollTwoDice(dice1, dice2) > 9)
                    util::failed();
            util::successed();

            Dice* dice3 = new LoadedDice(99);
            Dice* dice4 = new LoadedDice(10);
            cout << "Polymorphism check \n";
            cout << "\t└─ 1 Dice and 1 LoadedDice object ";
            rollTwoDice(dice1, *dice4);
            cout << endl;
            cout << "\t└─ 2 LoadedDice objects ";
            rollTwoDice(*dice3, *dice4);
            cout << endl;
        }
    } // ch15

} // hw02


#endif // _TESTCASE_H_

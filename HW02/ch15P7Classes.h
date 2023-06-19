/**
 * @file ch15P7Classes.h
 * @brief Chapter15 project7
 * @author 2018203023 박민근
 * @date 2023-06-19
 */

#ifndef _CH15_P7_CLASSES_H_
#define _CH15_P7_CLASSES_H_

#include <cstdlib>
#include <time.h>
#include <iostream>

namespace hw02 {

    namespace ch15 {

        class Dice {
            public:
                Dice(): numSides(6) { srand(time(NULL)); }
                Dice(int numSides): numSides(numSides) { srand(time(NULL)); }
                virtual int rollDice() const { return (rand()%numSides) + 1; }
            protected:
                int numSides;
        }; // Dice


        class LoadedDice: public Dice {
            public:
                LoadedDice(): Dice() {  }
                LoadedDice(int n): Dice(n) {  }
                int rollDice() const override {
                    std::cout << "\t...\033[32m ✓\033[0m";
                    if (rand()%2)
                        return numSides;
                    else
                        return Dice::rollDice();
                }
        }; // LoadedDice

        int rollTwoDice(const Dice& d1, const Dice& d2) {
            return d1.rollDice() + d2.rollDice();
        }

    } // ch15
    
} // hw02

#endif // _CH15_P7_CLASSES_H_

/**
 * @file ch15P6Classes.h
 * @brief Chapter15 project6
 * @author 2018203023 박민근
 * @date 2023-06-19
 */

#ifndef _CH15_P6_CLASSES_H_
#define _CH15_P6_CLASSES_H_

#include "ch15P5Classes.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

namespace hw02 {

    namespace ch15 {

        namespace p6 {

            class Player {
                public:
                    virtual int getGuess() const { return 0; }
                    virtual void setLowerBound(int n) = 0;
                    virtual void setUpperBound(int n) = 0;
            }; // Player

            
            class HumanPlayer: public Player {
                public:
                    int getGuess() const override;
                    void setLowerBound(int n) override {  }
                    void setUpperBound(int n) override {  }
            }; // HumanPlayer
            

            class ComputerPlayer: public Player {
                public:
                    ComputerPlayer(  )
                        : lowerBound(0), upperBound(100) {  }
                    int getGuess() const override;
                    void setLowerBound(int n) override { lowerBound = n; }
                    void setUpperBound(int n) override { upperBound = n; }

                private:
                    int lowerBound;
                    int upperBound;
            }; // ComputerPlayer

            void play (Player &player1, Player &player2);
        } // p5

    } // ch15

} // hw02

#endif // _CH15_P5_CLASSES_H_

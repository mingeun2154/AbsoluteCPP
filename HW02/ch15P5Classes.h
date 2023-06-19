/**
 * @file ch15P5Classes.h
 * @brief Chapter15 project5
 * @author 2018203023 박민근
 * @date 2023-06-19
 */

#ifndef _CH15_P5_CLASSES_H_
#define _CH15_P5_CLASSES_H_

#include <iostream>
#include <stdlib.h>

using namespace std;

namespace hw02 {

    namespace ch15 {

        namespace p5 {

            int getRandomNumber(int limit);

            class Player {
                public:
                    virtual int getGuess() const { return 0; }
            }; // Player


            class HumanPlayer: public Player {
                public:
                    int getGuess() const override;
            }; // HumanPlayer


            class ComputerPlayer: public Player {
                public:
                    int getGuess() const override;
            }; // ComputerPlayer


            bool checkForWin (int guess, int answer);
            void play (Player &player1, Player &player2);
        } // p5

    } // ch15

} // hw02

#endif // _CH15_P5_CLASSES_H_

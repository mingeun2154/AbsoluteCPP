/**
 * @file ch15Classes.cpp
 * @author 2018203023 박민근 
 * @date 2023-06-18
 */

#include <random>

#include "figure.h"
#include "ch15P4Classes.h"
#include "ch15P5Classes.h"


void hw02::ch15::p2::Rectangle::draw() {
    cout << "Rectangle( width = " << _width
        << " height = " << _height << " )\n";

    int x_pixels = _height * ANSI_CONTROL::X_UNIT;
    int y_pixels = _width * ANSI_CONTROL::Y_UNIT;

    // 사각형의 왼쪽 위 꼭짓점의 위치
    int x_offset = 1;
    int y_offset = 6;

    for (int i=0; i<x_offset+x_pixels; i++) {
        if (i < x_offset)
            cout << endl;
        // 가장 윗부분, 가장 아랫부분
        else if ( (i == x_offset) || (i == x_offset+x_pixels-1) ) {
            for (int j=0; j<y_offset; j++)
                cout << " ";
            for (int j=0; j<y_pixels; j++)
                cout << "*";
            cout << endl;
        }
        else {
            for (int j=0; j<y_offset; j++)
                cout << " ";
            for (int j=0; j<y_pixels; j++) {
                if ( (j == 0) || (j == y_pixels-1) )
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }

    cout << endl;
}


void hw02::ch15::p2::Triangle::draw() {
    cout << "Triangle( width = " << _width
        << " height = " << _height << " )\n";

    int x_pixels = _height * ANSI_CONTROL::X_UNIT;
    int y_pixels = _width * ANSI_CONTROL::Y_UNIT;

    // 삼각형을 포함하는 사각형의 왼쪽 위 꼭짓점의 위치
    int x_offset = 1;
    int y_offset = 12;
    int inside = 0;
    int inside_increment = (y_pixels-1)/(x_pixels) ? (y_pixels-1)/(x_pixels) : 1;


    const int BUFFER_X_LENGTH = x_offset+x_pixels;
    const int BUFFER_Y_LENGTH = y_offset+y_pixels+1;

    for (int x=0; x<BUFFER_X_LENGTH; x++) {
        if (x < x_offset)
            cout << endl;
        // 맨 위 꼭짓점
        else if (x==x_offset) {
            // y_offset
            for (int y=0; y<y_offset; y++)
                cout << " ";
            cout << "*\n";
        }
        // 아랫변
        else if (x==BUFFER_X_LENGTH-1) {
            // y_offset
            for (int y=0; y<y_offset; y++)
                cout << " ";
            for (int y=0; y<inside+3; y++)
                cout << "*";
            cout << endl;
        }
        // 중간 부분
        else {
            inside += inside_increment;
            // y_offset
            for (int y=0; y<y_offset; y++)
                cout << " ";
            cout << "*";
            for (int y=0; y<inside; y++)
                cout << " ";
            cout << "*\n";
        }
    }

    cout << endl;
}


int hw02::ch15::Creature::randomNumber(int limit) const {
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
int hw02::ch15::Creature::getDamage() const {
    return randomNumber(strength);
}


int hw02::ch15::Human::getDamage() const {
    return Creature::getDamage();
}


/**
 * @brief 일정한 확률로 true를 반환한다.
 * @param p 확률(단위: %, included)
 */
bool hw02::ch15::Creature::triggeredByProbability(double p) const {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    if (dis(gen) <= p / 100)
        return true;
    else
        return false;
}


/**
 * @brief Elves inflict double magical
 * damage with a 10% chance.
 *
 * @return Total damage Elves can inflict.
 */
int hw02::ch15::Elf::getDamage() const {
    int damage = Creature::getDamage();
    if (Creature::triggeredByProbability(10.0))
        return 2*damage;
    else
        return damage;
}


int hw02::ch15::Demon::getDamage() const {
    int damage = Creature::getDamage();
    if (Creature::triggeredByProbability(5.0))
        return damage + 5;
    else
        return damage;
}



int hw02::ch15::CyberDemon::getDamage() const {
    return Demon::getDamage();
}



/**
 * @brief Balrog들은 두 번 공격한다.
 *
 * @return Balrog이 적에게 입히는 데미지.
 */
int hw02::ch15::Balrog::getDamage() const {
    return Demon::getDamage() + Demon::getDamage();
}


int hw02::ch15::p5::ComputerPlayer::getGuess() const {
    return getRandomNumber(100);
}



int hw02::ch15::p5::HumanPlayer::getGuess() const {
    int input;
    cin >> input;
    return input;
}


int hw02::ch15::p5::getRandomNumber(int limit) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, static_cast<double>(limit+1));
    return static_cast<int>(dis(gen));
}



bool hw02::ch15::p5::checkForWin (int guess, int answer) {
    if (answer == guess) {
        cout << "You're right! You win!" << endl;
        return true;
    }
    else if (answer < guess)
        cout << "Your guess is too high." << endl;
    else
        cout << "Your guess is too low." << endl;
    return false;
}


void hw02::ch15::p5::play (Player &player1, Player &player2) {
    int answer = 0, guess = 0;
    answer = rand ( ) % 100;
    bool win = false;
    using namespace ANSI_CONTROL;
    while (!win) {
        cout << CYAN
            << "Player 1's turn to guess ➠ ";
        guess = player1.getGuess ( );
        cout << DEFAULT;
        win = checkForWin (guess, answer);
        if (win) return;

        guess = player2.getGuess ( );
        cout << YELLOW
            << "Player 2's turn to guess ➠ "
            << guess << DEFAULT << endl;
        win = checkForWin (guess, answer);
    }
}

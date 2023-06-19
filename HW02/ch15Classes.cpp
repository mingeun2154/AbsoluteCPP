/**
 * @file ch15Classes.cpp
 * @author 2018203023 박민근 
 * @date 2023-06-18
 */
#include <unistd.h>

#include "figure.h"

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

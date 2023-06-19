/**
 * @file figure.h 
 * @brief CHAPTER15 programming project에 사용된 클래스에 대한 구현
 * @author 2018203023 박민근
 * @date 2023-06-18
 */
#ifndef _FIGURE_
#define _FIGURE_

#define X 0
#define Y 1

#include <iostream>

using namespace std;

namespace ANSI_CONTROL {
    extern const char* DEFAULT;
    extern const char* RED;
    extern const char* GREEN;
    extern const char* CYAN;
    extern const char* YELLOW;
    extern const char* CLEAR;

    constexpr int X_UNIT = 2; // 세로 길이 1 = X_UNIT칸
    constexpr int Y_UNIT = 4; // 가로 길이 1 = Y_UNIT칸
} // ANSI_CONTROL

namespace hw02 {

    namespace ch15 {

        using namespace ANSI_CONTROL;

        namespace p1 {

            class Figure {
                public:
                    virtual void vErase() = 0;
                    virtual void vDraw() = 0; 
                    virtual void vCenter() = 0;

                    void erase() { cout << YELLOW << "Figure::erase()\n" << DEFAULT; }
                    void draw() { cout << YELLOW << "Figure::draw()\n" << DEFAULT; }
                    void center() {
                        erase(); draw();
                        cout << YELLOW << "Figure::center()\n" << DEFAULT ;
                    }
            }; // Figure
            

            class Rectangle: public Figure {
                public:
                    Rectangle(  ): width(0), height(0), _center{0, 0} {  }
                    Rectangle(int w, int h, int x, int y)
                        : width(w), height(h), _center{x, y} {  }
                    virtual void vErase() { cout << CYAN << "Rectangle::vErase()\n" << DEFAULT; }
                    virtual void vDraw() { cout << CYAN << "Rectangle::vDraw()\n" << DEFAULT; }
                    virtual void vCenter() {
                        vErase(); vDraw();
                        cout << CYAN << "Rectangle::vCenter()\n" << DEFAULT;
                    }
                    void erase() { cout << CYAN << "Rectangle::erase()\n" << DEFAULT; }
                    void draw() { cout << CYAN << "Rectangle::draw()\n" << DEFAULT; }
                    void center() {
                        erase(); draw();
                        cout << CYAN << "Rectangle::center()\n" << DEFAULT ;
                    }
                private:
                    int width;
                    int height;
                    int _center[2];
            }; // Rectangle
            

            class Triangle: public Figure {
                public:
                    Triangle(  ): _center{0, 0}, width(1), height(1) {  }
                    Triangle(int x, int y, int w, int h): _center{x, y}, width(w), height(h) {  }
                    virtual void vErase() { cout << CYAN << "Triangle::vErase()\n" << DEFAULT; }
                    virtual void vDraw() { cout << CYAN << "Triangle::vDraw()\n" << DEFAULT; }
                    virtual void vCenter() {
                        vErase(); vDraw();
                        cout << CYAN << "Triangle::vCenter()\n" << DEFAULT;
                    }
                    void erase() { cout << CYAN << "Triangle::erase()\n" << DEFAULT; }
                    void draw() { cout << CYAN << "Triangle::draw()\n" << DEFAULT; }
                    void center() {
                        erase(); draw();
                        cout << CYAN << "Triangle::center()\n" << DEFAULT ;
                    }
                private:
                    int _center[2];
                    int width;
                    int height;
            }; // Triangle
        } // p1


        namespace p2 {

            class Figure {
                public:
                    void erase() { cout << CLEAR; }
                    virtual void draw() = 0; 
                    // virtual void center() = 0;
            }; // Figure
            

            class Rectangle: public Figure {
                public:
                    Rectangle(  )
                        : _width(1), _height(1),
                        _center{0, 0} {  }
                    
                    /**
                     * @param w 가로
                     * @param h 세로
                     */
                    Rectangle( int w, int h )
                        : _width(w), _height(h) {  }
                    Rectangle(int w, int h,
                        int x, int y)
                        : _width(w), _height(h),
                        _center{x, y} {  }
                    void draw() override;
                private:
                    int _width;
                    int _height;
                    int _center[2];
            }; // Rectangle
            

            class Triangle: public Figure {
                public:
                    Triangle( )
                        : _center{0, 0},
                        _width(2), _height(1) {  }

                    /**
                     * @param w 가로
                     * @param h 높이
                     */
                    Triangle(int w, int h)
                        : _width(w), _height(h) {  }
                    Triangle(int x, int y,
                        int w, int h)
                        : _center{x, y},
                        _width(w), _height(h) {  }
                    void draw() override;
                private:
                    int _center[2];
                    int _width;
                    int _height;
            }; // Triangle

        } // p1

    } // ch15
    
} // hw02

#endif

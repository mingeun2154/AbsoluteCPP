/*
 * 2018203023 박민근
 * Vector2D
 * */

#ifndef VECTOR_2D_H_
#define VECTOR_2D_H_

namespace Ch8 {

	class Vector2D {

		private:
			int x;
			int y;
		public:
			Vector2D(): x(0), y(0) {}
			Vector2D(int x, int y): x(x), y(y) {}
			int getX() { return x; }
			int getY() { return y; }
			void setX(int x) { this->x = x; }
			void setY(int y) { this->y = y; }
			friend int operator *(Vector2D v1, Vector2D v2) { return v1.getX()*v2.getX() + v1.getY()*v2.getY(); }

	};// Vector2D

};// Ch8

#endif// VECTOR_2D_H_

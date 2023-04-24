/*
 * 2018203023
 * Temperature.h
 * */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include <iostream>
using namespace std;

namespace Ch8 {

	class Temperature {

		private:
			double degree;  		// Kelvin
		public:
			Temperature(): degree(0.0) {}
			void setTempKelvin(double x) { this->degree = x; }
			void setTempFahrenheit(double x);
			void setTempCelcius(double x);
			double getTempKelvin() { return degree; }
			double getTempFahrenheit();
			double getTempCelcius();
			friend ostream& operator <<(ostream& out, Temperature temp);
			friend istream& operator >>(istream& in, Temperature& temp);
			friend bool operator ==(Temperature t1, Temperature t2);
	};// Temperature
	
	double celciusToKelvin(double c);
	double fahrenheitToCelcius(double f);
	double kelvinToCelcius(double k);
	double celciusToFahrenheit(double c);

};// Ch8

#endif// TEMPERATURE_H_

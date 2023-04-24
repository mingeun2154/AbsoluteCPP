/*
 * 2018203023
 * Temperature.cpp
 * */

#include "temperature.h"

namespace Ch8 {

	double celciusToKelvin(double c) {
		return c + 273.15;
	}

	double fahrenheitToCelcius(double f) {
		return (5.0/9) * (f-32);
	}

	double kelvinToCelcius(double k) {
		return k - 273.15;
	}

	double celciusToFahrenheit(double c) {
		return c*9/5+32;
	}

	void Temperature::setTempFahrenheit(double x) {
		this->degree = celciusToKelvin(fahrenheitToCelcius(x));
	}

	void Temperature::setTempCelcius(double x) {
		this->degree = celciusToKelvin(x);
	}

	double Temperature::getTempFahrenheit() {
		return celciusToFahrenheit(kelvinToCelcius(this->degree));
	}

	double Temperature::getTempCelcius() {
		return kelvinToCelcius(this->degree);
	}

	ostream& operator <<(ostream& out, Temperature temp) {
		out << celciusToFahrenheit(kelvinToCelcius(temp.getTempKelvin())) << "℉ " ;
		return out;
	}

	istream& operator >>(istream& in, Temperature& temp) {
		double f;
		in >> f;
		temp.setTempFahrenheit(f);
		return in;
	}

	bool operator ==(Temperature t1, Temperature t2) {
		return t1.getTempKelvin() == t2.getTempKelvin();
	}


};// Ch8

#pragma once

#include <QString>

class ActivationFunction
{
public:
	virtual double calculate(double in) = 0;
	//производная выраженная через значения функции
	virtual double calculateDir(double in) = 0;
};

class ExpSigmoidal
{
public:
	double calculate(double in);
	double calculateDir(double in);
private:
	static double const alpha=0.7;
};

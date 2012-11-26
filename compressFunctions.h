#pragma once

class ExpSigmoidal
{
public:
	double calculate(double in);
	double calculateDir(double in);
private:
	static double const alpha=0.7;
};

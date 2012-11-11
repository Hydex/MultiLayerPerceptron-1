#include <math.h>
#include <QDebug>
#include "compressFunctions.h"

double ExpSigmoidal::calculate(double in)
{
	return 1 / ( 1 + exp(-2 * alpha * in));
}

double ExpSigmoidal::calculateDir(double in)
{
	return -2 * alpha * in * (1 - in);
}

#pragma once

#include <QtXml>
#include <QVector>
#include "compressFunctions.h"

class TNeuron
{
public:
<<<<<<< HEAD
	TNeuron(const int countOfSynWeights);
	TNeuron(const QDomElement &neuron);
	double getResult(const QVector<double> &input, ExpSigmoidal &activationFunction );
	//обучение методом обратного распространения ошибки (backpropagation)
	QVector<double> learn(double dj, const QVector<double> &input);
=======
    TNeuron(const int countOfSynWeights);
	TNeuron(const QDomElement &neuron);
	void addWeight(const double newWeight, const int position);
	void addWeight(const double newWeight);
	void setWeights(const QVector<double> &newWeights);
    double getResult(const QVector<double> &input, ExpSigmoidal &activationFunction );
	//обучение методом обратного распространения ошибки (backpropagation)
    QVector<double> learn(double dj, const QVector<double> &input);
>>>>>>> origin/master

	QDomElement save(QDomDocument &mlp, int neuronNumber);

private:
	QVector<double> mSynapticWeights;
	double mDetectivity;    //пороговая чувствительность нейрона
	static const double nn = 0.01;  //0 < n < 1 множитель, задающий скорость обучения
};

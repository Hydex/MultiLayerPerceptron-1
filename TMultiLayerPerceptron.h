#pragma once

#include <QString>
#include <QList>
#include <QtXml>
#include "TNeuron.h"
#include "TNeuronLayer.h"

class TMultiLayerPerceptron
{

public:

	TMultiLayerPerceptron(const int numOfLayers, const int dim[], const int dimOfInput);
	TMultiLayerPerceptron(const QString &xmlfile);
	QVector<double> recognize(const QVector<double> &input);
	void learn(const QVector<double> &expectedResult);
	bool save(const QString &xmlFile);

private:
	QList<TNeuronLayer> mLayers;
	//выход всей сети
	QVector<double> mNetworkOut;
	QVector<double> mNetworkInput;
};

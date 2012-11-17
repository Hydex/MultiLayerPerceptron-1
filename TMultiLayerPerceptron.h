#pragma once

#include <QString>
#include <QList>
#include <QtXml>
#include "TNeuron.h"
#include "TNeuronLayer.h"

class TMultiLayerPerceptron
{
private:
	QList<TNeuronLayer> mLayers;
	//выход всей сети
	QVector<double> mNetworkOut;
    QVector<double> mNetworkInput;
public:
	TMultiLayerPerceptron(int numOfLayers, int dim[], int dimOfInput);
	TMultiLayerPerceptron(const QString &xmlfile);
	QVector<double> recognize(const QVector<double> &input);
	void learn(const QVector<double> &expectedResult);
	bool save(const QString &xmlFile);

};

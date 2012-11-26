#include "TNeuron.h"
#include "compressFunctions.h"

TNeuron::TNeuron(int countOfSynWeights)
{
    //double tmp = 1.0 / (100 + countOfSynWeights * countOfSynWeights);
    for (int i = 0; i < countOfSynWeights; i++) {
        mSynapticWeights << ((qrand()%100+1) - 50) / 10.0;
	}
    mDetectivity = ((qrand()%100+1) - 50) / 10.0;
	Q_ASSERT(mSynapticWeights.size() == countOfSynWeights);
}

TNeuron::TNeuron(const QDomElement &neuron)
{
	QDomElement weight = neuron.firstChild().toElement();
    while (!weight.isNull()) {
        if(weight.tagName() == "detectivity") {
            double newDetectivity = weight.attribute("value").toDouble();
            mDetectivity = newDetectivity;
        }
        else if (weight.tagName() == "weight") {
            double newWeight = weight.attribute("value").toDouble();
            mSynapticWeights << newWeight;
        }
        else Q_ASSERT(false);
		weight = weight.nextSibling().toElement();
	}
	Q_ASSERT(mSynapticWeights.size() == neuron.attribute("countOfWeights").toDouble());
}

double TNeuron::getResult(const QVector<double> &input
						  , ExpSigmoidal &activationFunction)
{
    Q_ASSERT(input.size() == mSynapticWeights.size());
	double sum = 0;
    for (int i = 0; i < input.size(); i++) {
		sum += input.at(i) * mSynapticWeights.at(i);
	}
    sum += mDetectivity;
	double out = activationFunction.calculate(sum);
	Q_ASSERT(out >= -1 && out <= 1);
	return out;
}

// обучение методом обратного распространения ошибки: веса корректируются в соответствии с входными данными
// и оценкой ошибки dj для конкретного нейрона
QVector<double> TNeuron::learn(double dj, const QVector<double> &input)
{
	QVector<double> correction;
    Q_ASSERT(input.size() == mSynapticWeights.size());
    for (int i = 0; i < input.size(); i++) {
		mSynapticWeights[i] += -dj * nn * input.at(i);
		correction << mSynapticWeights.at(i) * dj;
	}
    mDetectivity += -dj * nn * 1;
    correction << mDetectivity * dj;
	return correction;
}

QDomElement TNeuron::save(QDomDocument &mlp, int neuronNumber)
{
	QDomElement neuron = mlp.createElement("neuron");
	neuron.setAttribute("neuronNumber", neuronNumber);
	neuron.setAttribute("countOfWeights", mSynapticWeights.size());

    QDomElement detectivity = mlp.createElement("detectivity");
    detectivity.setAttribute("value", mDetectivity);
    neuron.appendChild(detectivity);
    for (int i = 0; i < mSynapticWeights.size(); i++) {
		QDomElement weight = mlp.createElement("weight");
		weight.setAttribute("number", i+1);
		weight.setAttribute("value", mSynapticWeights.at(i));
		neuron.appendChild(weight);
	}
	return neuron;
}

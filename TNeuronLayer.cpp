#include "TNeuronLayer.h"


TNeuronLayer::TNeuronLayer(ExpSigmoidal &activationFunction
						   , int dimOfInput
						   , int dimOfLayer)
	: mActivationFunction(activationFunction)
{
	for(int i = 0; i < dimOfLayer; i++) {
		TNeuron newNeuron(dimOfInput);
		mNeurons << newNeuron;
	}
}

TNeuronLayer::TNeuronLayer(const QDomElement &layer)
{
	//пока не придумал как сохранять функцию
	ExpSigmoidal activationFunction;
	mActivationFunction = activationFunction;

	QDomElement neuron = layer.firstChild().toElement();
	while(!neuron.isNull()) {
		if(neuron.tagName() == "neuron") {
			TNeuron newNeuron(neuron);
			mNeurons << newNeuron;
			neuron = neuron.nextSibling().toElement();
		}
	}
	Q_ASSERT(mNeurons.size() == layer.attribute("countOfNeurons").toDouble());
}

void TNeuronLayer::addNeuron(const TNeuron &neuron)
{
	mNeurons << neuron;
}

const int TNeuronLayer::getDimension() const
{
	return mNeurons.size();
}

QVector<double> TNeuronLayer::getResult(const QVector<double> &input)
{
	mLayerOut.clear();
	for(int i = 0; i < mNeurons.size(); i++)
	{
		mLayerOut << mNeurons[i].getResult(input, mActivationFunction);
	}
	return mLayerOut;
}

void TNeuronLayer::setActivationFunction(ExpSigmoidal &newActivationFunction)
{
	mActivationFunction = newActivationFunction;
}


QVector<double> TNeuronLayer::showResult() const
{
	return mLayerOut;
}

QVector<double> TNeuronLayer::learn(QVector<double> &correction, const QVector<double> &input)
{
	//поправок должно быть столько же, сколько нейронов в обучаемом слое
	Q_ASSERT(correction.size() == mNeurons.size());
	for(int i = 0; i < correction.size(); i++) {
		correction[i] *= mActivationFunction.calculateDir(mLayerOut.at(i));
	}
	QVector<double> correctVector;
	for(int i = 0; i < input.size(); i++) {
		correctVector << 0;
	}
	//поправка весов всего слоя(обучение)
	for(int i=0; i < mNeurons.size(); i++)
	{
		QVector<double> tmp = mNeurons[i].learn(correction.at(i), input);
		for(int j = 0; j < correctVector.size(); j++) {
			correctVector[j] += tmp.at(j);
		}
	}
	//возврат поправок для предыдущего слоя
	//qDebug()<<correctVector;
	return correctVector;
}


QDomElement TNeuronLayer::save(QDomDocument &mlp, int layerNumber)
{
	QDomElement layer = mlp.createElement("neuronLayer");
	layer.setAttribute("countOfNeurons", mNeurons.size());
	layer.setAttribute("layerNumber", layerNumber);
	for(int i = 0; i < mNeurons.size(); i++) {
		layer.appendChild(mNeurons[i].save(mlp, i + 1));
	}
	return layer;
}

#include "TMultiLayerPerceptron.h"

TMultiLayerPerceptron::TMultiLayerPerceptron(int numOfLayers
											 , int dim[]
											 , int dimOfInput)
{
	ExpSigmoidal activationFunction;
	TNeuronLayer firstLayer(activationFunction, dimOfInput, dim[0]);
	mLayers << firstLayer;
    for (int i = 1; i < numOfLayers; i++) {
		TNeuronLayer newLayer(activationFunction, mLayers.at(i-1).getDimension(), dim[i]);
		mLayers << newLayer;
	}
}

TMultiLayerPerceptron::TMultiLayerPerceptron(const QString &xmlfile)
{
	QDomDocument loadingMLP;
	QFile mlpIn(xmlfile);
    if (mlpIn.open(QIODevice::ReadOnly)) {
        if (loadingMLP.setContent(&mlpIn)) {
			QDomElement network =
					loadingMLP.documentElement().firstChildElement("neuronLayer");
            while (!network.isNull()) {
                if (network.tagName() == "neuronLayer") {
					TNeuronLayer  newLayer(network);
					mLayers << newLayer;
					network = network.nextSiblingElement("neuronLayer");
				}
			}
		}
	}
    mlpIn.close();
}

QVector<double> TMultiLayerPerceptron::recognize(const QVector<double> &input)
{
	mNetworkInput = input;
	QVector<double> tmp = input;
    for (int i = 0; i < mLayers.size(); i++) {
		tmp = mLayers[i].getResult(tmp);
	}
	mNetworkOut=tmp;
	return mNetworkOut;
}

void TMultiLayerPerceptron::learn(const QVector<double> &expectedResult)
{
	Q_ASSERT(expectedResult.size() == mNetworkOut.size());
	QVector<double> correction;
    for (int i = 0; i < expectedResult.size(); i++) {
		correction << expectedResult.at(i) - mNetworkOut.at(i);
	}
    for (int i = mLayers.size()-1; i > 0; i--) {
		correction = mLayers[i].learn(correction, mLayers[i-1].showResult());
	}
	mLayers[0].learn(correction, mNetworkInput);
}

bool TMultiLayerPerceptron::save(const QString &xmlFile)
{
	QDomDocument mlp("MultiLayerPerceptron");
	QDomElement network = mlp.createElement("MultiLayerPerceptron");
	network.setAttribute("countOfLayers", mLayers.size());
	mlp.appendChild(network);
    for (int i = 0; i < mLayers.size(); i++) {
		network.appendChild(mLayers[i].save(mlp, i+1));
	}
	QFile saveMLP(xmlFile);
    if (saveMLP.open(QIODevice::WriteOnly)) {
		QTextStream(&saveMLP) << mlp.toString();
		saveMLP.close();
	}
	else{
		return true;
	}
	return false;
}


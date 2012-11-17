#include "compressFunctions.h"
#include "TMultiLayerPerceptron.h"
#include <QDebug>
#include <math.h>
QVector<double> chek(const QVector<double> &point, double r)
{
	QVector<double> res;
	double sum = 0;
	for(int i = 0; i < point.size(); i++) {
		sum += point.at(i) * point.at(i);
	}
	res << (sum <= r * r);
	//res << !(x * x + y * y + z * z <= r * r);
	return res;
}

QList<QVector<double> > sampleGen()
{
	QVector<double> point, ans;
	QList<QVector<double> > sample;
	double r = 2;
	point << 0 << 0 << 0 << 0 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 1 << 0 << 0 << 0 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 1 << 0 << 0 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 1 << 0 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 0 << 1 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 0 << 0 << 1 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 0 << 0 << 0 << 1;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 1 << 1 << 1 << 1 << 1 << 1;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 0 << 0 << 1 << 1;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 0 << 1 << 1 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 1 << 1 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 1 << 1 << 0 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 1 << 1 << 0 << 0 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 1 << 0 << 1 << 0 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 1 << 0 << 1 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 1 << 0 << 1 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 0 << 1 << 0 << 1;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 1 << 0 << 0 << 1;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 1 << 0 << 0 << 1 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 1 << 0 << 0 << 1 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 1 << 0 << 0 << 0 << 1 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 1 << 0 << 0 << 0 << 1;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 1 << 0 << 0 << 0 << 0 << 1;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 1 << 1 << 1 << 0 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 1 << 1 << 1 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 1 << 1 << 1 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 0 << 1 << 1 << 1;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0.3 << 0.2 << 0.1 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0.1 << 0 << 0 << 0.4 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0.65 << 0 << 0 << 0.21 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0.2 << 0 << 0.3 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 2 << 1 << 3 << 0 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 0 << 0 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 0 << 0 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 0 << 0 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 0 << 0 << 0 << 0 << 0;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	point << 0 << 1 << 1 << 1 << 1 << 2;
	ans = chek(point, r);
	sample << point << ans;
	point.clear();

	return sample;
}

int main()
{
	int dim[]={6, 6, 1};
	TMultiLayerPerceptron mlp(3, dim, 6);
	QVector<double> point, tmp;
	QList<QVector<double> > sample = sampleGen();
	double a1 = 0, b1 = 0, c1 = 0, r = 2, a11 = 0, b11 = 0, c11 = 0;
	for(int i = 0; i < 1000; i++) {
		for(int j = 0; j < sample.size(); j += 2) {
			tmp = mlp.recognize(sample.at(j));
			mlp.learn(sample.at(j+1));
		}
		qDebug() << "------------------------------------";
		qDebug() << "----------------" << i << "-------------------";
		point.clear();
		point << 0.1 << -0.1 << 0.3 << 0 << 0 << 0;
		qDebug() << point << endl;
		double a = mlp.recognize(point)[0] - chek(point, r)[0];
		if((a1 > a && -a1 < -a) || (a1 < a && -a1 > -a)) {
			qDebug() << a << " down";
			a11++;
		}
		else qDebug() << a << " up";
		a1 = a;

		point.clear();
		qDebug() << "------------------------------------";
		point << 0 << 1 << 1 << 1 << 0 << 0;
		qDebug() << point << endl;
		double b = mlp.recognize(point)[0] - chek(point, r)[0];

		if((b1 > b && b > 0) || ((b1 < b && b < 0))) {
			qDebug() << b << " down";
			b11++;
		}
		else qDebug() << b << " up";
		b1 = b;

		point.clear();
		qDebug() << "------------------------------------";
		point << 0 << 0 << 0 << 0 << 0 << 0;
		qDebug() << point << endl;
		double c = mlp.recognize(point)[0] - chek(point, r)[0];
		if((c1 > c && c > 0) || ((c1 < c && c < 0))) {
			qDebug() << c << " down";
			c11++;
		}
		else qDebug() << c << " up";
		c1 = c;
		point.clear();
	}
	qDebug() << "a" << a11;
	qDebug() << "b" << b11;
	qDebug() << "c" << c11;

	mlp.save("mlp.xml");
//	TMultiLayerPerceptron mlp("mlp.xml");
//	QVector<double> a;
//	a << 12 << 6546 << 0;
//	qDebug() << a << endl << mlp.recognize(a);
	return 0;
}

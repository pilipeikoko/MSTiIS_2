#include "MatrixConverter.h"

double MatrixConverter::getElementC(int i, int j)
{
	totalCounter += 12;
	elementCCounter++;

	sumCounter += 2;
	multiplicationCounter += 7;
	diffirenceCounter += 3;

	return conjunctionOfF(i, j) * (3 * G[i][j] - 2) * G[i][j] + (disjunctionOfD(i, j) +
		(4 * multiplyConjuctionOfFAndDisjunctionOfD(i, j) - 3 * disjunctionOfD(i, j)) * G[i][j]) * (1 - G[i][j]);
}

double MatrixConverter::getElementF(int i, int j, int k)
{
	totalCounter += 12;
	elementFCounter++;

	multiplicationCounter += 7;
	diffirenceCounter += 3;
	sumCounter += 2;

	totalParallelCounter += (time_of_sum + time_of_comparing + time_of_difference)*3;

	return aPointB(i, j, k) * (2 * E[0][k] - 1) * E[0][k] +
		bPointA(i, j, k) * (1 + (4 * aPointB(i, j, k) - 2) * E[0][k]) * (1 - E[0][k]);
}

double MatrixConverter::conjunctionOfF(int i, int j)
{
	conjunctionOfFCounter++;
	double result = 1.0;
	for (int k = 0; k < B.size(); k++) {
		multiplicationCounter++;
		totalCounter++;
		result *= getElementF(i, j, k);
	}

	metodParallelCounter += time_of_multiplicity * B.size();
	metodParallelCounter += (7 * time_of_multiplicity + 2 * time_of_sum + 3 * time_of_difference) * B.size();

	return result;
}

double MatrixConverter::disjunctionOfD(int i, int j)
{
	disjunctionOfDCounter++;
	double result = 1.0;
	for (int k = 0; k < B.size(); k++) {
		totalCounter += 2;
		multiplicationCounter++;
		diffirenceCounter++;
		result *= 1 - aConjunctionB(i, j, k);
	}
	metodParallelCounter += (time_of_multiplicity+time_of_difference) * B.size();
	metodParallelCounter += (time_of_sum + time_of_comparing + time_of_difference) * B.size();
	return 1 - result;
}

double MatrixConverter::multiplyConjuctionOfFAndDisjunctionOfD(int i, int j)
{
	totalCounter++;
	multiplyConjuctionOfFAndDisjunctionOfDCounter++;
	multiplicationCounter++;

	metodParallelCounter += time_of_multiplicity;

	return conjunctionOfF(i, j) * disjunctionOfD(i, j);
}

double MatrixConverter::aPointB(int i, int j, int k)
{
	totalCounter += 3;
	aPointBCounter++;
	sumCounter++;
	diffirenceCounter++;
	comparingCounter++;
	double result = 1 - A[i][k] + B[k][j];

	return result < 1 ? result : 1;
}

double MatrixConverter::bPointA(int i, int j, int k)
{
	totalCounter += 3;
	bPointACounter++;
	sumCounter++;
	diffirenceCounter++;
	comparingCounter++;
	double result = 1 - B[k][j] + A[i][k];


	return result < 1 ? result : 1;
}

double MatrixConverter::aConjunctionB(int i, int j, int k)
{
	aConjunctionBCounter++;
	sumCounter++;
	diffirenceCounter++;
	comparingCounter++;
	totalCounter += 3;

	double result = A[i][k] + B[k][j] - 1;

	return result > 0 ? result : 0;
}

void MatrixConverter::generateInputMatrixes()
{
	srand(time(NULL));
	for (size_t i = 0; i < p; i++) {
		A.push_back({});
		for (size_t j = 0; j < m; j++) {
			A[i].push_back((double)rand() * (2) / RAND_MAX - 1);
		}
	}
	for (size_t i = 0; i < m; i++) {
		B.push_back({});
		for (size_t j = 0; j < q; j++) {
			B[i].push_back((double)rand() * (2) / RAND_MAX - 1);
		}
	}
	for (size_t i = 0; i < 1; i++) {
		E.push_back({});
		for (size_t j = 0; j < m; j++) {
			E[i].push_back((double)rand() * (2) / RAND_MAX - 1);
		}
	}
	for (size_t i = 0; i < p; i++) {
		G.push_back({});
		for (size_t j = 0; j < q; j++) {
			G[i].push_back((double)rand() * (2) / RAND_MAX - 1);
		}
	}
}

void MatrixConverter::createC()
{
	for (int i = 0; i < p; i++) {
		C.push_back({});
		for (int j = 0; j < q; j++) {
			C[i].push_back(getElementC(i, j));
		}
	}
	totalParallelCounter += metodParallelCounter / n;
	totalParallelCounter += (7 * time_of_multiplicity + 2 * time_of_sum + 3 * time_of_difference) * ceil(p * q / n);
}

void MatrixConverter::printC()const
{
	cout << " C:" << endl;
	for (int i = 0; i < C.size(); i++) {
		for (int j = 0; j < C[i].size(); j++) {
			cout << setw(14) << C[i][j];
		}
		cout << endl;
	}
}

MatrixConverter::MatrixConverter(size_t p, size_t m, size_t q, int n)
{
	this->p = p;
	this->m = m;
	this->q = q;
	this->n = n;
	totalCounter = 0;
	generateInputMatrixes();
	createC();
}

void MatrixConverter::printInputMatrixes()const
{
	cout << " A:" << endl;
	for (size_t i = 0; i < A.size(); i++) {
		for (size_t j = 0; j < A[i].size(); j++) {
			cout << setw(14) << A[i][j];
		}
		cout << endl;
	}
	cout << " B:" << endl;
	for (size_t i = 0; i < B.size(); i++) {
		for (size_t j = 0; j < B[i].size(); j++) {
			cout << setw(14) << B[i][j];
		}
		cout << endl;
	}
	cout << " E:" << endl;
	for (size_t i = 0; i < E.size(); i++) {
		for (size_t j = 0; j < E[i].size(); j++) {
			cout << setw(14) << E[i][j];
		}
		cout << endl;
	}
	cout << " G:" << endl;
	for (size_t i = 0; i < G.size(); i++) {
		for (size_t j = 0; j < G[i].size(); j++) {
			cout << setw(14) << G[i][j];
		}
		cout << endl;
	}
}

int MatrixConverter::getSequentialTime()const
{
	return totalCounter;
}

int MatrixConverter::getParallelTime() const
{
	return totalParallelCounter;
	int tn = totalCounter;
	tn = n >= p * q * m ? tn / (p * q * m) : tn / n;
	return tn;
}

double MatrixConverter::getEffectivity() const
{
	return getCoefficientOfAcceleration() / n;
}

double MatrixConverter::getCoefficientOfAcceleration() const
{
	return getSequentialTime() / (double) getParallelTime();
}

int MatrixConverter::getAPointBCounter()
{
	return aPointBCounter;
}

int MatrixConverter::getBPointACounter()
{
	return bPointACounter;
}

int MatrixConverter::getConjunctionOfFCounter()
{
	return conjunctionOfFCounter;
}

int MatrixConverter::getDisjunctionOfDCounter()
{
	return disjunctionOfDCounter;
}

int MatrixConverter::getAConjunctionBCounter()
{
	return aConjunctionBCounter;
}

int MatrixConverter::getMultiplyConjuctionOfFAndDisjunctionOfDCounter()
{
	return multiplyConjuctionOfFAndDisjunctionOfDCounter;
}

int MatrixConverter::getElementCCounter()
{
	return elementCCounter;
}

int MatrixConverter::getElementFCounter()
{
	return elementFCounter;
}

int MatrixConverter::getLavg()
{
	double Lavg = 0.0;

	Lavg += (7 * time_of_multiplicity + 2 * time_of_sum + 3 * time_of_difference) * p * q;
	Lavg += (7 * time_of_multiplicity + 2 * time_of_sum + 3 * time_of_difference) * p * m * q;
	Lavg += (time_of_multiplicity * (m - 1) + time_of_difference * (m + 1)) * getDisjunctionOfDCounter();
	Lavg += (time_of_multiplicity * (m - 1)) * getConjunctionOfFCounter();
	Lavg += (time_of_comparing + time_of_difference + time_of_sum) * getAConjunctionBCounter();
	Lavg += (time_of_comparing + time_of_difference + time_of_sum) * getAPointBCounter();
	Lavg += (time_of_comparing + time_of_difference + time_of_sum) * getBPointACounter();
	Lavg += time_of_multiplicity * getMultiplyConjuctionOfFAndDisjunctionOfDCounter();
	Lavg /= (p * m * q);
	return Lavg;
}

int MatrixConverter::getD()
{
	return getSumLenthOfProgram() / getLavg();
}



int MatrixConverter::getSumCounter()
{
	return sumCounter;
}

int MatrixConverter::getDiffirenceCounter()
{
	return diffirenceCounter;
}

int MatrixConverter::getMultiplicationCounter()
{
	return multiplicationCounter;
}

int MatrixConverter::getComparingCounter()
{
	return comparingCounter;
}

int MatrixConverter::getSumLenthOfProgram() const
{
	return totalCounter;
}


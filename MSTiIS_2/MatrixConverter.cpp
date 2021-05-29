#include "MatrixConverter.h"

double MatrixConverter::getElementC(int i, int j)
{
	counter += 12;
	return conjunctionOfF(i, j) * (3 * G[i][j] - 2) * G[i][j] + (disjunctionOfD(i, j) +
		(4 * multiplyConjuctionOfFAndDisjunctionOfD(i, j) - 3 * disjunctionOfD(i, j)) * G[i][j]) * (1 - G[i][j]);
}

double MatrixConverter::getElementF(int i, int j, int k)
{
	counter += 12;
	return aPointB(i, j, k) * (2 * E[0][k] - 1) * E[0][k] +
		bPointA(i, j, k) * (1 + (4 * aPointB(i, j, k) - 2) * E[0][k]) * (1 - E[0][k]);
}

double MatrixConverter::conjunctionOfF(int i, int j)
{
	double result = 1.0;
	for (int k = 0; k < B.size(); k++) {
		counter++;
		result *= getElementF(i, j, k);
	}
	return result;
}

double MatrixConverter::disjunctionOfD(int i, int j)
{
	double result = 1.0;
	for (int k = 0; k < B.size(); k++) {
		counter += 2;

		result *= 1 - aConjunctionB(i, j, k);
	}
	counter++;
	return 1 - result;
}

double MatrixConverter::multiplyConjuctionOfFAndDisjunctionOfD(int i, int j)
{
	counter++;
	return conjunctionOfF(i, j) * disjunctionOfD(i, j);
}

double MatrixConverter::aPointB(int i, int j, int k) 
{
	counter += 3;
	double result = 1 - A[i][k] + B[k][j];
	// does it make sence?
	return result < 1 ? result : 1;
}

double MatrixConverter::bPointA(int i, int j, int k)
{
	double result = 1 - B[k][j] + A[i][k];
	counter += 3;
	return result < 1 ? result : 1;
}

double MatrixConverter::aConjunctionB(int i, int j, int k)
{
	double result = A[i][k] + B[k][j] - 1;
	counter += 3;
	return result > 1 ? result : 1;
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
	counter = 0;
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

int MatrixConverter::getCounter()const
{
	return counter;
}

int MatrixConverter::getParallelTime() const
{
	int tn = counter;
	tn = n >= p * q * m ? tn / (p * q * m) : tn / n;
	return tn;
}

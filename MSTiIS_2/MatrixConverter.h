#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <time.h>
#include <iomanip>

using namespace std;

class MatrixConverter {
private:
	vector<vector<double>> A;			// pxm
	vector<vector<double>> B;			// mxq
	vector<vector<double>> E;			// 1xm
	vector<vector<double>> G;			// pxq

	vector<vector<double>> C;

	size_t p;
	size_t m;
	size_t q;

	int n;
	int counter;

	double getElementF(int i, int j, int k);
	double getElementC(int i, int j);

	double conjunctionOfF(int i, int j);
	double disjunctionOfD(int i, int j);

	double aPointB(int i, int j, int k);
	double bPointA(int i, int j, int k);

	double aConjunctionB(int i, int j, int k);

	double multiplyConjuctionOfFAndDisjunctionOfD(int i, int j);

	void createC();

	void generateInputMatrixes();

public:
	MatrixConverter(size_t p, size_t m, size_t q, int n);

	void printInputMatrixes() const;
	void printC() const;

	int getCounter() const;
	int getParallelTime() const;

};

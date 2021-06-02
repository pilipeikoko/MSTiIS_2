#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <time.h>
#include <iomanip>

using namespace std;

class MatrixConverter {
private:
	vector<vector<double>> A;// pxm
	vector<vector<double>> B;// mxq
	vector<vector<double>> E;// 1xm
	vector<vector<double>> G;// pxq

	vector<vector<double>> C;

	size_t p;
	size_t m;
	size_t q;

	int n;
	int totalCounter;
	int totalParallelCounter = 0;
	int metodParallelCounter = 0;

	int sumCounter = 0;
	int diffirenceCounter = 0;
	int multiplicationCounter = 0;
	int comparingCounter = 0;

	int aPointBCounter = 0;
	int bPointACounter = 0;

	int conjunctionOfFCounter = 0;
	int disjunctionOfDCounter = 0;

	int aConjunctionBCounter = 0;
	int multiplyConjuctionOfFAndDisjunctionOfDCounter = 0;

	int elementCCounter = 0;
	int elementFCounter = 0;

	int time_of_sum = 1;
	int time_of_difference = 1;
	int time_of_multiplicity = 1;
	int time_of_comparing = 1;



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

	int getSequentialTime() const;
	int getParallelTime() const;
	int getSumLenthOfProgram() const;
	double getEffectivity() const;
	double getCoefficientOfAcceleration() const;

	int getSumCounter();
	int getDiffirenceCounter();
	int getMultiplicationCounter();
	int getComparingCounter();

	int getAPointBCounter();
	int getBPointACounter();

	int getConjunctionOfFCounter();
	int getDisjunctionOfDCounter();
	
	int getAConjunctionBCounter();
	int getMultiplyConjuctionOfFAndDisjunctionOfDCounter();

	int getElementCCounter();
	int getElementFCounter();

	int getLavg();
	int getD();

};

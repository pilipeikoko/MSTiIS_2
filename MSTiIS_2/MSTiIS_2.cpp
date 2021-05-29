//// Лабораторная работа 2 по дисциплине МРЗвИС
//// Выполнена студентом группы 921701
//// БГУИР Пилипейко Валентин Игоревич
//// 15.05.2021
////
//
//
//#include <iostream>
//#include <math.h>
//#include <vector>
//#include <time.h>
//#include <iomanip>
//
//using namespace std;
//
//void generation();
//void show();
//double elementC(int i, int j);
//double elementF(int i, int j, int k);
//double conF(int i, int j);
//double disD(int i, int j);
//double conFdisD(int i, int j);
//double aPointB(int i, int j, int k);
//double bPointA(int i, int j, int k);
//double aConB(int i, int j, int k);
//
//vector<vector<double>> A;			// pxm
//vector<vector<double>> B;			// mxq
//vector<vector<double>> E;			// 1xm
//vector<vector<double>> G;			// pxq
//
//size_t p;
//size_t m;
//size_t q;
//int n;
//int counter = 0;
//
//int main() {
//
//	setlocale(LC_ALL, "ru");
//	cout << " Введите p m q: ";
//	cin >> p >> m >> q;
//	cout << endl << " Введите n: ";
//	cin >> n;
//	vector<vector<double>> C;
//	generation();
//	show();
//	for (int i = 0; i < p; i++) {
//		C.push_back({});
//		for (int j = 0; j < q; j++) {
//			C[i].push_back(elementC(i, j));
//		}
//	}
//	cout << " C:" << endl;
//	for (int i = 0; i < C.size(); i++) {
//		for (int j = 0; j < C[i].size(); j++) {
//			cout << setw(14) << C[i][j];
//		}
//		cout << endl;
//	}
//	cout << " Последовательное время: " << counter << endl;
//	double tn = counter;
//	tn = n >= p * q * m ? tn / (p * q * m) : tn / n;
//	cout << " Параллельное время: " << tn << endl;
//	return 0;
//}
//
//void generation() {
//	srand(time(NULL));
//	for (size_t i = 0; i < p; i++) {
//		A.push_back({});
//		for (size_t j = 0; j < m; j++) {
//			A[i].push_back((double)rand() * (2) / RAND_MAX - 1);
//		}
//	}
//	for (size_t i = 0; i < m; i++) {
//		B.push_back({});
//		for (size_t j = 0; j < q; j++) {
//			B[i].push_back((double)rand() * (2) / RAND_MAX - 1);
//		}
//	}
//	for (size_t i = 0; i < 1; i++) {
//		E.push_back({});
//		for (size_t j = 0; j < m; j++) {
//			E[i].push_back((double)rand() * (2) / RAND_MAX - 1);
//		}
//	}
//	for (size_t i = 0; i < p; i++) {
//		G.push_back({});
//		for (size_t j = 0; j < q; j++) {
//			G[i].push_back((double)rand() * (2) / RAND_MAX - 1);
//		}
//	}
//}
//
//void show() {
//	cout << " A:" << endl;
//	for (size_t i = 0; i < A.size(); i++) {
//		for (size_t j = 0; j < A[i].size(); j++) {
//			cout << setw(14) << A[i][j];
//		}
//		cout << endl;
//	}
//	cout << " B:" << endl;
//	for (size_t i = 0; i < B.size(); i++) {
//		for (size_t j = 0; j < B[i].size(); j++) {
//			cout << setw(14) << B[i][j];
//		}
//		cout << endl;
//	}
//	cout << " E:" << endl;
//	for (size_t i = 0; i < E.size(); i++) {
//		for (size_t j = 0; j < E[i].size(); j++) {
//			cout << setw(14) << E[i][j];
//		}
//		cout << endl;
//	}
//	cout << " G:" << endl;
//	for (size_t i = 0; i < G.size(); i++) {
//		for (size_t j = 0; j < G[i].size(); j++) {
//			cout << setw(14) << G[i][j];
//		}
//		cout << endl;
//	}
//
//}
//
//double elementC(int i, int j) {
//	counter += 12;
//	return conF(i, j) * (3 * G[i][j] - 2) * G[i][j] + (disD(i, j) +
//		(4 * conFdisD(i, j) - 3 * disD(i, j)) * G[i][j]) * (1 - G[i][j]);
//}
//
//double elementF(int i, int j, int k) {
//	counter += 12;
//	return aPointB(i, j, k) * (2 * E[0][k] - 1) * E[0][k] +
//		bPointA(i, j, k) * (1 + (4 * aPointB(i, j, k) - 2) * E[0][k]) * (1 - E[0][k]);
//}
//
//double conF(int i, int j) {
//	double result = 1.0;
//	for (int k = 0; k < B.size(); k++) {
//		counter++;
//		result *= elementF(i, j, k);
//	}
//	return result;
//}
//
//double disD(int i, int j) {
//	double result = 1.0;
//	for (int k = 0; k < B.size(); k++) {
//		counter += 2;
//		result *= 1 - aConB(i, j, k);
//	}
//	counter++;
//	return 1 - result;
//}
//
//double conFdisD(int i, int j) {
//	counter++;
//	return conF(i, j) * disD(i, j);
//}
//
//double aPointB(int i, int j, int k) {
//	double result = 1 - A[i][k] + B[k][j];
//	counter += 3;
//	return result < 0 ? result : 0;
//}
//
//double bPointA(int i, int j, int k) {
//	double result = 1 - B[k][j] + A[i][k];
//	counter += 3;
//	return result < 0 ? result : 0;
//}
//
//double aConB(int i, int j, int k) {
//	double result = A[i][k] + B[k][j] - 1;
//	counter += 3;
//	return result > 0 ? result : 0;
//}
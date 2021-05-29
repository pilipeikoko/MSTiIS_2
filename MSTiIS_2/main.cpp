#include "MatrixConverter.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	size_t p;
	size_t m;
	size_t q;

	int n;

	cout << " Введите p m q: \n";
	cin >> p >> m >> q;
	cout << " Введите n: ";
	cin >> n;

	MatrixConverter* matrixConverter = new MatrixConverter(p, m, q, n);

	matrixConverter->printInputMatrixes();
	matrixConverter->printC();

	cout << " Последовательное время: " << matrixConverter->getCounter() << endl;
	cout << " Параллельное время: " << matrixConverter->getParallelTime() << endl;
}
#include "MatrixConverter.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	size_t p;
	size_t m;
	size_t q;

	int n;

	cout << " ������� p m q: \n";
	cin >> p >> m >> q;
	cout << " ������� n: ";
	cin >> n;

	MatrixConverter* matrixConverter = new MatrixConverter(p, m, q, n);

	matrixConverter->printInputMatrixes();
	matrixConverter->printC();

	cout << " ���������������� �����: " << matrixConverter->getCounter() << endl;
	cout << " ������������ �����: " << matrixConverter->getParallelTime() << endl;
}
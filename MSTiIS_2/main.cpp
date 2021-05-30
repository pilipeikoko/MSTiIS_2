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

	cout << " ���������������� �����: " << matrixConverter->getSequentialTime() << endl;
	cout << " ������������ �����: " << matrixConverter->getParallelTime() << endl;
	cout << " ����������� ���������: " << matrixConverter->getCoefficientOfAcceleration() << endl;
	cout << " �������������: " << matrixConverter->getEffectivity() << endl;
	cout << " ��������� ����� ��������: " << matrixConverter->getSumLenthOfProgram() << endl;

	int time_of_sum, time_of_difference, time_of_multiplicity, time_of_comparing;

	cout << " ����� �����:\n";
	cin >> time_of_sum;
	cout << " ����� ��������:\n";
	cin >> time_of_difference;
	cout << " ����� ���������:\n";
	cin >> time_of_multiplicity;
	cout << " ����� ���������:\n";
	cin >> time_of_comparing;

	cout << " ������� ������: " << matrixConverter->getLavg(time_of_sum, time_of_difference, time_of_multiplicity, time_of_comparing) << endl;
	cout << " ����������� ����������� ���������: " << matrixConverter->getD(time_of_sum, time_of_difference, time_of_multiplicity, time_of_comparing);

	delete matrixConverter;
}
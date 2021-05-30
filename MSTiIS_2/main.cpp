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

	cout << " Последовательное время: " << matrixConverter->getSequentialTime() << endl;
	cout << " Параллельное время: " << matrixConverter->getParallelTime() << endl;
	cout << " Коэффициент ускорения: " << matrixConverter->getCoefficientOfAcceleration() << endl;
	cout << " Эффективность: " << matrixConverter->getEffectivity() << endl;
	cout << " Суммарная длина програмы: " << matrixConverter->getSumLenthOfProgram() << endl;

	int time_of_sum, time_of_difference, time_of_multiplicity, time_of_comparing;

	cout << " Время суммы:\n";
	cin >> time_of_sum;
	cout << " Время разности:\n";
	cin >> time_of_difference;
	cout << " Время умножения:\n";
	cin >> time_of_multiplicity;
	cout << " Время сравнения:\n";
	cin >> time_of_comparing;

	cout << " Средняя длинна: " << matrixConverter->getLavg(time_of_sum, time_of_difference, time_of_multiplicity, time_of_comparing) << endl;
	cout << " Коэффициент расхождения программы: " << matrixConverter->getD(time_of_sum, time_of_difference, time_of_multiplicity, time_of_comparing);

	delete matrixConverter;
}
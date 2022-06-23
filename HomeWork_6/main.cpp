//****Реализовать класс Matrix.
// В классе надо реализовать следующие операторы :
//	- операторы ввода - вывода(>> , << )
//	- операторы равно и не равно(== , != )
//	- оператор индексирования(получение элемента по строке и столбцу) (как говорил лучше реализовать через оператор[i][j], если не получится,
//  то можно попробовать через оператор вызова(i, j), или уже через свой собственный метод)
//	- арифметические операторы сложения, вычитания, умножения(каждая операция с числом и с матрицей) (+, -, *, +=, -=, *=)
//	- операторы инкремента и декремента(++, --) : префиксные и постфиксные(поэлементно добавить 1 и отнять 1 соответственно)
//**Для простоты можно реализовать целочисленную матрицу(с вещественнными могут быть нюансы при сравнении(обычно вещественные числа 
// сравниваются с погрешностью. Кому будет интересно, то в интернете можно исследовать тему относительная погрешность и сравнение вещественных чисел)).
//
//#На 9 максимум - это реализация с вектором векторов
//#На 10 - с одним вектором

#include <iostream>
#include "matrix.h"

int main()
{
	Matrix matrix1(3, 3);
	Matrix matrix2(3, 3);
	for (int i = 0; i < matrix1.GetRow(); ++i) {
		for (int j = 0; j < matrix1.GetCol(); ++j) {
			matrix1[i][j] = i;
		}
	}

	for (int i = 0; i < matrix2.GetRow(); ++i) {
		for (int j = 0; j < matrix2.GetCol(); ++j) {
			matrix2[i][j] = j;
		}
	}
	std::cout << "matrix1:\n" << matrix1 << "\nmatrix2:\n" << matrix2;

	if (matrix1.GetCol() == matrix2.GetCol() && matrix1.GetRow() == matrix2.GetCol())
		matrix1 += matrix2;
	std::cout << "matrix1 + matrix2:\n" << matrix1;

	if (matrix1.GetRow() == matrix2.GetCol())
		matrix1 *= matrix2;
	std::cout << "matrix1 *= matrix2:\n" << matrix1;

	if (matrix1.GetCol() == matrix2.GetCol() && matrix1.GetRow() == matrix2.GetCol())
		matrix1 -= matrix2;
	std::cout << "matrix1 - matrix2:\n" << matrix1;

	++matrix1;
	std::cout << "++matrix1:\n" << matrix1;
	
	--matrix1;
	std::cout << "--matrix1:\n" << matrix1;


}
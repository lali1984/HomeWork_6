//****����������� ����� Matrix.
// � ������ ���� ����������� ��������� ��������� :
//	- ��������� ����� - ������(>> , << )
//	- ��������� ����� � �� �����(== , != )
//	- �������� ��������������(��������� �������� �� ������ � �������) (��� ������� ����� ����������� ����� ��������[i][j], ���� �� ���������,
//  �� ����� ����������� ����� �������� ������(i, j), ��� ��� ����� ���� ����������� �����)
//	- �������������� ��������� ��������, ���������, ���������(������ �������� � ������ � � ��������) (+, -, *, +=, -=, *=)
//	- ��������� ���������� � ����������(++, --) : ���������� � �����������(����������� �������� 1 � ������ 1 ��������������)
//**��� �������� ����� ����������� ������������� �������(� �������������� ����� ���� ������ ��� ���������(������ ������������ ����� 
// ������������ � ������������. ���� ����� ���������, �� � ��������� ����� ����������� ���� ������������� ����������� � ��������� ������������ �����)).
//
//#�� 9 �������� - ��� ���������� � �������� ��������
//#�� 10 - � ����� ��������

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
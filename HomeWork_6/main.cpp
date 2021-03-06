//****??????????? ????? Matrix.
// ? ?????? ???? ??????????? ????????? ????????? :
//	- ????????? ????? - ??????(>> , << )
//	- ????????? ????? ? ?? ?????(== , != )
//	- ???????? ??????????????(????????? ???????? ?? ?????? ? ???????) (??? ??????? ????? ??????????? ????? ????????[i][j], ???? ?? ?????????,
//  ?? ????? ??????????? ????? ???????? ??????(i, j), ??? ??? ????? ???? ??????????? ?????)
//	- ?????????????? ????????? ????????, ?????????, ?????????(?????? ???????? ? ?????? ? ? ????????) (+, -, *, +=, -=, *=)
//	- ????????? ?????????? ? ??????????(++, --) : ?????????? ? ???????????(??????????? ???????? 1 ? ?????? 1 ??????????????)
//**??? ???????? ????? ??????????? ????????????? ???????(? ?????????????? ????? ???? ?????? ??? ?????????(?????? ???????????? ????? 
// ???????????? ? ????????????. ???? ????? ?????????, ?? ? ????????? ????? ??????????? ???? ????????????? ??????????? ? ????????? ???????????? ?????)).
//
//#?? 9 ???????? - ??? ?????????? ? ???????? ????????
//#?? 10 - ? ????? ????????

#include <iostream>
#include "matrix.h"

int main()
{
	Matrix m1(10, 10);
	Matrix m2(10, 10);
	Matrix m3(3, 3);
	int n = 1;
	for (int i = 0; i < m1.GetRow(); ++i) {
		for (int j = 0; j < m1.GetCol(); ++j) {
			m1[i][j] = i;
			n++;
		}
	}

	for (int i = 0; i < m2.GetRow(); ++i) {
		for (int j = 0; j < m2.GetCol(); ++j) {
			m2[i][j] = j;
		}
	}

	std::cout << "matrix1:\n" << m1 << "\nmatrix2:\n" << m2;

	m2 = m1;
	std::cout << "matrix1:\n" << m1 << "\nmatrix2:\n" << m2;

	m1 += 1;
	std::cout << "matrix1:\n" << m1 << "\nmatrix2:\n" << m2;

	m3 = m1 + 4;
	std::cout << "matrix1:\n" << m1 << "\nmatrix2:\n" << m2 << "\nmatrix3:\n" << m3;

	m1 += m2;
	std::cout << "matrix1:\n" << m1 << "\nmatrix2:\n" << m2;

	m3 = m1 + m2;
	std::cout << "matrix1:\n" << m1 << "\nmatrix2:\n" << m2 << "\nmatrix3:\n" << m3;

	m1 -= 1;
	std::cout << "matrix1:\n" << m1 << "\nmatrix2:\n" << m2;

	m3 = m1 - 1;
	std::cout << "matrix1:\n" << m1 << "\nmatrix2:\n" << m2 << "\n matrix3:\n" << m3;
	
	m1 -= m2;
	std::cout << "matrix1:\n" << m1 << "\nmatrix2:\n" << m2;

	m1 *= m2;
	std::cout << "matrix1:\n" << m1 << "\nmatrix2:\n" << m2;

	m3 = m1 * m2;
	std::cout << "matrix1:\n" << m1 << "\nmatrix2:\n" << m2 << "\n matrix3:\n" << m3;

	++m1;
	std::cout << "++matrix1:\n" << m1;
	
	--m1;
	std::cout << "--matrix1:\n" << m1;

	m1[9][9] = 67;
	std::cout << m1;
}
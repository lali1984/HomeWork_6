#pragma once
#include <vector>
#include <iomanip>
#include <iostream>

class Matrix
{
public:
	Matrix() {};
	Matrix(unsigned row, unsigned col);
	Matrix(const Matrix& m);
	std::vector<int>::iterator& getItRow(unsigned numRow);
	const void WriteMatrix() const;
	const int GetRow() const;
	const int GetCol() const;
	const std::vector<int>& GetNumbers() const;

	std::vector<int>::iterator& operator[](unsigned numCol);
	Matrix& operator=(const Matrix& that);
	Matrix& operator+=(int num);
	Matrix& operator+=(const Matrix& m1);
	Matrix operator+(int num);
	Matrix operator+(Matrix& m);
	Matrix& operator-=(int mun);
	Matrix& operator-=(const Matrix& m2);
	Matrix operator-(int m);
	Matrix operator-(Matrix& m);
	Matrix& operator++();
	Matrix& operator--();
	Matrix operator++(int);
	Matrix operator--(int);
	Matrix& operator*=(Matrix& m2);
	Matrix operator*(Matrix& m);



private:
	unsigned row_ = 0, col_ = 0;
	std::vector<int> matrix_{0};
	std::vector<int>::iterator itRow_ = matrix_.begin();
};

bool operator!=(const Matrix& m1, const Matrix& m2);
bool operator==(const Matrix& m1, const Matrix& m2);
std::ostream& operator<<(std::ostream& op, Matrix& that);
std::istream& operator>>(std::istream& in, Matrix& that);
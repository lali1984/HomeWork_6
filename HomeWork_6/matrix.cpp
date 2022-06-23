#include "matrix.h"

Matrix::Matrix(const unsigned row, const unsigned col) : row_(row), col_(col)
{
	std::vector<int> matrix(row * col);
	matrix_ = matrix;
	for (auto it = matrix_.begin(); it != matrix_.end(); ++it) {
		*it = 0;
	}
}

Matrix::Matrix(const Matrix& that) : row_(that.row_), col_(that.col_), matrix_(that.matrix_), itRow_(that.itRow_)
{
}

const std::vector<int>& Matrix::GetNumbers() const
{
	return matrix_;
}

const void Matrix::WriteMatrix() const
{
	std::cout << "\n";
	for (unsigned i = 1; i <= (row_ * col_); ++i) {
		std::cout << std::setw(3) << matrix_[i - 1] << " ";

		if (i % col_ == 0) {
			std::cout << "\n";
		}
	}

	std::cout << "\n";
}

const int Matrix::GetRow() const 
{
	return row_;
}

const int Matrix::GetCol() const
{
	return col_;
}

std::vector<int>::iterator& Matrix::getItRow(unsigned numRow) 
{
	itRow_ = matrix_.begin() + (numRow * col_);
	return itRow_;
}

std::vector<int>::iterator& Matrix::operator[](unsigned numCol) 
{
	return 	getItRow(numCol);
}

Matrix& Matrix::operator=(const Matrix& that)
{
	row_ = that.row_;
	col_ = that.col_; 
	matrix_ = that.matrix_;
	itRow_ = that.itRow_;
	return *this;
}

Matrix& Matrix::operator+=(int num)
{
	for (auto& m : matrix_) {
		m = m + num;
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& m2)
{
	int i = 0;
	for (auto& m : matrix_) {
		m += m2.matrix_[i];
		++i;
	}
	return *this;
}

Matrix Matrix::operator+(int num)
{
	Matrix m = *this;
	*this += num;
	return m ;
}

Matrix Matrix::operator+(Matrix& m)
{
	m = *this;
	*this += m;
	return m;

}

Matrix& Matrix::operator-=(int num)
{
	for (auto& m : matrix_) {
		m = m - num;
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& m2)
{
	int i = 0;
	for (auto& m : matrix_) {
		m -= m2.matrix_[i];
		++i;
	}
	return *this;
}

Matrix Matrix::operator-(int num)
{
	Matrix m = *this;
	*this -= num;
	return m;
}

Matrix Matrix::operator-(Matrix& m)
{
	m = *this;
	*this -= m;
	return m;

}

Matrix& Matrix::operator++() 
{
	for (auto& v : matrix_) {
		v = v + 1;
	}

	return *this;
}

Matrix& Matrix::operator--()
{
	for (auto& v : matrix_) {
		v = v - 1;
	}

	return *this;
}

Matrix Matrix::operator++(int)
{
	Matrix m = (*this);
	++(*this);
	return m;
}

Matrix Matrix::operator--(int)
{
	Matrix m = (*this);
	--(*this);
	return m;
}

Matrix& Matrix::operator*=(Matrix& m2)
{
	Matrix m1 = *this;
	Matrix mul(m1.row_, m2.col_);
	for (int i = 0; i < m1.row_; ++i) {
		for (int j = 0; j < m2.col_; ++j) {
			mul[i][j] = 0;
				for (int n = 0; n < m1.col_; ++n) {
					mul[i][j] += m1[i][n] * m2[n][j];
				}
		}
	}
	*this = mul;
	return *this;
}

Matrix Matrix::operator*(Matrix& m2)
{
	return *this *= m2;
}

std::ostream& operator<<(std::ostream& op, Matrix& that)
{
	for (int i = 0; i < that.GetRow(); ++i) {
		for (int j = 0; j < that.GetCol(); ++j) {
			op << std::setw(3) << that[i][j];
		}
		std::cout << "\n";
	}

	return op;
}

std::istream& operator>>(std::istream& in, Matrix& that)
{
	for (int i = 0; i < that.GetRow(); ++i) {
		for (int j = 0; j < that.GetCol(); ++j) {
			in >> std::setw(3) >> that[i][j];
		}
	}

	return in;
}

bool operator==(const Matrix& m1, const Matrix& m2)
{
	if (m1.GetCol() == m2.GetCol() && m1.GetCol() == m2.GetCol() && m1.GetNumbers() == m2.GetNumbers())
		return true;
	else
		return false;
}

bool operator!=(const Matrix& m1, const Matrix& m2)
{
	return !(m1 == m2);
}

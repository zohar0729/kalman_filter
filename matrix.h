#ifndef DEF_KALMAN_MATRIX_H

#define DEF_KALMAN_MATRIX_H

//実装予定
//・行列同士の加算
//・行列同士の乗算
//・逆行列の計算
//・行列の代入
//・添字を用いた要素の参照

namespace kalman_filter{

class row{
public:
	row();
	row(row&);
	row(int);
	const double operator[](const unsigned int);
	double& operator[](const unsigned int);
	int columns(){return columns.size();;}
private:
	std::vector<double> columns;
};

class matrix{
public:
	matrix();
	matrix(matrix&);
	matrix(int, int);
	matrix operator+(const matrix&, const matrix&);
	matrix operator-(const matrix&, const matrix&);
	matrix operator*(const matrix&, const matrix&);
	matrix operator*(const double, const matrix&);
	matrix operator/(const matrix&, const matrix&);
	matrix& operator=(const matrix&);
	const row& operator[](const unsigned int);
	row& operator[](const unsigned int);
	matrix add(const matrix&, const matrix&);
	matrix mul(const matrix&, const matrix&);
	matrix inv(const matrix&);
	double det(const matrix&);
	int rows(){return rows.size();}
	int columns(){return rows[0].columns();}
private:
	std::vector<row> rows;
};

}

#endif

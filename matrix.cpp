#include "matrix.h"

matrix::matrix(){
	n_rows = 0;
}

matrix::matrix(matrix& m){
	this->n_rows = m.n_rows;
	this->rows = m.rows;
}

matrix::matrix(int r, int c) : n_rows(r) {
	int i;
	for(i=0; i<r; i++){
		rows.emplace_back(c);
	}
}

matrix add(const matrix& m1, const matrix& m2){
	try{
		if(m1.rows() == 0
		|| m2.rows() == 0)
			throw "There is empty matrix.";
		if(m1.rows() != m2.rows()
		|| m1.columns() != m2.columns())
			throw "Sizes of two matrix is diffrent.";
	}catch(char* str){
		std::cout << str << endl;
	}
	matrix *m = new matrix(m1.rows(), m1.columns());
	for(int i=0; i<m1.rows(); i++){
		for(int j=0; j<m1.columns(); j++){
			m[i][j] = m1[i][j] + m2[i][j];
		}
	}
	return *m;
}

matrix mul(const matrix& m1, const matrix& m2){
	try{
		if(m1.rows() == 0
		|| m2.rows() == 0
		|| m1.columns() == 0
		|| m2.columns() == 0)
			throw "There is empty matrix.";
		if(m1.columns() != m2.rows())
			throw "It's impossible to multiply.";
	}catch(char* str){
		std::cout << str << endl;
	}
	matrix *m = new matrix(m1.rows(), m2.columns());
	for(int i=0; i<m1.rows(); i++){
		for(int j=0; j<m2.columns; j++){
			m[i][j] = 0;
			for(int k=0; k<m1.columns(); k++){
				m[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	return *m;
}


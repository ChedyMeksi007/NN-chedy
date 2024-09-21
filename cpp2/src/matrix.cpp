#include "../include/matrix.hpp"
#include <random>
#include <vector>

Matrix :: Matrix(int numRows, int numCols, bool isRandom){

	this->numRows = numRows;
	this->numCols = numCols;

	for(int i = 0; i < numRows ; i++){
		vector<double> colValues;

		for(int j = 0; j < numCols; j++){
			double r = isRandom ? this->generateRandomNumber() : 0.0;

			colValues.push_back(r);
		}
		this->values.push_back(colValues);
	}
}

Matrix* Matrix :: transpose(){
	Matrix* m = new Matrix(this->numCols, this->numRows, false);

	for(int i = 0; i< this->numRows; i++){
		for(int j = 0; j< this->numCols; j++){
			m->setValue(j,i,this->getValue(i,j));
		}
	}
	return m;
}

Matrix* Matrix :: copy(){

	Matrix* m = new Matrix(this->numRows, this->numCols, false);

	for(int i = 0; i< this->numRows; i++){
		for(int j = 0; j< this->numCols; j++){
			m->setValue(i,j,this->getValue(i,j));
		}
	}
	return m;
}

void Matrix :: setValue(int r, int c , double v){
	this->values.at(r).at(c) = v;
}

void Matrix :: printToConsole(){

	for(int i = 0 ; i < this->numRows; i++){
		for(int j = 0 ; j < this->numCols ; j++){
			cout << this->values.at(i).at(j) << "\t\t";
		}
	}
	cout << endl;
}

double Matrix :: generateRandomNumber() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<> dis(0.0,1.0);

	return dis(gen);
}

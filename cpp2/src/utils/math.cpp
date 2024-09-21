#include "../../include/utils/math.hpp"
#include <cstdlib>

void utils::Math::multiplyMatrix(Matrix* a, Matrix* b, Matrix* c){

	for(int i = 0; i< a->getNumRows(); i++){
		for(int j = 0; j < b->getNumCols() ; j++){
			for(int k = 0; k < b->getNumRows(); k++){
				double p = a->getValue(i,k) * b->getValue(k,j);
				double newValue = c->getValue(i,j) + p;
				c->setValue(i,j,newValue);
			}
			c->setValue(i,j,c->getValue(i,j));
		}
	}
}

void utils::Math::addMatrix(Matrix* a, Matrix* b, Matrix* c){

	if(a->getNumRows() != b-> getNumRows() || a->getNumCols() != b->getNumCols()){
		cerr << "Matrix additon not possible due to differnt orders" << endl;
		exit(-1);
	}

	for(int row = 0; row < a->getNumRows();row++){
		for(int col = 0; col< a ->getNumCols();col++){
			double newValue = a->getValue(row,col) * b->getValue(row,col);
			c->setValue(row,col,newValue);
		}
	}
}

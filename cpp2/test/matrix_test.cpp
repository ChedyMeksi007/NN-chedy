#include <gtest/gtest.h>
#include "../include/matrix.hpp"

TEST( MatrixClass, Constructor ){
	Matrix m{3,3,false};
	ASSERT_EQ(m.getNumCols(),3);
	ASSERT_EQ(m.getNumRows(),3);

	vector<vector<double>> m_values = m.getValues();

	for(int r = 0; r<3; r++){
		for(int c = 0; c<3; c++){
			ASSERT_EQ(m_values.at(r).at(c),0);
		}
	}
}

TEST( MatrixClass, Transpose ){

	Matrix m{2,3,false};

	m.setValue(0,1,1);
	m.setValue(1,1,1);

	Matrix* m_t = m.transpose();

	ASSERT_EQ(m_t->getNumCols(),m.getNumRows());
	ASSERT_EQ(m_t->getNumRows(),m.getNumCols());

	for(int r = 0; r<3; r++){
		for(int c = 0; c<2; c++){
			if(r != 1){
				ASSERT_EQ(m_t->getValues().at(r).at(c),0);
			}else{

				ASSERT_EQ(m_t->getValues().at(r).at(c),1);
			}
		}
	}

	Matrix m1{2,3,true};


	Matrix* m1_t = m1.transpose();

	ASSERT_EQ(m1_t->getNumCols(),m1.getNumRows());
	ASSERT_EQ(m1_t->getNumRows(),m1.getNumCols());

	for(int r = 0; r<2; r++){
		for(int c = 0; c<3; c++){
				ASSERT_EQ(m1.getValues().at(r).at(c),m1_t->getValues().at(c).at(r));

		}
	}
}

TEST ( MatrixClass, Copy ) {
	Matrix m{2,2,true};

	Matrix* m_c = m.copy();

	ASSERT_EQ(m_c->getNumCols(),m.getNumCols());
	ASSERT_EQ(m_c->getNumRows(),m.getNumRows());

	for(int r = 0; r<2 ; r++){
		for(int c = 0; c<2; c++){
			ASSERT_EQ(m.getValue(r,c),m_c->getValue(r,c));
		}
	}

}

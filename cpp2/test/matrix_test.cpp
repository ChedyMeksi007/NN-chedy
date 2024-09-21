#include <gtest/gtest.h>
#include "../include/matrix.hpp"
#include "../include/utils/math.hpp"

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

TEST (MatrixClass, Multiplication ){

	//same size Matrices
	Matrix a{2,2,false};
	Matrix b{2,2,false};
	Matrix c{2,2,false};
	Matrix e{2,2,false};


	//
	// |2 5| * |3 4| = |11 13|
	// |1 0|   |1 1|   | 3 4 |
	//
	//
	//


	a.setValue(0,0,2);
	a.setValue(0,1,5);
	a.setValue(1,0,1);
	a.setValue(1,1,0);

	b.setValue(0,0,3);
	b.setValue(0,1,4);
	b.setValue(1,0,1);
	b.setValue(1,1,1);

	c.setValue(0,0,11);
	c.setValue(0,1,13);
	c.setValue(1,0,3);
	c.setValue(1,1,4);

	utils::Math::multiplyMatrix(&a,&b,&e);


	for(int row = 0; row<2 ; row++){
		for(int col = 0; col<2; col++){
			ASSERT_EQ(e.getValue(row,col),c.getValue(row,col));
		}
	}

}

TEST (MatrixClass, Addition ) {

	//same size Matrices
	Matrix a{2,2,false};
	Matrix b{2,2,false};
	Matrix c{2,2,false};
	Matrix e{2,2,false};


	//
	// |1 2| + |5 6| = |6   8|
	// |3 4|   |7 8|   |10 12|
	//
	//
	//


	a.setValue(0,0,1);
	a.setValue(0,1,2);
	a.setValue(1,0,3);
	a.setValue(1,1,4);

	b.setValue(0,0,5);
	b.setValue(0,1,6);
	b.setValue(1,0,7);
	b.setValue(1,1,8);

	c.setValue(0,0,6);
	c.setValue(0,1,8);
	c.setValue(1,0,10);
	c.setValue(1,1,12);

	utils::Math::addMatrix(&a,&b,&e);


	for(int row = 0; row<2 ; row++){
		for(int col = 0; col<2; col++){
			ASSERT_EQ(e.getValue(row,col),c.getValue(row,col));
		}
	}

	//different order
	Matrix e1{2,2,false};

	utils::Math::addMatrix(&b,&a,&e1);


	for(int row = 0; row<2 ; row++){
		for(int col = 0; col<2; col++){
			ASSERT_EQ(e1.getValue(row,col),c.getValue(row,col));
		}
	}

}

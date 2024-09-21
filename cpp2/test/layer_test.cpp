
#include <gtest/gtest.h>
#include "../include/layer.hpp"
#include "../include/matrix.hpp"

TEST( LayerClass, Constructor_1){
	Layer l{10};
	ASSERT_EQ(l.getNeurons().size(),10);
}

TEST( LayerClass, Constructor_2){
	Layer l{12};
	ASSERT_EQ(l.getNeurons().size(),12);
}

TEST( LayerClass, Matrixify){

	Matrix m{1,6,false};
	Layer l{6};

	Matrix* m1 = l.matrixifyVals();


	ASSERT_EQ(m.getNumCols(),m1->getNumCols());
	ASSERT_EQ(m.getNumRows(),m1->getNumRows());

	for(int r = 0; r<1; r++){
		for(int c = 0; c<6; c++){
				ASSERT_EQ(m.getValues().at(r).at(c),m1->getValues().at(r).at(c));

		}
	}
}

TEST( LayerClass, ActivatedMatrixify ){
	Layer l{5};

	Matrix* m = l.matrixifyActivatedVals();

	for(int i = 0; i<5; i++){
		ASSERT_EQ(m->getValue(0,i),0.5);
	}

}

TEST( LayerClass, DerivedMatrixify ){
	 Layer l{5};

	Matrix* m = l.matrixifyDerivedVals();

	for(int i = 0; i<5; i++){
		ASSERT_EQ(m->getValue(0,i),0.25);
	}


}

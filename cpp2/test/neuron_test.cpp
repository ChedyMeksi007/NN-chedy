#include <gtest/gtest.h>
#include "../include/neuron.hpp"

TEST( NeuronClass, Constructor_1){
	Neuron n{1};
	ASSERT_EQ(1,n.getValue());
}

TEST( NeuronClass, Constructor_2){
	/*
	 * Testing the Sig function and its derivative
	 */
	Neuron n1{0,3};
	ASSERT_EQ(0,n1.getValue());
	ASSERT_EQ(0.5,n1.getActivatedValue());
	ASSERT_EQ(0.25,n1.getDerivedValue());
	/*
	 * Testing the RELU function and its derivative
	 */
	Neuron n2{1.77,2};
	ASSERT_EQ(1.77,n2.getValue());
	ASSERT_EQ(1.77,n2.getActivatedValue());
	ASSERT_EQ(1,n2.getDerivedValue());
	/*
	 * Testing the TANH function and its derivative
	 */
	Neuron n3{10,1};
	ASSERT_EQ(10,n3.getValue());
	ASSERT_TRUE(abs(1 - n3.getActivatedValue()) < 0.001);
	ASSERT_TRUE(abs(0-n3.getDerivedValue())< 0.001);
}

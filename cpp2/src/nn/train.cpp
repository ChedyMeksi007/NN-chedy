#include "../../include/nn.hpp"
#include <vector>


void NN :: train(vector<double> input,vector<double> target,double learningRate,double momentum){
	this->learningRate = learningRate;
	this->momentum = momentum;
	this->setCurrentInput(input);
	this->setCurrentTarget(target);
	this->feedForward();
	this->setErrors();
	this->backPropagation();
}

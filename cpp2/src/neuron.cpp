#include "../include/neuron.hpp"
#include <cmath>

void Neuron :: setVal(double value){
	this->value = value;
	activate();
	derive();
}

void Neuron :: activate(){

	switch(activationType){
		case TANH:
			this->activatedValue = tanh(this->value);
			break;
		case RELU:
			this->activatedValue =  this->value > 0 ? this->value : 0 ;
			break;
		case SIGM:
			this->activatedValue = (1 / (1 + exp(- this->value)));
			break;
	}
}

void Neuron :: derive(){

	switch(activationType){
		case TANH:
			this->derivedValue = ( 1.0 - pow(this->activatedValue,2));
			break;
		case RELU:
			this->derivedValue =  this->value > 0 ? 1 : 0;
			break;
		case SIGM:
		default:
			this->derivedValue = this->activatedValue * (1 - this->activatedValue);
			break;
	}
}

Neuron :: Neuron(double value){
	this->setVal(value);
}

Neuron :: Neuron(double value, int activationType){
	this->activationType = activationType;
	this->setVal(value);
}

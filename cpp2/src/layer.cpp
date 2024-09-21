#include "../include/layer.hpp"

Layer :: Layer(int size){

	this->size = size;

	for(int i = 0 ; i < size ; i++){
		Neuron* n = new Neuron(0.0000);
		this->neurons.push_back(n);
	}
}

Layer :: Layer(int size, int activationType){

	this->size = size;

	for(int i = 0 ; i < size ; i++){
		Neuron* n = new Neuron(0.0000,activationType);
		this->neurons.push_back(n);
	}
}

void  Layer :: setVal(int i, double v){
	this->neurons.at(i)->setVal(v);
}

Matrix* Layer :: matrixifyVals(){
	Matrix* m = new Matrix(1, this->neurons.size(), false);

	for(int i = 0; i< this->neurons.size(); i++){
		m->setValue(0,i,this->neurons.at(i)->getValue());
	}

	return m;
}

Matrix* Layer :: matrixifyActivatedVals(){

	Matrix* m = new Matrix(1, this->neurons.size(), false);

	for(int i = 0; i< this->neurons.size(); i++){
		m->setValue(0,i,this->neurons.at(i)->getActivatedValue());
	}

	return m;
}

Matrix* Layer :: matrixifyDerivedVals(){

	Matrix* m = new Matrix(1, this->neurons.size(), false);

	for(int i = 0; i< this->neurons.size(); i++){
		m->setValue(0,i,this->neurons.at(i)->getDerivedValue());
	}

	return m;
}

vector<double> Layer :: getActivatedVals(){

	vector<double> actV;

	for(int i = 0; i < this->neurons.size(); i++){
		actV.push_back(this->neurons.at(i)->getActivatedValue());
	}

	return actV;
}

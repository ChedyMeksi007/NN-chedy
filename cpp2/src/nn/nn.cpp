#include "../../include/nn.hpp"
#include <fstream>
#include <vector>

using json = nlohmann::json;


NN ::NN(
	vector<int> topology,
	double learningRate,
	double momentum
       ){

	this->topology = topology;
	this->topologySize = topology.size();
	this-> learningRate = learningRate;
	this-> momentum = momentum;

	for(int i = 0 ; i< topologySize; i++){
		if(i > 0 && i < topologySize-1){
			Layer* l = new Layer(topology.at(i), this->hiddenActivationType);
			this->layers.push_back(l);

		}else if(i== topologySize -1){
			Layer* l = new Layer(topology.at(i), this->outputActivationType);
			this->layers.push_back(l);
		}else{
			Layer* l = new Layer(topology.at(i));
			this->layers.push_back(l);
		}

	}
	// init weights
	for(int i = 0 ; i < topologySize -1; i++){
		Matrix* weightMatrix = new Matrix(topology.at(i), topology.at(i+1), true);
		this->weightMatrices.push_back(weightMatrix);
	}

	// init biases
	for(int i = 0 ; i < topologySize -1; i++){
		Matrix* biasMatrix = new Matrix(1,topology.at(i+1), true);
		this->biasMatrices.push_back(biasMatrix);
	}

	// init errors
	for(int i = 0; i < topology.at(topologySize - 1) ; i++){
		errors.push_back(0.00);
		derivedErrors.push_back(0.00);
	}

	this-> error = 0.00;

}

NN :: NN(
	vector<int> topology,
	int hiddenActivationType,
	int outputActivationType,
	int costFunctionType,
	double learningRate,
	double momentum
	){

	this->topology = topology;
	this->topologySize = topology.size();
	this-> learningRate = learningRate;
	this-> momentum = momentum;

	this->hiddenActivationType = hiddenActivationType;
	this->outputActivationType = outputActivationType;
	this->costFunctionType = costFunctionType;

	for(int i = 0 ; i< topologySize; i++){
		if(i > 0 && i < topologySize-1){
			Layer* l = new Layer(topology.at(i), this->hiddenActivationType);
			this->layers.push_back(l);

		}else if(i== topologySize -1){
			Layer* l = new Layer(topology.at(i), this->outputActivationType);
			this->layers.push_back(l);
		}else{
			Layer* l = new Layer(topology.at(i));
			this->layers.push_back(l);
		}

	}


	for(int i = 0 ; i < topologySize -1; i++){
		Matrix* weightMatrix = new Matrix(topology.at(i), topology.at(i+1), true);
		this->weightMatrices.push_back(weightMatrix);
	}

	// init biases
	for(int i = 0 ; i < topologySize -1; i++){
		Matrix* biasMatrix = new Matrix(1,topology.at(i+1), true);
		this->biasMatrices.push_back(biasMatrix);
	}
	for(int i = 0; i < topology.at(topologySize - 1) ; i++){
		errors.push_back(0.00);
		derivedErrors.push_back(0.00);
	}

	this-> error = 0.00;
}

void NN :: setCurrentInput(vector<double> input){
	this->input = input;

	for(int i =0; i< input.size();i++){
		this->layers.at(0)->setVal(i,input.at(i));

	}

}

void NN :: saveWeights(string filename){
	json j = {};

	vector<vector<vector<double>>>  weightSet;

	for(int i= 0; i < this->weightMatrices.size();i++){
		weightSet.push_back(this->weightMatrices.at(i)->getValues());
	}

	j["weight"] = weightSet;
	std:: ofstream o(filename);
	o << std::setw(4) << j << endl;
}

void NN :: loadWeights(string filename){
	std:: ifstream i(filename);
	json jWeights;
	i >> jWeights;

vector<	vector<vector<double>>> temp = jWeights["weights"];


	for(int i=0;this->weightMatrices.size();i++){
		for(int r = 0; r<this->weightMatrices.at(i)->getNumRows();r++){
			for(int c = 0; c < this->weightMatrices.at(i)->getNumCols();c++){
				this->weightMatrices.at(i)->setValue(r,c,temp.at(i).at(r).at(c));
			}
		}
	}

}

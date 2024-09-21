#include "../../include/nn.hpp"
#include <cassert>
#include <cmath>

void NN :: setErrors(){
	if(this->target.size() == 0){
		cerr << "No target for this NN" << endl;
		assert(false);
	}

	if(this->target.size() != this->layers.at(this->layers.size() -1)->getNeurons().size()){
		cerr << "Target size (" << this->target.size() << " ) is not the same as output layer size "
			<< this->layers.at(this->layers.size() - 1)->getNeurons().size() << endl;

		for(int i = 0; i < this->target.size(); i++){
			cout << this->target.at(i) << endl;
		}
		assert(false);
	}

	switch(costFunctionType){
		case (COST_MSE) : this->setErrorsMSE();
				  break;
		case (SUBTRACTION) : this->setErrorsSUB();
				      break;
		default: this->setErrorsMSE();
			 break;
	}
}

void NN::setErrorsSUB() {
    int outputLayerIndex = this->layers.size() - 1;
    vector<Neuron*> outputNeurons = this->layers.at(outputLayerIndex)->getNeurons();

    this->error = 0.0f;

    // Total number of output neurons, used for the MSE calculation
    int numOutputs = target.size();

    for (int i = 0; i < numOutputs; i++) {
        double t = target.at(i);  // target value
        double y = outputNeurons.at(i)->getActivatedValue();  // output of the neural network

        // Error for the current output neuron
        errors.at(i) = 0.5 * pow((y - t), 2);
        std::cout << "target = " << t << " and output of NN = " << y << std::endl;
        std::cout << "The error at " << i << " is " << errors.at(i) << std::endl;

        // Derivative of the error for backpropagation
        derivedErrors.at(i) = y - t;
        std::cout << "The derived error at " << i << " is " << derivedErrors.at(i) << std::endl;

        // Summing the squared errors
        this->error += derivedErrors.at(i);
    }

}
void NN::setErrorsMSE() {
    int outputLayerIndex = this->layers.size() - 1;
    vector<Neuron*> outputNeurons = this->layers.at(outputLayerIndex)->getNeurons();

    this->error = 0.0f;

    // Total number of output neurons, used for the MSE calculation
    int numOutputs = target.size();

    for (int i = 0; i < numOutputs; i++) {
        double t = target.at(i);  // target value
        double y = outputNeurons.at(i)->getActivatedValue();  // output of the neural network

        // Error for the current output neuron
        errors.at(i) = 0.5 * pow((y - t), 2);
        std::cout << "target = " << t << " and output of NN = " << y << std::endl;
        std::cout << "The error at " << i << " is " << errors.at(i) << std::endl;

        // Derivative of the error for backpropagation
        derivedErrors.at(i) = y - t;
        std::cout << "The derived error at " << i << " is " << derivedErrors.at(i) << std::endl;

        // Summing the squared errors
        this->error += errors.at(i);
    }

}

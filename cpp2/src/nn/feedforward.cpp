#include "../../include/nn.hpp"
#include "../../include/utils/math.hpp"

void NN::feedForward() {
    Matrix *a; // Matrix of neurons to the left
    Matrix *b; // Matrix of weights to the right of the layer
    Matrix *e; // Matrix of the biases
    Matrix *c; // Matrix of neurons to the right

    for (int i = 0; i < (this->topologySize - 1); i++) {
        a = this->getNeuronMatrix(i);
        b = this->getWeightMatrix(i);
	e = this->getBiasMatrix(i);
        c = new Matrix(
            a->getNumRows(),
            b->getNumCols(),
            false
        );

        if (i != 0) {
            a = this->getActivatedNeuronMatrix(i);
        }

        utils::Math::multiplyMatrix(a, b, c);
	utils::Math::addMatrix(c,e,c);

        for (int c_index = 0; c_index < c->getNumCols(); c_index++) {
            this->setNeuronValue(i + 1, c_index, c->getValue(0, c_index));
        }

    delete a;
    delete b;
    delete c;
    }
}

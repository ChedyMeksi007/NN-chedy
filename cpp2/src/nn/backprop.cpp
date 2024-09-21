#include "../../include/nn.hpp"
#include "../../include/utils/math.hpp"
#include <algorithm>
#include <vector>

void NN::backPropagation() {
    vector<Matrix*> newWeights;
    Matrix* deltaWeights;
    Matrix* gradients;
    Matrix* derivedValues;
    Matrix* gradientsTransposed;
    Matrix* zActivatedVals;
    Matrix* tempNewWeights;
    Matrix* pGradients;
    Matrix* transposePWeights;
    Matrix* hiddenDerived;
    Matrix* transposeHidden;

    if (this->velocities.empty()) {
        for (int i = 0; i < this->weightMatrices.size(); ++i) {
            this->velocities.push_back(new Matrix(
                this->weightMatrices[i]->getNumRows(),
                this->weightMatrices[i]->getNumCols(),
                false  
            ));
        }
    }

    int indexOutputLayer = this->topology.size() - 1;


    gradients = new Matrix(1, this->topology.at(indexOutputLayer), false);
    derivedValues = this->layers.at(indexOutputLayer)->matrixifyDerivedVals();

    for (int i = 0; i < this->topology.at(indexOutputLayer); i++) {
        double e = this->derivedErrors.at(i);
        double y = derivedValues->getValue(0, i);
        double g = e * y * (1 - y); 
        gradients->setValue(0, i, g);
    }

    gradientsTransposed = gradients->transpose();
    zActivatedVals = this->layers.at(indexOutputLayer - 1)->matrixifyActivatedVals();

    deltaWeights = new Matrix(
        gradientsTransposed->getNumRows(),
        zActivatedVals->getNumCols(),
        false
    );
    utils::Math::multiplyMatrix(gradientsTransposed, zActivatedVals, deltaWeights);

    tempNewWeights = new Matrix(
        this->topology.at(indexOutputLayer - 1),
        this->topology.at(indexOutputLayer),
        false
    );

    for (int r = 0; r < this->topology.at(indexOutputLayer - 1); r++) {
        for (int c = 0; c < this->topology.at(indexOutputLayer); c++) {
            double originalValue = this->weightMatrices.at(indexOutputLayer - 1)->getValue(r, c);
            double deltaValue = deltaWeights->getValue(c, r);
 
            double velocity = this->momentum * this->velocities.at(indexOutputLayer - 1)->getValue(r, c) +
                              this->learningRate * deltaValue;
            this->velocities.at(indexOutputLayer - 1)->setValue(r, c, velocity);
            tempNewWeights->setValue(r, c, originalValue - velocity);
        }
    }

    newWeights.push_back(new Matrix(*tempNewWeights));

    delete gradientsTransposed;
    delete zActivatedVals;
    delete tempNewWeights;
    delete derivedValues;
    delete deltaWeights;


    for (int i = indexOutputLayer - 1; i > 0; i--) {
        pGradients = new Matrix(*gradients);

        delete gradients;
        transposePWeights = this->weightMatrices.at(i)->transpose();
        gradients = new Matrix(
            pGradients->getNumRows(),
            transposePWeights->getNumCols(),
            false
        );

        utils::Math::multiplyMatrix(pGradients, transposePWeights, gradients);

        hiddenDerived = this->layers.at(i)->matrixifyDerivedVals();

        for (int colCounter = 0; colCounter < hiddenDerived->getNumRows(); colCounter++) {
            double g = gradients->getValue(0, colCounter) * hiddenDerived->getValue(0, colCounter);
            gradients->setValue(0, colCounter, g);
        }

        if (i == 1) {
            zActivatedVals = this->layers.at(0)->matrixifyVals();
        } else {
            zActivatedVals = this->layers.at(i - 1)->matrixifyActivatedVals();  
        }

        transposeHidden = zActivatedVals->transpose();
        deltaWeights = new Matrix(
            transposeHidden->getNumRows(),
            gradients->getNumCols(),
            false
        );
        utils::Math::multiplyMatrix(transposeHidden, gradients, deltaWeights);

        tempNewWeights = new Matrix(
            this->weightMatrices.at(i - 1)->getNumRows(),
            this->weightMatrices.at(i - 1)->getNumCols(),
            false
        );

        for (int r = 0; r < tempNewWeights->getNumRows(); r++) {
            for (int c = 0; c < tempNewWeights->getNumCols(); c++) {
                double originalValue = this->weightMatrices.at(i - 1)->getValue(r, c);
                double deltaValue = deltaWeights->getValue(r, c);
   
                double velocity = this->momentum * this->velocities.at(i - 1)->getValue(r, c) +
                                  this->learningRate * deltaValue;
                this->velocities.at(i - 1)->setValue(r, c, velocity);
        
                tempNewWeights->setValue(r, c, originalValue - velocity);
            }
        }

        newWeights.push_back(new Matrix(*tempNewWeights));

        delete pGradients;
        delete transposePWeights;
        delete hiddenDerived;
        delete zActivatedVals;
        delete transposeHidden;
        delete tempNewWeights;
        delete deltaWeights;
    }

    for (int i = 0; i < this->weightMatrices.size(); i++) {
        delete this->weightMatrices[i];
    }
    this->weightMatrices.clear();

    reverse(newWeights.begin(), newWeights.end());

    for (int i = 0; i < newWeights.size(); i++) {
        this->weightMatrices.push_back(new Matrix(*newWeights[i]));
        delete newWeights[i];
    }
}


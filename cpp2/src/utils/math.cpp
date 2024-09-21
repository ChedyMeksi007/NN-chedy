#include "../../include/utils/math.hpp"
#include <cstdlib>

void utils::Math::multiplyMatrix(Matrix* a, Matrix* b, Matrix* c) {
       if (a->getNumCols() != b->getNumRows() ||
           c->getNumRows() != a->getNumRows() ||
           c->getNumCols() != b->getNumCols()) {
           throw std::invalid_argument("Incompatible matrix dimensions for multiplication");
       }

       for (int i = 0; i < a->getNumRows(); i++) {
           for (int j = 0; j < b->getNumCols(); j++) {
               c->setValue(i, j, 0);  // Initialize the result to 0
               for (int k = 0; k < a->getNumCols(); k++) {
                   double p = a->getValue(i, k) * b->getValue(k, j);
                   c->setValue(i, j, c->getValue(i, j) + p);
               }
           }
       }
   }

void utils::Math::addMatrix(Matrix* a, Matrix* b, Matrix* c) {
    if (a->getNumRows() != b->getNumRows() || a->getNumCols() != b->getNumCols() ||
        c->getNumRows() != a->getNumRows() || c->getNumCols() != a->getNumCols()) {
        throw std::invalid_argument("Matrix addition not possible due to different dimensions");
    }

    for (int row = 0; row < a->getNumRows(); row++) {
        for (int col = 0; col < a->getNumCols(); col++) {
            double newValue = a->getValue(row, col) + b->getValue(row, col);
            c->setValue(row, col, newValue);
        }
    }
}

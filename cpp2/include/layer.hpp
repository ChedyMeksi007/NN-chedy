#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include <iostream>
#include <vector>
#include "neuron.hpp"
#include "matrix.hpp"

/**
 * @class Layer
 * @brief Represents a single Layer in a Neural Network
 */
class Layer
{
	public:
		/**
		 * @brief Constructs a Layer in the Neural Network with a specific size
		 * @param size The Size of the Layer
		 */
		Layer(int size);

		/**
		 * @brief Constructs a Layer in the Neural Network with a specific Size and Activation Function Type
		 * @param size The Size of the Layer
		 * @param activationType The Activation Function Type to be used in this Layer
		 */
		Layer(int size, int activationType);

		/**
		 * @brief Sets a specific Neuron Value in the Layer
		 * @param i Index of the Neuron
		 * @param v Value to be set in the specific Neuron
		 */
		void setVal(int i, double v);

		/**
		 *
		 */
		Matrix* matrixifyVals();

		/**
		 *
		 */
		Matrix* matrixifyActivatedVals();

		/**
		 *
		 */
		Matrix* matrixifyDerivedVals();

		/**
		 * @brief Sets the Neurons of this Layer
		 * @param neurons Value to be set in this Layer
		 */
		void setNeurons(vector<Neuron *> neurons){this->neurons = neurons;}

		/**
		 * @brief Gets the Activated Values of The Neurons of this Layer
		 * @return The Activated Values of The Neurons of This Layer
		 */
		vector<double> getActivatedVals();

		/**
		 * @brief Gets the current neurons of this Layer
		 * @return The current Neurons of this Layer
		 */
		vector<Neuron *> getNeurons(){return this->neurons;}

	private:

		int size; ///< The size of the Layer aka number of Neurons.
		vector<Neuron *> neurons; ///< The Neurons of this Layer.
};

#endif

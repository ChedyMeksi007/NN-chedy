#ifndef _NN_HPP_
#define _NN_HPP_


#include "neuron.hpp"
#include <vector>
#define COST_MSE 1

#include "matrix.hpp"
#include "json.hpp"
#include "layer.hpp"


using namespace std;

/**
 * @class NN
 * @brief Neural Network Class Implentation
 */
class NN{
	public:
		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/
		NN(
			vector<int> topology,
			double learningRate = 0.05,
			double momentum = 1
		);

		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/
		NN(
			vector<int> topology,
			int hiddenActivationType,
			int outputActivationType,
			int costFunctionType,
			double learningRate = 0.05,
			double momentum = 1
		  );

		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/
		void setCurrentInput(vector<double >input);
		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/
		void setCurrentTarget(vector<double> target) {this->target= target;}

		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/
		void feedForward();
		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/
		void backPropagation();
		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/
		void setErrors();

		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/
		vector<double> getActivatedVals(int index) {return this->layers.at(index)->getActivatedVals();}

		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/
		Matrix* getNeuronMatrix(int index) {return this->layers.at(index)->matrixifyVals();}


		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/

		Matrix* getActivatedNeuronMatrix(int index) {return this->layers.at(index)->matrixifyActivatedVals();}

		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/
		Matrix* getDerivedNeuronMatrix(int index) {return this->layers.at(index)->matrixifyDerivedVals();}
		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/

		Matrix* getWeightMatrix(int index) {return new Matrix(*this->weightMatrices.at(index));}
		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/

		void setNeuronValue(int indexLayer,int indexNeuron, double v) {this->layers.at(indexLayer)->setVal(indexNeuron,v);}

		void train(vector<double>input, vector<double>target,double learningRate,double momentum);

		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/

		Matrix* getBiasMatrix(int index) {return new Matrix(*this->biasMatrices.at(index));}
		void saveWeights(string filename);
		void loadWeights(string filename);

		int topologySize;
		int hiddenActivationType = RELU;
		int outputActivationType = SIGM;
		int costFunctionType = COST_MSE;

		vector<int> topology;
		vector<Layer *> layers;
		vector<Matrix *> weightMatrices;
		vector<Matrix *> biasMatrices;
		vector<Matrix *> gradientMatrices;
		vector<Matrix*> velocities;

		vector<double> input;
		vector<double> target;
		vector<double> errors;
		vector<double> derivedErrors;


		double error = 0;
		double momentum;
		double learningRate;

	private:
		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/
		void setErrorsMSE();
};
#endif

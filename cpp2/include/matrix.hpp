#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

/**
 * @class Matrix
 * @brief Represents a two dimensional Matrix.
 */
class Matrix
{
	public:
		/**
	 	* @brief Constructs a Matrix with a specified number of Rows and Columns and randomized values or not.
	 	* @param numRows number of Rows.
	 	* @param numCols number of Columns.
	 	* @param isRandom if the matrix values should be random or not.
	 	*/
		Matrix(int numRows,int numCols,bool isRandom);

		/**
	 	* @brief transposes the Matrix.
	 	*/
		Matrix* transpose();

		/**
	 	* @brief todo.
	 	*/
		Matrix* copy();

		/**
	 	* @brief Sets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	* @param v Matrix cell value.
	 	*/
		void setValue(int r, int c, double v);

		/**
	 	* @brief Gets the Value of the Matrix in a specific Row and Column index.
	 	* @param r Row index.
	 	* @param c Column index.
	 	*/
		double getValue(int r, int c){return this->values.at(r).at(c);}

		/**
	 	* @brief Prints the Matrix to console (useful for debugging).
	 	*/
		void printToConsole();

		vector<vector<double>> getValues(){return this->values;}

		int getNumRows(){return this->numRows;}
		int getNumCols(){return this->numCols;}

	private:
		double generateRandomNumber(); ///< generates random float number.
		int numRows;///< The Number of Rows.
		int numCols;///< The Number of Columns.
		vector<vector<double>> values;///< The Values of The Matrix.
};

#endif

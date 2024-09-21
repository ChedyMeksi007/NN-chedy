#ifndef _MATH_HPP_
#define _MATH_HPP_

#include <iostream>
#include <regex>
#include <vector>
#include <fstream>
#include <sstream>
#include <assert.h>

#include "../matrix.hpp"

using namespace std;
/**
 * @namespace utils
 * @brief Contains utility Functions ....
 */
namespace utils
{
	/**
	 * @class Math
	 * @brief Provides Utility Functions for mathemathical Operations on Matrices
	 */
	class Math
	{
		public:
		       /**
       			* @brief Multiplies two matrices and stores the result in a third matrix.
         		*
			* @param a Pointer to the first input matrix.
         		* @param b Pointer to the second input matrix.
         		* @param c Pointer to the matrix where the result will be stored.
         		*
         		* @note The dimensions of the matrices must be compatible for multiplication.
         		*/
			static void multiplyMatrix(Matrix* a, Matrix* b, Matrix* c);

			static void addMatrix(Matrix* a, Matrix* b, Matrix* c);
	};
};


#endif

#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#define TANH 1
#define RELU 2
#define SIGM 3

#include <iostream>
#include <math.h>

using namespace std;

/**
 * @class Neuron
 * @brief Represents a single neuron in a neural network.
 */
class Neuron
{
public:
    /**
     * @brief Constructs a Neuron with a specified initial value.
     * @param value The initial value of the neuron.
     */
    Neuron(double value);

    /**
     * @brief Constructs a Neuron with a specified initial value and activation type.
     * @param value The initial value of the neuron.
     * @param activationType The type of activation function to use (TANH, RELU, SIGM).
     */
    Neuron(double value, int activationType);

    /**
     * @brief Sets the value of the neuron.
     * @param value The value to set.
     */
    void setVal(double value);

    /**
     * @brief Activates the neuron using the specified activation function.
     */
    void activate();

    /**
     * @brief Derives the neuron using the specified activation function.
     */
    void derive();

    /**
     * @brief Gets the current value of the neuron.
     * @return The current value of the neuron.
     */
    double getValue() {return this->value;}

    /**
     * @brief Gets the current activated value of the neuron.
     * @return The current activated value of the neuron.
     */
    double getActivatedValue(){return this->activatedValue;}

    /**
     * @brief Gets the current derived value of the neuron.
     * @return The current derived value of the neuron.
     */
    double getDerivedValue() {return this->derivedValue;}

private:
    double value; ///< The input value of the neuron.
    double activatedValue; ///< The value after applying the activation function.
    double derivedValue; ///< The derivative value after applying the activation function.
    int activationType = SIGM; ///< The type of activation function (default is SIGM).
};

#endif // _NEURON_HPP_

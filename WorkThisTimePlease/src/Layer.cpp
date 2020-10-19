#include "Layer.h"
#include <iostream>
#include <cmath>
#include <blaze/Math.h>

Layer::Layer(const uint16_t &_size, Layer::ActivationFunction activationFn, Layer &prevLayer)
{
    this->_size = _size;
    this->activationFn = activationFn;

    // Initialize layer neurons
    blaze::DynamicVector<float> neuronLayer;
    neuronLayer.resize(_size);
    this->neuronLayer = neuronLayer;

    // Initialize layer weights
    Layer::initializeWeights(prevLayer._size);
    std::cout << Layer::weightMatrix << std::endl;

    // Initialize bias.
    Layer::initializeBias(_size);
    std::cout << biasVector << std::endl;
}

/*
 * Input layer constructor.
 */
Layer::Layer(const uint16_t &_size, Layer::ActivationFunction activationFn)
{
    this->_size = _size;
    this->activationFn = activationFn;

    blaze::DynamicVector<float> neuronLayer;
    neuronLayer.resize(_size);
    this->neuronLayer = neuronLayer;
}

Layer::~Layer()
{
    //dtor
}

/*
 * Initialize weights.
 */
void Layer::initializeWeights(uint16_t prevSize) {
    weightMatrix = blaze::generate(_size, prevSize, [](size_t i, size_t j){ return blaze::rand<float>(-1, 1); } );
}

/*
 * Initialize bias.
 */
void Layer::initializeBias(uint16_t _size) {
    biasVector = blaze::generate(_size, [](size_t i) {return blaze::rand<float>(-1, 1); } );
}

/*
 * Feed forward.
 */
void Layer::feedForward(Layer &prevLayer) {

    neuronLayer = (weightMatrix * prevLayer.neuronLayer) + biasVector;
    activate();

    std::cout << "-- NEURON LAYER --" << std::endl;
    std::cout << neuronLayer << std::endl;
    // neuronLayer = .yaya.yaya da yada yada

}

/*
 * Apply activation function to layer.
 */
void Layer::activate() {
    switch (activationFn) {
    case Layer::Sigmoid:
        neuronLayer = blaze::map(neuronLayer, []( float elem ) { return 1 / (1 + blaze::exp(-elem)); });
        break;
    case Layer::ReLu:
        neuronLayer = blaze::map(neuronLayer, []( float elem ) { return blaze::max(0, elem); });
        break;
    case Layer::Softmax:
        neuronLayer = blaze::softmax(neuronLayer);
        break;
    default:
        throw "Unsupported activation function";
    }
}

blaze::DynamicVector<float> Layer::activationDerivative() {
    switch (activationFn) {
    case Layer::Sigmoid:
        return blaze::map(neuronLayer, []( float elem ) {
                            float exp = blaze::exp(-elem);
                            return exp / blaze::pow2(1 + exp);
                          });

    case Layer::ReLu:
        return blaze::map(neuronLayer, []( float elem ) { return elem > 0 ? 1 : 0; });
        break;
    case Layer::Softmax:
        return blaze::softmax(neuronLayer); // TODO
        break;
    default:
        throw "Unsupported activation function";
    }
}

//ostream &operator<<(ostream &os, const Layer &layer) {

//    os << layer.weightLayer.
//    return os; // LOL.
//}



#include "NeuralNetwork.h"
#include "Layer.h"
#include <iostream>
#include <cmath>
#include <blaze/Math.h>

NeuralNetwork::NeuralNetwork(const float &learningRate) {
    this->learningRate = learningRate;
}

NeuralNetwork::~NeuralNetwork() {
    for (const auto layer : layers) {
        delete layer;
    }
}

/*
 * Add layer.
 */
void NeuralNetwork::addLayer(const uint16_t &_size, Layer::ActivationFunction activationFn) {
    std::cout << layers.size() << std::endl;
    if (layers.size() == 0) { // Input layer.
        Layer* layer = new Layer(_size, activationFn);
        layers.push_back(layer);
        return;
    }

    Layer* layer = new Layer(_size, activationFn, *layers[layers.size()-1]);
    layers.push_back(layer);
}

void NeuralNetwork::setInputs(blaze::DynamicVector<float> inputVec) {
    layers[0]->neuronLayer = inputVec;
}

/*
 * Feed forward.
 */
void NeuralNetwork::feedForward() {
    layers[0]->activate();
    for (uint16_t i = 1; i < layers.size(); i++) {
        layers[i]->feedForward(*layers[i-1]);
    }
 }

float NeuralNetwork::loss() {
    // expected value, estimated value, yada yada yada
}

std::ostream &operator<<(std::ostream &os, const NeuralNetwork &neuralNetwork) {

    os << std::endl;
    for (int i = 0; i < neuralNetwork.layers.size(); ++i) {
        os << "===== LAYER " << i << " =====" << std::endl;
        neuralNetwork.layers[i]->print();
    }
    os << std::endl;

    return os;
}

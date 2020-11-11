#include <blaze/Math.h>
#include <iostream>
#include "NeuralNetwork.h"

int main()
{
    NeuralNetwork* test = new NeuralNetwork(0.05f);

    test->addLayer(1, Layer::ActivationFunction::ReLu); // Input layer.
    test->addLayer(3, Layer::ActivationFunction::Sigmoid); // Hidden 1.
    test->addLayer(2, Layer::ActivationFunction::Softmax); // Hidden 1.


    blaze::DynamicVector<float> inputVector {69};
    test->setInputs(inputVector);
    test->feedForward();

    std::cout << *test;
    // Dataset loader

    // create NN layers (dimensions, activation functions etc)
    // load input vector
    // input Vector = loaded input

    // train neural net
    // - feed forward, evaluate cost, back propagate
    // test neural net

    // graph performance?


    delete test;

    std::cout << "It's all good!!!" << std::endl;
}

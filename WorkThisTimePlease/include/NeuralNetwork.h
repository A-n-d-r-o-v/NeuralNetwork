#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include <blaze/Math.h>
#include "NeuralNetwork.h"
#include "Layer.h"

class NeuralNetwork
{
    public:
        NeuralNetwork(const float &learningRate); // TODO convert to static vector?
        virtual ~NeuralNetwork();
        void addLayer(const uint16_t &_size, Layer::ActivationFunction activationFn);
        void feedForward();
        float NeuralNetwork::loss();

    protected:

    private:
        float learningRate;
        std::vector<Layer*> layers;

};


#endif // NEURALNETWORK_H

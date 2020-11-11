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
        void setInputs(blaze::DynamicVector<float> inputVec);
        void feedForward();
        float loss();
        std::vector<Layer*> layers;
        std::ostream& operator << (std::ostream &os, const NeuralNetwork& neuralNetwork);

    protected:

    private:
        float learningRate;

};


#endif // NEURALNETWORK_H

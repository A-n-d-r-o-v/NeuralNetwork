#ifndef LAYER_H
#define LAYER_H
#include <blaze/Math.h>
#include "Layer.h"


class Layer
{
    public:
        enum ActivationFunction { Sigmoid, ReLu, Softmax };
        Layer(const uint16_t &_size, Layer::ActivationFunction activationFn, Layer &prevLayer);
        Layer(const uint16_t &_size, Layer::ActivationFunction activationFn);
        virtual ~Layer();
        blaze::DynamicVector<float> neuronLayer;
        blaze::DynamicVector<float> biasVector;
        blaze::DynamicMatrix<float> weightMatrix;
        void feedForward(Layer &prevLayer);
        void activate();
        blaze::DynamicVector<float> activationDerivative();
        void print();

    protected:

    private:
        uint16_t _size;
        void initializeWeights(uint16_t prevSize);
        void initializeBias(uint16_t _size);
        ActivationFunction activationFn;

};

#endif // LAYER_H

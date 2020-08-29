#include "Neuron.h"

namespace BearAI
{

	// Neuron definition
	neuron::neuron() { value = 0.0; }
	neuron::neuron(double val) { value = val; }
	neuron::~neuron() {}

	// Smart neuron definition
	smart_neuron::smart_neuron() { value = 0.0; bias = 0.0; }
	smart_neuron::smart_neuron(double val) { value = val; bias = 0.0; }
	smart_neuron::smart_neuron(N_Function _fn) { fn = _fn; bias = 0.0; }
	smart_neuron::smart_neuron(double val, N_Function _fn) { value = val; fn = _fn; bias = 0.0; }
	smart_neuron::~smart_neuron() {}
	void smart_neuron::operator=(double val) { value = fn(val); }


	// Activation function definitions

	// Sigmoid function def
	N_Function _Sigmoid = [&](double v) {
		return (1 / (1 + std::exp(0 - v)));
	};

	// Scaled sigmoid function def
	N_Function _S_Sigmoid = [&](double v) {
		return 2 * _Sigmoid(2 * v) - 1;
		// Same as " return std::tanh(v); ", feel free to replace
	};

	// Softplus function def
	N_Function _Softplus = [&](double v) {
		return std::log(1 + std::exp(v));
	};

	// ReLU function def
	N_Function _ReLU = [&](double v) {
		if (v < 0) { return 0.0; }
		else { return v; }
	};

	// Binary step function def
	N_Function _BinStep = [&](double v) {
		if (v < 0) { return 0.0; }
		else { return 1.0; }
	};

	// Tangent inverse function def
	N_Function _ATan = [&](double v) {
		return std::atan(v);
	};

	// Softsign function def
	N_Function _Softsign = [&](double v) {
		return v / (1 + std::abs(v));
	};

	// Sigmoid LU function def
	N_Function _SiLU = [&](double v) {
		return v / (1 + std::exp(0 - v));
	};





}


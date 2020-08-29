
#include "Network.h"


namespace BearAI
{

	void weight::Go() { second->value += first->value * s; }
	void weight::operator=(double v) { s = v; }

	void layer::SetFunctions(N_Function _fn) {
		for (smart_neuron& n : neurons) {
			n.fn = _fn;
		}
	}
	

	NeuralNetwork::NeuralNetwork() {}
	NeuralNetwork::~NeuralNetwork(){}
	void NeuralNetwork::SetSize(std::size_t nLayers, std::vector <std::size_t> sLayers)
	{
		if (nLayers == sLayers.size()) {
			layers.resize(nLayers - 1);
			index i = 0;
			for (std::size_t s : sLayers)
			{
				if (i == 0) { inLayer.neurons.resize(s); }
				else { layers[i - 1].neurons.resize(s); }
				i++;
			}
		}
	}
	void NeuralNetwork::SetWeights() 
	{
		weights.resize(layers.size());
		for (index i = 0; i < weights.size(); i++) {
			if (i != 0) {
				weights[i].resize(layers[i - 1].neurons.size());
			}
			else {
				weights[i].resize(inLayer.neurons.size());
			}
			for (index j = 0; j < weights[i].size(); j++) {
				weights[i][j].resize(layers[i].neurons.size());
				for (index k = 0; k < weights[i][j].size(); k++) {
					if (i != 0) {
						weights[i][j][k].first = &layers[i - 1].neurons[j];
					}
					else {
						weights[i][j][k].first = &inLayer.neurons[j];
					}
					weights[i][j][k].second = &layers[i].neurons[k];
					weights[i][j][k].s = 1.0;
				}
			}
		}

	}

	std::vector <layer>& NeuralNetwork::Layers() { return layers; }
	smart_neuron& NeuralNetwork::Neuron(index layer, index neuron) 
		{ return layers[layer].neurons[neuron]; }
	layer& NeuralNetwork::Layer(index layer) 
		{ return layers[layer - 1]; }
	double& NeuralNetwork::Value(index layer, index neuron) 
		{ return Neuron(layer, neuron).value; }
	void NeuralNetwork::FeedInput(basic_layer _layer) 
		{ inLayer = _layer; }
	basic_layer& NeuralNetwork::InputLayer() { return inLayer; }
	layer NeuralNetwork::Activate() {
		for (auto& c : weights) {
			for (auto& b : c) {
				for (weight& w : b) {
					w.Go();
				}
			}
		}
		for (layer& l : layers) {
			for (smart_neuron& sn : l.neurons) {
				sn.value = sn.fn(sn.value + sn.bias);
			}
		}
		return layers[layers.size() - 1];
	}
	weight& NeuralNetwork::Weight(index firstlayer, index neuron, index weight)
		{ return weights[firstlayer][neuron][weight];}
	smart_neuron& NeuralNetwork::operator()(index layer, index neuron) { return Neuron(layer, neuron); }
	layer& NeuralNetwork::operator[](index layer) { return Layer(layer); }
	weight& NeuralNetwork::operator()(index firstlayer, index neuron, index weight)
		{ return Weight(firstlayer, neuron, weight); }

	void NeuralNetwork::Clear() {
		for (neuron& n : inLayer.neurons) {
			n.value = 0.0;
		}
		for (layer& l : layers) {
			for (smart_neuron& sn : l.neurons) {
				sn.value = 0.0;
			}
		}
	}


	neuron Greatest(layer l) {
		neuron theory;
		theory.value = -1e100;
		for (neuron& n : l.neurons) {
			if (n.value > theory.value) { theory = n; }
			else { continue; }
		}
		return theory;
	}

	neuron Greatest(basic_layer bl) {
		neuron theory;
		theory.value = -1e100;
		for (neuron& n : bl.neurons) {
			if (n.value > theory.value) { theory = n; }
			else { continue; }
		}
		return theory;
	}


}
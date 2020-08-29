#pragma once

#ifndef BEAR_AI_STD_NETWORK_H_HEADER__
#define BEAR_AI_STD_NETWORK_H_HEADER__


#include "Neuron.h"

#define BEARLAS_ALL
#include "BearLAS.h"

namespace BearAI
{

	using namespace BearLas;

	typedef unsigned int index;


	struct weight
	{
		void Go();
		void operator=(double v);
		double s;
		neuron* first;
		smart_neuron* second;
	};


	struct basic_layer
	{
		std::vector <neuron> neurons;
	};

	struct layer
	{
		std::vector <smart_neuron> neurons;
		void SetFunctions(N_Function _fn);
	};



	class NeuralNetwork
	{
	public:
		NeuralNetwork();
		~NeuralNetwork();

		void SetSize(std::size_t nLayers, std::vector <std::size_t> sLayers);
		void SetWeights();

		std::vector <layer>& Layers();
		smart_neuron& Neuron(index layer, index neuron);
		layer& Layer(index layer);
		double& Value(index layer, index neuron);
		weight& Weight(index firstlayer, index neuron, index weight);
		void FeedInput(basic_layer _inlayer);
		basic_layer& InputLayer();
		layer Activate();

		smart_neuron& operator()(index layer, index neuron);
		layer& operator[](index layer);
		weight& operator()(index firstlayer, index neuron, index weight);

		void Clear();

	private:
		std::vector <layer> layers;
		basic_layer inLayer;
		std::vector <std::vector<std::vector<weight>>> weights;
	};



	neuron Greatest(layer l);

	neuron Greatest(basic_layer bl);

	


	class SmartNeuralNetwork
	{
	public:
		SmartNeuralNetwork();
		~SmartNeuralNetwork();

		void SetSize(std::size_t nLayers, std::vector <std::size_t> sLayers);
		void SetWeights();
		void SetWeights(std::vector <Matrix>& _weights);

		std::vector <Vector>& Layers();
		std::vector <Matrix>& Weights();

		Vector& Layer(index ind);
		Matrix& Weight_Layer(index ind);

		double& Neuron(index l, index n);
		Vector& Weight_Group(index l, index n);
		double& Weight(index l, index n, index w);

		N_Function& Function(index layer);

		Vector& Train();
		Vector& Train(Vector exp_out);

		Vector& Test();

	private:
		std::vector <Vector> layers;
		std::vector <Matrix> weights;
		std::vector <Vector> biases;
		std::vector <N_Function> functions;
		
	};








}




#endif // BEAR_AI_STD_NETWORK_H_HEADER__
#pragma once

#ifndef BEAR_AI_STD_NEURON_H_HEADER__
#define BEAR_AI_STD_NEURON_H_HEADER__

#include <iostream>
#include <string>
#include <vector>
#include <strstream>
#include <set>
#include <cmath>
#include <cstdlib>
#include <functional>



namespace BearAI
{

	struct neuron
	{
		neuron();
		neuron(double val);
		~neuron();
		double value;
	};


	template <typename T>
	struct neuron_t
	{
		neuron_t() {}
		neuron_t(T val) { value = val; }
		~neuron_t() {}
		T value;
	};


	// Neuron function typedef
	typedef std::function<double(double)> N_Function;

	// Sigmoid function def
	extern N_Function _Sigmoid;

	// Scaled sigmoid function def
	extern N_Function _S_Sigmoid;

	// Softplus function def
	extern N_Function _Softplus;

	// ReLU function def
	extern N_Function _ReLU;

	// Binary step function def
	extern N_Function _BinStep;

	// Tangent inverse function def
	extern N_Function _ATan;

	// Softsign function def
	extern N_Function _Softsign;

	// Sigmoid LU function def
	extern N_Function _SiLU;

	struct smart_neuron : neuron
	{
		smart_neuron();
		smart_neuron(double val);
		smart_neuron(N_Function _fn);
		smart_neuron(double val, N_Function _fn);
		~smart_neuron();
		void operator= (double val);
		std::function<double(double)> fn;
		double bias;
	};





}



#endif // BEAR_AI_STD_NEURON_H_HEADER__

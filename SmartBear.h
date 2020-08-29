#pragma once

#include "Neuron.h"
#include "Network.h"



namespace BearAI
{

	std::ostream& operator<<(std::ostream& out, layer l);

	std::ostream& operator<<(std::ostream& out, basic_layer l);

	std::ostream& operator<<(std::ostream& out, neuron n);



}
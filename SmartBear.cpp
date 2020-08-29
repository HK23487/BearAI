
// Includes all assets of SmartBear to be exported


#include "SmartBear.h"


namespace BearAI
{

	std::ostream& operator<<(std::ostream& out, layer l) {
		for (neuron n : l.neurons) {
			out << n.value << std::endl;
		}
		return out;
	}

	std::ostream& operator<<(std::ostream& out, basic_layer l) {
		for (neuron n : l.neurons) {
			out << n.value << std::endl;
		}
		return out;
	}

	std::ostream& operator<<(std::ostream& out, neuron n) {
		out << n.value << std::endl;
		return out;
	}




}


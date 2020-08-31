


#include "BearMath.h"


namespace BearMath {


	using namespace BearLas;
	
	double DerivativePoint(double in, DFunction fn) {

		double run = 0.000001;
		double rise = fn(in + run) - fn(in);

		return rise / run;

	}

	Vector Gradient(Vector in, VFunction fn) {

		Vector ret; ret.Fill(in.Length());
		double rn = fn(in);

		for (int i = 0; i < in.Length(); i++) {

			double elem = in[i];
			in[i] = elem + 0.000001;

			double diff = fn(in) - rn;
			ret[i] = diff / 0.000001;

			in[i] = elem;

		}

		return ret;

	}


}



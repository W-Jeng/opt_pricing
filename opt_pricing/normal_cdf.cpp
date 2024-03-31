#include<cmath>
#include "normal_cdf.h"

double normal_cdf(double x) {
	return 0.5 * (1 + std::erf(x / std::sqrt(2)));
}

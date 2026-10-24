#include "Benchmarks.h"
#include <cmath>
double sphere(const std::vector<double>& x){double s=0;for(double v:x)s+=v*v;return s;}
double rastrigin(const std::vector<double>& x){double pi=std::acos(-1.0),r=10.0*x.size();for(double v:x)r+=v*v-10.0*std::cos(2*pi*v);return r;}

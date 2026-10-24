#pragma once
#include "WifiProblem.h"
#include <vector>
struct KMeansResult { std::vector<double> centers; double fitness=0.0; double runtimeMs=0.0; int iterations=0; };
KMeansResult runKMeans(const std::vector<User>& users,int k,unsigned int seed,int maxIterations=100);

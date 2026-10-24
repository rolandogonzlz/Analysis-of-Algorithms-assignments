#pragma once
#include <functional>
#include <string>
#include <vector>
struct Particle { std::vector<double> position, velocity, bestPosition; double fitness=0.0, bestFitness=0.0; };
struct PSOResult { std::vector<double> bestPosition; double bestFitness=0.0; double runtimeMs=0.0; };
class PSO {
public:
 PSO(int numParticles,int dimensions,int maxIterations,double inertiaWeight,double cognitiveCoefficient,double socialCoefficient,double lowerBound,double upperBound,unsigned int seed);
 PSOResult optimize(const std::function<double(const std::vector<double>&)>& objectiveFunction,const std::string& convergenceCsvFile);
private:
 int numParticles_, dimensions_, maxIterations_; double w_, c1_, c2_, lowerBound_, upperBound_; unsigned int seed_;
};

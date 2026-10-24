#include "PSO.h"
#include <chrono>
#include <fstream>
#include <limits>
#include <random>
#include <stdexcept>
PSO::PSO(int n,int d,int it,double w,double c1,double c2,double lo,double hi,unsigned int seed):
numParticles_(n),dimensions_(d),maxIterations_(it),w_(w),c1_(c1),c2_(c2),lowerBound_(lo),upperBound_(hi),seed_(seed){}
PSOResult PSO::optimize(const std::function<double(const std::vector<double>&)>& f,
const std::string& csvfile){
 std::mt19937 gen(seed_); 
 std::uniform_real_distribution<double> pos(lowerBound_,upperBound_), rnd(0.0,1.0); 
 double vlim=(upperBound_-lowerBound_)*0.10; 
 std::uniform_real_distribution<double> vel(-vlim,vlim);
 std::ofstream csv; if(!csvfile.empty()){csv.open(csvfile); 
    if(!csv.is_open()) throw std::runtime_error("Could not open CSV"); 
    csv<<"iteration,best_fitness\n";}
 auto start=std::chrono::high_resolution_clock::now(); 
 std::vector<Particle> swarm(numParticles_); 
 std::vector<double> gpos(dimensions_,0.0); 
 double gfit=std::numeric_limits<double>::infinity();
 for(auto &p:swarm){p.position.resize(dimensions_);p.velocity.resize(dimensions_);p.bestPosition.resize(dimensions_);
    for(int d=0;d<dimensions_;++d){p.position[d]=pos(gen);p.velocity[d]=vel(gen);}p.fitness=f(p.position);p.bestPosition=p.position;p.bestFitness=p.fitness;
    if(p.bestFitness<gfit){gfit=p.bestFitness;gpos=p.bestPosition;}}
 if(csv)csv<<0<<","<<gfit<<"\n";
 for(int t=1;t<=maxIterations_;++t){
    for(auto &p:swarm){
        for(int d=0;d<dimensions_;++d){
            double r1=rnd(gen),r2=rnd(gen);
            double inertia=w_*p.velocity[d];
            double cog=c1_*r1*(p.bestPosition[d]-p.position[d]);
            double soc=c2_*r2*(gpos[d]-p.position[d]);
            p.velocity[d]=inertia+cog+soc;p.position[d]+=p.velocity[d];
            if(p.position[d]<lowerBound_){
                p.position[d]=lowerBound_;
                p.velocity[d]=0;}else if(p.position[d]>upperBound_){
                    p.position[d]=upperBound_;p.velocity[d]=0;}}
 p.fitness=f(p.position);
 if(p.fitness<p.bestFitness){
    p.bestFitness=p.fitness;p.bestPosition=p.position;}
    if(p.bestFitness<gfit){gfit=p.bestFitness;gpos=p.bestPosition;}}
 if(csv)csv<<t<<","<<gfit<<"\n";}
 auto end=std::chrono::high_resolution_clock::now(); 
 double ms=std::chrono::duration<double,std::milli>(end-start).count(); 
 return {gpos,gfit,ms};
}

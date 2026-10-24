#include "PSO.h"
#include "WifiProblem.h"
#include "KMeans.h"
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

static double mean(const std::vector<double>& v){ 
    return std::accumulate(v.begin(),v.end(),0.0)/v.size(); }
static double sd(const std::vector<double>& v){ 
    double m=mean(v),s=0; 
    for(double x:v)s+=(x-m)*(x-m); 
    return std::sqrt(s/(v.size()-1)); }
int main(){
    std::filesystem::create_directories("results");
    auto users=loadUsersCSV("data/wifi_users.csv");
    std::ofstream raw("results/wifi_comparison_runs.csv");
    raw << "seed,pso_fitness,pso_runtime_ms,kmeans_fitness,kmeans_runtime_ms\n";
    std::vector<double> pf,pt,kf,kt;
    for(unsigned seed=1;seed<=30;++seed){
        PSO pso(30,4,200,0.7,1.5,1.5,0.0,100.0,seed);
        auto objective=[&users](const std::vector<double>& p){
            return wifiFitness(p,users);};
        auto pr=pso.optimize(objective,""); 
        auto kr=runKMeans(users,2,seed,100);
        pf.push_back(pr.bestFitness);
        pt.push_back(pr.runtimeMs);
        kf.push_back(kr.fitness);
        kt.push_back(kr.runtimeMs);
        raw<<seed<<','<<pr.bestFitness<<','<<pr.runtimeMs<<','<<kr.fitness<<','<<kr.runtimeMs<<'\n';
    }
    std::cout<<std::fixed<<std::setprecision(6)
             <<"PSO mean fitness: "<<mean(pf)<<"  sd: "<<sd(pf)<<"  mean runtime: "<<mean(pt)<<" ms\n"
             <<"K-means mean fitness: "<<mean(kf)<<"  sd: "<<sd(kf)<<"  mean runtime: "<<mean(kt)<<" ms\n";
}

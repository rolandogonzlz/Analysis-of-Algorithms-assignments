#include "PSO.h"
#include "Benchmarks.h"
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

struct Row { std::string experiment, function; double parameter; unsigned seed; double fitness, runtime; };
int main() {
    std::filesystem::create_directories("results");
    std::vector<Row> rows;
    const int D=2, T=200, runs=30; const double c1=1.5,c2=1.5;
    for (int S : {10,30,50}) for (unsigned seed=1; seed<=runs; ++seed) for (int f=0; f<2; ++f) {
        PSO p(S,D,T,0.7,c1,c2,-5.12,5.12,seed);
        auto r=p.optimize(f==0?sphere:rastrigin,"");
        rows.push_back({"swarm_size",f==0?"Sphere":"Rastrigin",(double)S,seed,r.bestFitness,r.runtimeMs});
    }
    for (double w : {0.4,0.7,0.9}) for (unsigned seed=1; seed<=runs; ++seed) for (int f=0; f<2; ++f) {
        PSO p(30,D,T,w,c1,c2,-5.12,5.12,seed);
        auto r=p.optimize(f==0?sphere:rastrigin,"");
        rows.push_back({"inertia",f==0?"Sphere":"Rastrigin",w,seed,r.bestFitness,r.runtimeMs});
    }
    std::ofstream out("results/benchmark_batch.csv");
    out << "experiment,function,parameter,seed,fitness,runtime_ms\n" << std::setprecision(17);
    for (const auto& r:rows) out << r.experiment<<','<<r.function<<','<<r.parameter<<','<<r.seed<<','<<r.fitness<<','<<r.runtime<<'\n';
    std::cout << "Saved results/benchmark_batch.csv\n";
}

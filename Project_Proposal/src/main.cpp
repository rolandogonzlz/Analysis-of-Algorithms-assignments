#include "Benchmarks.h"
#include "PSO.h"
#include <filesystem>
#include <iomanip>
#include <iostream>

void printResult(const std::string& name, const PSOResult& result) {
    std::cout << "\n=== " << name << " ===\n";
    std::cout << std::scientific << std::setprecision(10);
    std::cout << "Best fitness: " << result.bestFitness << "\nBest position: [";
    for (std::size_t i = 0; i < result.bestPosition.size(); ++i) {
        std::cout << result.bestPosition[i] << (i + 1 < result.bestPosition.size() ? ", " : "");
    }
    std::cout << "]\n" << std::fixed << std::setprecision(3)
              << "Runtime: " << result.runtimeMs << " ms\n";
}

int main() {
    std::filesystem::create_directories("results");
    const int particles = 30, dimensions = 2, iterations = 200;
    const double w = 0.7, c1 = 1.5, c2 = 1.5;
    const unsigned seed = 42;

    PSO psoSphere(particles, dimensions, iterations, w, c1, c2, -5.12, 5.12, seed);
    auto sphereResult = psoSphere.optimize(sphere, "results/sphere_convergence.csv");
    printResult("PSO - Sphere benchmark", sphereResult);

    PSO psoRastrigin(particles, dimensions, iterations, w, c1, c2, -5.12, 5.12, seed);
    auto rastriginResult = psoRastrigin.optimize(rastrigin, "results/rastrigin_convergence.csv");
    printResult("PSO - Rastrigin benchmark", rastriginResult);
    return 0;
}

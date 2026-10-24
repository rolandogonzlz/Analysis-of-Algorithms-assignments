#include "PSO.h"
#include "WifiProblem.h"
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>

static void saveAPs(const std::vector<double>& p, const std::string& filename) {
    std::ofstream out(filename);
    out << "ap,x,y\n";
    for (std::size_t i = 0; i < p.size(); i += 2)
        out << (i / 2 + 1) << ',' << p[i] << ',' << p[i + 1] << '\n';
}

int main() {
    std::filesystem::create_directories("results");
    auto users = loadUsersCSV("data/wifi_users.csv");
    const int numberOfAPs = 2;
    PSO pso(30, 2 * numberOfAPs, 200, 0.7, 1.5, 1.5, 0.0, 100.0, 42);
    auto objective = [&users](const std::vector<double>& p) { return wifiFitness(p, users); };
    auto result = pso.optimize(objective, "results/wifi_pso_convergence.csv");
    saveAPs(result.bestPosition, "results/wifi_pso_access_points.csv");

    std::cout << "=== Wi-Fi Access Point Placement ===\n"
              << "Users: " << users.size() << "\nAccess points: " << numberOfAPs << "\n"
              << "Particles: 30\nIterations: 200\n\n"
              << std::fixed << std::setprecision(4)
              << "Average user-to-AP distance: " << result.bestFitness << " meters\n"
              << "Runtime: " << result.runtimeMs << " ms\n\nBest AP positions:\n";
    for (int ap = 0; ap < numberOfAPs; ++ap)
        std::cout << "AP " << ap + 1 << ": (" << result.bestPosition[2*ap] << ", " << result.bestPosition[2*ap+1] << ")\n";
}

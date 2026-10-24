CXX=g++
CXXFLAGS=-std=c++17 -O2 -Wall -Wextra -Iinclude
COMMON=src/PSO.cpp src/Benchmarks.cpp src/WifiProblem.cpp src/KMeans.cpp

all: pso wifi_pso batch_bench compare_wifi

pso: src/main.cpp $(COMMON)
	$(CXX) $(CXXFLAGS) src/main.cpp src/PSO.cpp src/Benchmarks.cpp -o pso

wifi_pso: src/wifi_main.cpp $(COMMON)
	$(CXX) $(CXXFLAGS) src/wifi_main.cpp src/PSO.cpp src/WifiProblem.cpp -o wifi_pso

batch_bench: src/batch_bench.cpp $(COMMON)
	$(CXX) $(CXXFLAGS) src/batch_bench.cpp src/PSO.cpp src/Benchmarks.cpp -o batch_bench

compare_wifi: src/compare_wifi.cpp $(COMMON)
	$(CXX) $(CXXFLAGS) src/compare_wifi.cpp src/PSO.cpp src/WifiProblem.cpp src/KMeans.cpp -o compare_wifi

clean:
	rm -f pso wifi_pso batch_bench compare_wifi

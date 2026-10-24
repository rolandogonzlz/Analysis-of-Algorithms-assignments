#pragma once
#include <string>
#include <vector>
struct User{double x;double y;};
std::vector<User> loadUsersCSV(const std::string& filename);
double wifiFitness(const std::vector<double>& apPositions,const std::vector<User>& users);

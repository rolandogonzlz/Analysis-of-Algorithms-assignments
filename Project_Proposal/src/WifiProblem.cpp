#include "WifiProblem.h"
#include <cmath>
#include <fstream>
#include <limits>
#include <sstream>
#include <stdexcept>
std::vector<User> loadUsersCSV(const std::string& filename){
    std::ifstream in(filename); 
    if(!in) throw std::runtime_error("Cannot open users"); 
    std::string line; 
    std::getline(in,line); 
    std::vector<User> users; 
    while(std::getline(in,line)){ 
        if(line.empty())continue; 
        std::stringstream ss(line); 
        std::string a,b; std::getline(ss,a,','); 
        std::getline(ss,b,','); 
        users.push_back({
            std::stod(a),std::stod(b)});} return users;}
double wifiFitness(const std::vector<double>& p,const std::vector<User>& users){
    double total=0; int k=p.size()/2; 
    for(const auto& u:users){
        double best=std::numeric_limits<double>::infinity(); 
        for(int j=0;j<k;++j){
            double dx=u.x-p[2*j],dy=u.y-p[2*j+1];
            double dist=std::sqrt(dx*dx+dy*dy); 
            if(dist<best)best=dist;} total+=best;} 
            return total/users.size();}

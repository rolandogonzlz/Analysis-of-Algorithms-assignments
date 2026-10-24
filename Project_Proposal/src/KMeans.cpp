#include "KMeans.h"
#include <chrono>
#include <cmath>
#include <limits>
#include <random>
#include <stdexcept>
KMeansResult runKMeans(const std::vector<User>& users,int k,unsigned int seed,int maxIterations){
    if(k<=0||users.size()<(size_t)k)throw std::runtime_error("Invalid k"); 
    auto start=std::chrono::high_resolution_clock::now(); 
    std::mt19937 gen(seed); 
    std::uniform_int_distribution<int> pick(0,(int)users.size()-1); 
    std::vector<double> centers(2*k); 
    std::vector<int> chosen; for(int j=0;j<k;++j){
        int idx; bool dup; do{idx=pick(gen);
            dup=false;
            for(int c:chosen)if(c==idx)dup=true;}while(dup);
            chosen.push_back(idx);centers[2*j]=users[idx].x; 
            centers[2*j+1]=users[idx].y;}
 std::vector<int> labels(users.size(),-1); 
 int iter=0; for(;iter<maxIterations;++iter){
    bool changed=false; 
    for(size_t i=0;i<users.size();++i){
        double best=std::numeric_limits<double>::infinity();
        int bestj=0;for(int j=0;j<k;++j){
            double dx=users[i].x-centers[2*j],dy=users[i].y-centers[2*j+1];
            double d2=dx*dx+dy*dy;if(d2<best){best=d2;bestj=j;}}
            if(labels[i]!=bestj){labels[i]=bestj;changed=true;}}
 std::vector<double> sx(k,0),sy(k,0);
 std::vector<int> count(k,0);
 for(size_t i=0;i<users.size();++i){
    int j=labels[i];sx[j]+=users[i].x;sy[j]+=users[i].y;count[j]++;}
    for(int j=0;j<k;++j){if(count[j]>0){centers[2*j]=sx[j]/count[j];
        centers[2*j+1]=sy[j]/count[j];}} if(!changed){++iter;break;}}
 double fit=wifiFitness(centers,users); 
 auto end=std::chrono::high_resolution_clock::now(); 
 double ms=std::chrono::duration<double,std::milli>(end-start).count(); return {centers,fit,ms,iter};}

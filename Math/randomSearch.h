
#ifndef OPTIMIZATION_BP_RANDOMSEARCH_H
#define OPTIMIZATION_BP_RANDOMSEARCH_H
#include "optimizationMethod.h"
#include <random>
extern std::mt19937 generator;

class randomSearch : public optimizationMethod {
public:
    randomSearch(area* _a, stopCrit* _stop, Function* _f) : optimizationMethod( _a, _stop, _f) {};
    std::vector<double> argMin(std::vector<double> x, int& iterNum) override ;
};


#endif //OPTIMIZATION_BP_RANDOMSEARCH_H

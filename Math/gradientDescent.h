
#ifndef OPTIMIZATION_BP_GRADIENTDESCENT_H
#define OPTIMIZATION_BP_GRADIENTDESCENT_H

#include "area.h"
#include "stopCrit.h"
#include "Function.h"
#include "optimizationMethod.h"

class gradientDescent : public optimizationMethod{
public:
    gradientDescent(area* _a, stopCrit* _stop, Function* _f) : optimizationMethod( _a, _stop, _f) {};
    std::vector<double> argMin(std::vector<double> x, int& iterNum) override ;
};


#endif //OPTIMIZATION_BP_GRADIENTDESCENT_H

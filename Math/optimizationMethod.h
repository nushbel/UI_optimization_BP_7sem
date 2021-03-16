
#ifndef OPTIMIZATION_BP_OPTIMIZATIONMETHOD_H
#define OPTIMIZATION_BP_OPTIMIZATIONMETHOD_H

#include "Function.h"
#include "area.h"
#include "stopCrit.h"

class optimizationMethod {
public:
    area* a;
    stopCrit* stop;
    Function* f;
    double alpha;
    std::vector<double> xPlot;
    std::vector<double> yPlot;
    optimizationMethod(area* _a,stopCrit* _stop, Function* _f);
    virtual std::vector<double> argMin(std::vector<double> x, int& iterNum);

};


#endif //OPTIMIZATION_BP_OPTIMIZATIONMETHOD_H

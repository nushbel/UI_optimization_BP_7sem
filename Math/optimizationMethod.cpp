
#include "optimizationMethod.h"


optimizationMethod::optimizationMethod(area* _a,stopCrit* _stop, Function* _f) {
    a = _a;
    stop = _stop;
    f = _f;
    alpha = 0.1;
    xPlot = {};
    yPlot = {};
}
std::vector<double> optimizationMethod::argMin(std::vector<double> x, int& iterNum){
    std::vector<double> r;
    return r;
}

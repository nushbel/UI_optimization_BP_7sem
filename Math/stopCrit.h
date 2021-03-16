
#ifndef OPTIMIZATION_BP_STOPCRIT_H
#define OPTIMIZATION_BP_STOPCRIT_H

#include <vector>
#include "Function.h"

class stopCrit {
public:
    Function* f;
    stopCrit(Function* _f);
    virtual bool stopCheck(std::vector<double> _x, std::vector<double> _xNext);

};

class stopCritEpsilon : public stopCrit {
public:
    double epsilon = 0.0000001;
    stopCritEpsilon( Function* _f) : stopCrit( _f) {};
    bool stopCheck(std::vector<double> _x, std::vector<double> _xNext) override;
};

#endif //OPTIMIZATION_BP_STOPCRIT_H

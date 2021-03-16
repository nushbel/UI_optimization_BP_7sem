
#include "stopCrit.h"
#include <vector>
#include <iostream>
#include "math.h"

stopCrit::stopCrit( Function* _f)
{
    f = _f;
}

bool stopCrit::stopCheck(std::vector<double> _x, std::vector<double> _xNext)
{
    return false;
}

bool stopCritEpsilon::stopCheck(std::vector<double> _x, std::vector<double> _xNext)
{
    //std::cout << "epsilon = " << epsilon << std::endl;
    if (abs(1 - f->eval(_x)/f->eval(_xNext)) < epsilon)
    {
        return true;
    }
    return false;
}
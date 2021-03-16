//
// Created by UserMB1 on 14/03/2021.
//

#include "area.h"

area::area() : left({0}), right({0}) {}

area::area(std::vector<double> _left, std::vector<double> _right) : left(_left), right(_right) {}

bool area::checkIfInside(std::vector<double> x)
{
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] < left[i] || x[i] > right[i])
        {
            return false;
        }
    }
    return true;
}

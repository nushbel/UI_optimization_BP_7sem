//
// Created by UserMB1 on 14/03/2021.
//

#ifndef OPTIMIZATION_BP_AREA_H
#define OPTIMIZATION_BP_AREA_H

#include <vector>



class area {
public:
    std::vector<double> left;
    std::vector<double> right;
    area();
    area(std::vector<double> _left, std::vector<double> _right);
    bool checkIfInside(std::vector<double> x);

};


#endif //OPTIMIZATION_BP_AREA_H

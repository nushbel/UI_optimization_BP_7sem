//
// Created by UserMB1 on 14/03/2021.
//

#ifndef OPTIMIZATION_BP_FUNCTION_H
#define OPTIMIZATION_BP_FUNCTION_H

#include <vector>

class Function {
    public:
    Function();
    Function(Function& _f);
    virtual double eval(std::vector<double> x);
    virtual std::vector<double> calculateGradient(std::vector<double> x);
    virtual ~Function() {};
};

class Function1: public Function {
public:
    Function1() : Function() {};
    //Function1(Function1& _f) : Function(Function& _f) {};
    double eval(std::vector<double> x) override;
    std::vector<double> calculateGradient(std::vector<double> x) override ;
};



class Function2: public Function {
public:
    Function2() : Function() {};
    //Function1(Function1& _f) : Function(Function& _f) {};
    double eval(std::vector<double> x) override;
    std::vector<double> calculateGradient(std::vector<double> x) override ;
};


class Function3: public Function {
public:
    Function3() : Function() {};
    //Function1(Function1& _f) : Function(Function& _f) {};
    double eval(std::vector<double> x) override;
    std::vector<double> calculateGradient(std::vector<double> x) override ;
};

#endif //OPTIMIZATION_BP_FUNCTION_H

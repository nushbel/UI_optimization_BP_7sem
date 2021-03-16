
#include "Function.h"
#include <iostream>
#include <vector>
#include "math.h"

Function::Function() {};

Function::Function(Function& _f) {};

double Function::eval(std::vector<double> x) {
    return 0;
}
std::vector<double> Function::calculateGradient(std::vector<double> x)
{
    std::vector<double> r;
    return r;
}

double Function1::eval(std::vector<double> x)  {
    return x[0] * x[0] + x[1] * x[1];
}

std::vector<double> Function1::calculateGradient(std::vector<double> x)
{
    std::vector<double> grad = {0, 0};
    grad[0] = 2 * x[0];
    grad[1] = 2 * x[1];
    return grad;
}

double Function2::eval(std::vector<double> x)  {
    return x[1] * x[1] + cos(x[0] + x[1]) + 1;
}

std::vector<double> Function2::calculateGradient(std::vector<double> x)
{
    std::vector<double> grad = {0, 0};
    grad[0] = - sin(x[0] + x[1]);
    grad[1] = 2 * x[1] - sin(x[0] + x[1]);
    return grad;
}

double Function3::eval(std::vector<double> x)  {
    return x[0] * x[0] + x[1] * x[1] + x[2] * x[2];
}

std::vector<double> Function3::calculateGradient(std::vector<double> x)
{
    std::vector<double> grad = {0, 0, 0};
    grad[0] = 2 * x[0];
    grad[1] = 2 * x[1];
    grad[2] = 2 * x[2];
    return grad;
}

#pragma once
#include <cmath>
#include <iostream>
#include <vector>

namespace funcs {
    std::vector<double> cartesianToSpherical(double coords[3]);
    int factorial(unsigned int n); 
    double degreesToRadians(double degrees);
    double radiansToDegrees(double radians);
}

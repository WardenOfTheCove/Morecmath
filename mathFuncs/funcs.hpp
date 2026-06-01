#pragma once
#include <cmath>
#include <iostream>
#include <vector>

namespace funcs {
    std::vector<double> cartesianToSpherical(double coords[3]);
    int factorial(unsigned int n); 
    double degreesToRadians(double degrees);
    double radiansToDegrees(double radians);
    double dotProduct(double vectorA[2], double vectorB[2], size_t sizeA, size_t sizeB);
    double crossProduct(double vectorA[2], double vectorB[2], size_t sizeA, size_t sizeB, double angle);
}

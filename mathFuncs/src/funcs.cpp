#include <iostream>
#include <cmath>
#include <stddef.h>
#include "funcs.hpp"
#define PI 3.141592653589793

int funcs::factorial(unsigned int n) {
    if(n == 0 || n == 1) {
        return 1;
    } else {
        n = n * factorial(n - 1);
    }
    return n;
}

double funcs::degreesToRadians(double degrees) {
    double radians = degrees * (PI/180);
    return radians;
}

double funcs::radiansToDegrees(double radians) {
    double degrees = radians * (180/PI);
    return degrees;
}

double funcs::dotProduct(double vectorA[2], double vectorB[2], size_t sizeA, size_t sizeB) {
    double angle;
    if(sizeA != sizeB || sizeA == 1) {
        return -1;
    } else {
        double dot = (vectorA[0] * vectorB[0]) + (vectorA[1] * vectorB[1]);
        double magA = hypot(vectorA[0], vectorA[1]);
        double magB = hypot(vectorB[0], vectorB[1]);
        angle = acos(dot / (magA * magB));
    }
    return angle;
}

double funcs::crossProduct(double vectorA[2], double vectorB[2], size_t sizeA, size_t sizeB, double angle) {
    double vectorProduct;
    if(sizeA != sizeB || sizeA == 1) {
        return -1;
    } else {
        double magA = hypot(vectorA[0], vectorA[1]);
        double magB = hypot(vectorB[0], vectorB[1]);
        vectorProduct = magA * magB * sin(angle);
    }
    return vectorProduct;
}

std::vector<double> funcs::cartesianToSpherical(double coords[3]) {
    double r = hypot(coords[0], coords[1]);
    double theta = funcs::radiansToDegrees(atan(coords[1] / coords[0]));
    double phi = funcs::radiansToDegrees(asin(r / hypot(r, coords[2])));
    std::vector<double> SphericalCoords = {r, theta, phi};
    return SphericalCoords;
}
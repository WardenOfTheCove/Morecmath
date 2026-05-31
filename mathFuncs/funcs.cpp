#include <iostream>
#include <cmath>
#include "funcs.hpp"
#define PI 3.141592653589793

std::vector<double> funcs::cartesianToSpherical(double coords[3]) {
    double xSquared = coords[0] * coords[0];
    double ySquared = coords[1] * coords[1];
    double zSquared = coords[2] * coords[2];
    double r = hypot(xSquared, ySquared);
    double theta = atan(coords[1] / coords[0]);
    double phi = asin(r / hypot((r*r), zSquared));
    std::vector<double> SphericalCoords = {r, theta, phi};
    return SphericalCoords;
}

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
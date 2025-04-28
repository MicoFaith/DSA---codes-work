#include <iostream>
#include <cmath>

void findQuadraticRoots(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0) {
        double x1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double x2 = (-b - std::sqrt(discriminant)) / (2 * a);
        std::cout << "Roots are real and different: x1 = " << x1 << ", x2 = " << x2 << std::endl;
    } else if (discriminant == 0) {
        double x1 = -b / (2 * a);
        std::cout << "Roots are real and same: x1 = x2 = " << x1 << std::endl;
    } else {
        std::cout << "Roots are complex and different." << std::endl;
    }
}


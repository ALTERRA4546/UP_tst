#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>

class Equation {
public:
    static std::vector<double> solve(double a, double b, double c);
};

std::vector<double> Equation::solve(double a, double b, double c) {
    if (a == 0) {
        throw std::invalid_argument("Coefficient 'a' cannot be zero in a quadratic equation.");
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return {};
    }
    else if (discriminant == 0) {
        double root = -b / (2 * a);
        return { root };
    }
    else {
        double sqrtDiscriminant = std::sqrt(discriminant);
        double root1 = (-b - sqrtDiscriminant) / (2 * a);
        double root2 = (-b + sqrtDiscriminant) / (2 * a);
        return { root1, root2 };
    }
}

int main()
{
    double a, b, c;

    std::cout << "Enter coefficients a, b, and c: ";
    std::cin >> a >> b >> c;

    try {
        std::vector<double> roots = Equation::solve(a, b, c);

        if (roots.empty()) {
            std::cout << "No real roots." << std::endl;
        }
        else if (roots.size() == 1) {
            std::cout << "One root: " << roots[0] << std::endl;
        }
        else {
            std::cout << "Two roots: " << roots[0] << " and " << roots[1] << std::endl;
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

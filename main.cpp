#include "integration_output.h"

#include <cmath>

double g(double x) {
    return std::exp(-x*x);
}

double h(double x) {
    double y = x*(2 - x) + 1e-12;
    y = std::sin(1/y);
    return y*y;
}

int main() {
    integral_csv(g, -5, 5, "g");
    integral_csv(h, 0, 2, "h");
    return 0;
}

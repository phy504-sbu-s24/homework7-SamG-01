#include <functional>
#include <random>

/// @brief Integrates f(x) over [a, b] using the trapezoid rule.
/// @param f the function to be integrated.
/// @param a the lower integration bound.
/// @param b the upper integration bound.
/// @param N the number of slabs to divide [a, b] into.
double trapezoid(std::function<double(double)> f, double a, double b, int N) {
    double I = 0;
    double dx = (b - a)/N;

    for (int i = 0; i < N; i++) {
        I += f(a + i*dx) + f(a + (i + 1)*dx);
    }

    return I * dx/2;
}

/// @brief Integrates f(x) over [a, b] using Monte Carlo integration.
/// @param f the function to be integrated.
/// @param a the lower integration bound.
/// @param b the upper integration bound.
/// @param N the number of points to randomly sample.
/// @param gen the random number generator to use.
double monte_carlo(std::function<double(double)> f, double a, double b, int N, std::mt19937 gen) {
    double I = 0;
    std::uniform_real_distribution<> dis(a, b);

    for (int i = 0; i < N; i++) {
        I += f(dis(gen));
    }
    
    return I * (b - a)/N;
}

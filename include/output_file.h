#include "integrate.h"

#include <fstream>

/// @brief Numerically integrates f(x) over [a, b] with varying precision and outputs the results to a csv.
/// @param filename the name of the csv to output to.
/// @param f the function to integrate.
/// @param a the lower integration bound.
/// @param b the upper integration bound.
void integral_csv(std::function<double(double)> f, double a, double b, std::string filename) {
    // set seed for replicability purposes
    std::mt19937 gen(0);
    
    // open csv file
    std::ofstream csv;
    csv.open("../data/" + filename + ".csv");

    // column labels
    csv << "N,trapezoid,monte carlo";

    // integration loop
    for (int N = 8; N <= 1024; N *= 2) {
        csv << "\n" << N << ",";
        csv << trapezoid(f, a, b, N) << ",";
        csv << monte_carlo(f, a, b, N, gen);
    }
    csv.close();
}

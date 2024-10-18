#include <iostream>
#include <cmath>
#include <vector>

int main() {
    // Define the range and step for X
    double start = -2.0;
    double end = 2.0;
    double step = 0.2;

    // Initialize an empty vector to store Y values
    std::vector<double> y_values;

    // Iterate over each X value
    for (double x = start; x <= end; x += step) {
        double y;
        if (2 >= x && x > 1) {
            y = exp(x) + 1;
        } else if (1 >= x && x > 0) {
            y = log(x);
        } else if (0 >= x && x >= -2) {
            y = sin(x) + x * cos(x);
        }
        y_values.push_back(y);
    }

    // Print X and corresponding Y values
    for (size_t i = 0; i < y_values.size(); ++i) {
        double x = start + i * step;
        std::cout << "X: " << x << ", Y: " << y_values[i] << std::endl;
    }

    return 0;
}
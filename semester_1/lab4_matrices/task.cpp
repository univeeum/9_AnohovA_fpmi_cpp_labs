#include <iomanip>
#include <iostream>
#include <random>

void delete_matrix(double **matrix, double *x, double *y, const int n) {
    for (int i = 0; i < n; i++)
        delete[] matrix[i];

    delete[] matrix;
    delete[] x;
    delete[] y;
}

void print_matrix(double **matrix, const int n) {
    std::cout << "The resulting Cauchy matrix:\n";
    std::cout << std::fixed << std::setprecision(3);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(4) << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void print_column_sums(double **matrix, const int n) {
    std::cout << "Sum of columns:\n";
    std::cout << std::fixed << std::setprecision(3);
    for (int j = 0; j < n; j++) {
        double sum = 0.0;
        for (int i = 0; i < n; i++) {
            sum += matrix[i][j];
        }
        std::cout << std::setw(4) << sum << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char *argv[]) {
    std::cout << "Usage:\n";
    std::cout << "  " << argv[0] << "          - manual input\n";
    std::cout << "  " << argv[0] << " --random - random filling\n\n";

    int n;
    std::cout << "Enter the number of elements in arrays\n";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Error\n";
        std::exit(1);
    }

    // Create arrays x y and matrix
    double *x = new double[n];
    double *y = new double[n];

    double **matrix = new double *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[n];
    }

    if (argc > 1 && static_cast<std::string>(argv[1]) == "--random") {
        // Random input
        int ra, rb;
        std::cout << "Enter random bounds from a to b for nums in array\n";
        if (!(std::cin >> ra >> rb)) {
            std::cout << "Error/n";
            delete_matrix(matrix, x, y, n);
            std::exit(1);
        }
        std::mt19937 gen(1337);
        std::uniform_int_distribution<int> dist(ra, rb);

        for (int i = 0; i < n; i++)
            x[i] = dist(gen);

        for (int i = 0; i < n; i++)
            y[i] = dist(gen);

    } else {
        // Manual input
        std::cout << "Enter numbers for x and y\n";
        for (int i = 0; i < n; i++) {
            std::cin >> x[i];
        }
        for (int i = 0; i < n; i++) {
            std::cin >> y[i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double denom = x[i] + y[j];
            if (denom == 0.0) {
                std::cout << "Cannot build matrix: division by zero\n";
                delete_matrix(matrix, x, y, n);
                std::exit(1);
            } else {
                matrix[i][j] = 1.0 / denom;
            }
        }
    }

    print_matrix(matrix, n);
    print_column_sums(matrix, n);

    delete_matrix(matrix, x, y, n);
    return 0;
}
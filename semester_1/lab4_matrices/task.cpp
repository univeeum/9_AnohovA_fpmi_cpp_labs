#include <iomanip>
#include <iostream>
#include <random>
#include <cstdint>

// TODO try debug in vs code without .vscode settings

// INPUT
void InputSize(int64_t& size) {
    std::cout << "Enter the number of elements in arrays\n";
    if (!(std::cin >> size) || size <= 0) {
        throw std::string("Failed to read matrix size!");
    }
}

void InputVariant(bool& variant) {
    if (!(std::cin >> variant) || (variant != 0 && variant != 1)) {
        throw std::string("Failed to read variant!");
    }
}

// MATRIX FUNCTIONS
void AllocateMatrix(double**& matrix, double*& x, double*& y, const int n) {
    x = new double[n];
    y = new double[n];
    matrix = new double*[n];
    for (int64_t i = 0; i < n; i++) {
        matrix[i] = new double[n];
    }
}

void DeleteMatrix(double**& matrix, double* x, double* y, const int n) {
    for (int64_t i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] x;
    delete[] y;
}

void PrintMatrix(double** matrix, const int n) {
    std::cout << "Matrix:\n";
    std::cout << std::fixed << std::setprecision(3);
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = 0; j < n; j++) {
            std::cout << std::setw(4) << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void FillMatrix(double**& matrix, double* x, double* y, int64_t size) {
    for (int64_t i = 0; i < size; i++) {
        for (int64_t j = 0; j < size; j++) {
            double denom = x[i] + y[j];
            if (denom == 0.0) {
                throw std::string("Cannot build matrix: division by zero\n");
            } else {
                matrix[i][j] = 1.0 / denom;
            }
        }
    }
}

void PrintColumnSums(double** matrix, const int n) {
    std::cout << "Sum of columns:\n";
    std::cout << std::fixed << std::setprecision(3);
    for (int64_t j = 0; j < n; j++) {
        double sum = 0.0;
        for (int64_t i = 0; i < n; i++) {
            sum += matrix[i][j];
        }
        std::cout << std::setw(4) << sum << ' ';
    }
    std::cout << '\n';
}

void PrintArrays(double* x, double* y, const int size) {
    std::cout << "Generated arrays:\n";
    for (int64_t i = 0; i < size; i++) {
        std::cout << x[i] << ' ';
    }
    std::cout << '\n';
    for (int64_t i = 0; i < size; i++) {
        std::cout << y[i] << ' ';
    }
    std::cout << '\n';
}

// INPUT MATRIX
void RandomInput(double* x, double* y, int64_t size) {
    int32_t ra, rb;
    std::cout << "Enter random bounds from a to b for nums in arrays\n";
    if (!(std::cin >> ra >> rb)) {
        throw std::string("Failed to read random bounds!");
    }

    std::mt19937 gen(1337);
    std::uniform_int_distribution<int32_t> dist(ra, rb);

    for (int64_t i = 0; i < size; i++)
        x[i] = dist(gen);

    for (int64_t i = 0; i < size; i++)
        y[i] = dist(gen);
}

void ManualInput(double* x, double* y, int64_t size) {
    std::cout << "Enter numbers for x and y\n";
    for (int64_t i = 0; i < size; i++) {
        if (!(std::cin >> x[i])) {
            throw std::string("Failed to read array element!");
        }
    }
    for (int64_t i = 0; i < size; i++) {
        if (!(std::cin >> y[i])) {
            throw std::string("Failed to read array element!");
        }
    }
}

void InputMatrix(double**& matrix, double* x, double* y, int64_t size) {
    std::cout << "Select an input method (0 or 1):\n  0 - Random\n  1 - Manual\n";
    bool variant = 0;
    InputVariant(variant);

    if (variant == 0) {
        RandomInput(x, y, size);
        PrintArrays(x, y, size);
    } else {
        ManualInput(x, y, size);
    }
}

int main() {
    int64_t size = 0;
    double* x = nullptr;
    double* y = nullptr;
    double** matrix = nullptr;

    try {
        InputSize(size);
        AllocateMatrix(matrix, x, y, size);
        InputMatrix(matrix, x, y, size);
        FillMatrix(matrix, x, y, size);
        PrintMatrix(matrix, size);
        PrintColumnSums(matrix, size);

        DeleteMatrix(matrix, x, y, size);
    } catch (const std::string& msg) {
        std::cerr << msg << '\n';
        if (matrix != nullptr) {
            DeleteMatrix(matrix, x, y, size);
        }
    }
    return 0;
}
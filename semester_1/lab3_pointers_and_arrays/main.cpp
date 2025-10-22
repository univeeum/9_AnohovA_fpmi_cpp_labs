#include <iostream>
#include <random>
#include <iomanip>

// Random number
std::mt19937 gen(1337);

// Dynamic matrix allocation
int **allocateMatrix(int rows, int cols) {
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];
    return matrix;
}

// Free memory
void deleteMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}

// Manual input
void fillMatrixManual(int **matrix, int rows, int cols) {
    std::cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            std::cin >> matrix[i][j];
}

// Fill with random numbers
void fillMatrixRandom(int **matrix, int rows, int cols, int minVal, int maxVal) {
    std::uniform_int_distribution<int> dist(minVal, maxVal);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = dist(gen);
}

// Print matrix
void printMatrix(int **matrix, int rows, int cols) {
    std::cout << "\nMatrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            std::cout << std::setw(4) << matrix[i][j] << " ";
        std::cout << "\n";
    }
}

// SORT 

void insert_sort(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            int cur = j;
            while (cur > 0 && matrix[i][cur - 1] > matrix[i][cur]) {
                std::swap(matrix[i][cur - 1], matrix[i][cur]);
                cur--;
            }
        }
    }
}

bool comp (int a, int b) {
    return a < b;
}

int main() {
    int rows, cols;

    // Matrix size
    std::cout << "Enter number of rows:\n";
    std::cin >> rows;
    std::cout << "Enter number of columns:\n";
    std::cin >> cols;

    // Allocate matrix
    int **matrix = allocateMatrix(rows, cols);

    // Filling method
    std::cout << "\nChoose filling method:\n0 - Manual\n1 - Random\nYour choice: ";
    int fillChoice;
    std::cin >> fillChoice;

    if (fillChoice == 1) {
        int ra, rb;
        std::cout << "Enter random bounds from a to b for nums in array\n";
        if (!(std::cin >> ra >> rb)) {
            std::cout << "Error\n";
            deleteMatrix(matrix, rows);
            std::exit(1);
        }
        fillMatrixRandom(matrix, rows, cols, ra, rb);
    } else {
        fillMatrixManual(matrix, rows, cols);
    }

    // Print original matrix
    printMatrix(matrix, rows, cols);

    // Choose sort type 
    std::cout << "Choose sort type (0 - up) or (1 - down)\n";
    int sort_type = 0;
    std::cin >> sort_type;

    // Choose sort algo
    std::cout << "Default | Insertion |  \n";
    std::string sort_algo = "Default"; 

    if (sort_algo == "Default") {
        
    } else if (sort_algo == "Instertion") {
        
    }

    // Print sorted matrix
    printMatrix(matrix, rows, cols);

    deleteMatrix(matrix, rows);
    return 0;
}
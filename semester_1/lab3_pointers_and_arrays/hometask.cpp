#include <iomanip>
#include <iostream> 
#include <random>

// Random generator 
std::mt19937 gen(1337);

// Matrix Actions  
void createMatrix(int** &matrix, const int &rows, const int &columns) {
    matrix = new int* [rows];
    for (int i = 0;i < rows;i++) {
        matrix[i] = new int[columns];
    }
}

void printMatrix(int** &matrix, const int &n, const int &m) {
    std::cout << "Matrix:\n";
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            std::cout << std::setw(3) << matrix[i][j];
        }
        std::cout << '\n';
    }
}

void deleteMatrix (int** &matrix, int n) {
    for (int i = 0; i < n;i++) {
        delete[] matrix[i];
    }    
    delete[] matrix;
}


// Input Functions

void inputBorders(int &rows, int &columns) {
    std::cout << "Enter the number of rows in the matrix\n";
    if (!(std::cin >> rows) || rows <= 0) {
        std::cout << "Error while input rows\n"; 
        std::exit(1);
    }
    std::cout << "Enter the number of columns in the matrix\n";
    if (!(std::cin >> columns) || columns <= 0) {
        std::cout << "Error while input columns\n"; 
        std::exit(1);
    }
}

void inputVariant (int &variant) {
    if (!(std::cin >> variant) || (variant != 0 && variant != 1)) {
        std::cout << "Error\n";
        std::exit(1);
    }
}

void inputSortVariant (int &variant) {
    if (!(std::cin >> variant) || variant < 1 || variant > 3) {
        std::cout << "Error\n";
        std::exit(1);
    }
}

void manualInput(int** matrix, const int &rows, const int &columns) {
    std::cout << "Enter matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0;j < columns;j++) {
                if (!(std::cin >> matrix[i][j])) {
                    std::cout << "Error while input matrix\n";
                    deleteMatrix(matrix, rows);
                    std::exit(1);
            }
        }
    }
}

void randomInput(int** matrix, const int &rows, const int &columns) {
    int ra, rb;
        std::cout << "Enter bounds of nums in matrix - a and b\n";

        if (!(std::cin >> ra >> rb)) {
            std::cout << "Error\n";
            deleteMatrix(matrix, rows);
            std::exit(1);
        }
        std::uniform_int_distribution<int> dist(ra, rb);
        for (int i = 0; i < rows; i++) 
            for (int j = 0;j < columns;j++) 
                matrix[i][j] = dist(gen);
}

void chooseInput(int** &matrix, const int &rows, const int &columns) {
    std::cout << "Select an input method (0 or 1):\n  0 - Random\n  1 - Manual\n";
    int variant = 0;
    inputVariant(variant);

    if (!variant)
        randomInput(matrix, rows, columns);
    else
        manualInput(matrix, rows, columns);
}

// Comparison functions

bool comp1 (const int &a, const int &b) {
    return a < b;
}
bool comp2 (const int &a, const int &b) {
    return a > b;
}

bool (*selectOrder())(const int &, const int &) {
    std::cout << "Enter 0 for ascending order or 1 for descending order\n";

    int variant = 0; 
    inputVariant(variant);
    if (!variant) 
        return comp1;
    else 
        return comp2;
}


// Sort functions

void bubbleSort(int* arr, int n, bool (*comparison)(const int&, const int&)) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (comparison(arr[j+1], arr[j])) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(int* arr, int n, bool (*comparison)(const int&, const int&)) {
    for (int i = 0; i < n-1; i++) {
        int extreme = i;
        for (int j = i+1; j < n; j++) {
            if (comparison(arr[j], arr[extreme])) {
                extreme = j;
            }
        }
        std::swap(arr[i], arr[extreme]);
    }
}

void insertionSort(int* arr, int n, bool (*comparison)(const int&, const int&)) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && comparison(key, arr[j])) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void sortMatrix(int** &matrix, const int &rows, const int &columns, void (*sortFunc)(int*, int, bool(*)(const int &, const int &)), bool (*comp)(const int &, const int &)) {
    for (int i = 0;i < rows;i++) 
        sortFunc(matrix[i], columns, comp);
}

void chooseSort(int** &matrix, const int &rows, const int &columns) {
    bool (*comp)(const int&, const int&) = selectOrder();
    std::cout << "Choose sort type:\nBubble sort    (enter 1)\nSelection sort (enter 2)\nInsertion sort (enter 3)\n";
    int variant;
    inputSortVariant(variant);

    switch (variant) {
        case 1: 
            sortMatrix(matrix, rows, columns, bubbleSort, comp);
            std::cout << "Bubble sort completed!\n";
            break;
        case 2:
            sortMatrix(matrix, rows, columns, selectionSort, comp);
            std::cout << "Selection sort completed!\n";
            break;
        case 3:
            sortMatrix(matrix, rows, columns, insertionSort, comp);
            std::cout << "Insertion sort completed!\n";
            break;
        default:
            std::cout << "Invalid choice, using bubble sort\n";
            sortMatrix(matrix, rows, columns, bubbleSort, comp);
            break;
    }
}

int main () {
    // Input 
    int rows, columns;
    inputBorders(rows, columns);
    int **matrix;
    createMatrix(matrix, rows, columns);

    chooseInput(matrix, rows, columns);
    printMatrix(matrix, rows, columns);

    // Sort 
    chooseSort(matrix, rows, columns);
    printMatrix(matrix, rows, columns);

    deleteMatrix(matrix, rows);
    return 0;
}

/*
    Ввести размеры матрицы n m 
    Обьявить динамический массив 
    Выбрать способ запонения и заполнить матрицу
    Вывести матрицу 
    Выбраит направление сортировки
    Выбрать тип сортировки
    Отсортировать
    Вывести матрицу
    Удалить матрицу 
*/
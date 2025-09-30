#include <algorithm>
#include <iostream>
#include <random>

// solve task with usage of
// dymanic arrays
int main(int argc, char* argv[]) {

    int n, a, b;
    std::cout << "Enter the number of array elements\n";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Error\n";
        return 1;
    }
    
    std::cout << "Enter a and b\n";
    if (!(std::cin >> a >> b) || std::min(a, b) < 0 || std::max(a, b) > n) {
        std::cout << "Error\n";
        return 1;
    }
    int low = std::min(a, b);
    int high = std::max(a, b);
    low--; high--;

    // dynamic array
    int* array = new int[n];

    // select filling method
    if (argc > 1 && std::string(argv[1]) == "--random") {
        int ra, rb;
        std::cout << "Enter random bounds a and b\n";

        if (!(std::cin >> ra >> rb)) {
            std::cout << "Error\n";
            delete[] array; 
            return 1;
        }
        std::mt19937 gen(1337);
        std::uniform_int_distribution<int> dist(ra, rb);
        for (int i = 0; i < n; i++) 
            array[i] = dist(gen);

    } else {
        std::cout << "Enter " << n << " integers:\n";
        for (int i = 0; i < n; i++) {
            if (!(std::cin >> array[i])) {
                std::cout << "Error\n";
                delete[] array;
                return 1;
            }
        }
    }
    
    // find uniq elements
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool seen_before = false;
        for (int j = 0; j < i; j++) {
            if (array[i] == array[j] && i != j) {
                seen_before = true; break;
            }
        }
        if (!seen_before) count++;
    }
    std::cout << "Number of different elements is " << count << '\n';

    // find sum of elements
    int sum = 0, first = -1, second = -1;
    for (int i = 0; i < n; i++) {
        if (array[i] > 0) first = i;
        if (array[i] > 0 && first != -1) second = i;
    }

    for (int i = first; i < second; i++) {
        sum += array[i];
    }

    if (first == -1 || second == -1) {
        std::cout << "There are not two positive elements\n";
    } else {
        std::cout << "Sum between the first and second positive numbers is " << sum << '\n';
    }
    
    int insert_pos = n - 1;

    for (int i = high; i >= low; i--) {
        int val = array[i];
        for (int j = i; j < insert_pos; j++) {
            array[j] = array[j + 1];
        }
        array[insert_pos] = val;
        insert_pos--;
    }

    std::cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << ' '; 
    }
    std::cout << '\n';

    return 0;
}
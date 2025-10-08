#include <climits>
#include <iostream>
#include <random>

// solve task with usage of
// static arrays
// variant 3

static const int N = 1000;

int main(int argc, char* argv[]) {
    
    std::cout << "Usage:\n";
    std::cout << "  " << argv[0] << "          - manual input\n";
    std::cout << "  " << argv[0] << " --random - random filling\n\n";

    int array[N];
    int min_element = INT_MAX;
    int n;

    std::cout << "Enter the number of array elements (no more than " << N << ")\n";
    if (!(std::cin >> n) || (n > N || n <= 0)) {
        std::cout << "Error\n";
        std::exit(1);
    }

    // select filling method
    if (argc > 1 && static_cast<std::string>(argv[1]) == "--random") {
        int a, b;
        std::cout << "Enter random bounds a and b\n";

        if (!(std::cin >> a >> b)) {
            std::cout << "Error\n";
            std::exit(1);
        }
        std::mt19937 gen(1337);
        std::uniform_int_distribution<int> dist(a, b);
        for (int i = 0; i < n; i++) 
            array[i] = dist(gen);
        
    } else {
        std::cout << "Enter " << n << " integers:\n";
        for (int i = 0; i < n; i++) {
            if (!(std::cin >> array[i])) {
                std::cout << "Error\n";
                std::exit(1);
            }
        }
    }

    // find sum and min element
    int sum = -1;
    for (int i = 0; i < n; i++) {
        min_element = std::min(abs(array[i]), min_element);
        
        if (array[i] == 0) sum = 0;
        if (sum != -1) sum += array[i];
    }

    std::cout << "Minimum element by modulus is " << min_element << "\n";

    if (sum != -1) {
        std::cout << "Sum of elements after the last zero is " << sum << "\n";
    } else {
        std::cout << "There are no zero elements :(\n";
    }

    // convert array 
    // 1 2 3 4 5 6 7 8 9
    // 2 4 6 8 1 3 5 7 9

    int insert_pos = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            int val = array[i];
            for(int j = i; j > insert_pos; j--) {
                array[j] = array[j - 1];
            }
            array[insert_pos] = val;
            insert_pos++;
        }
    }
    
    std::cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << ' '; 
    }
    std::cout << '\n';

    return 0;
}
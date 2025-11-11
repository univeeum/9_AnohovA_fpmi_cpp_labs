#include <iostream>

int *merge(int *arr, const int *arr1, const int *arr2, int n, int m) {

    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }
    // дописываем остаток из arr1 или arr2
    while (i < n)
        arr[k++] = arr1[i++];

    while (j < m)
        arr[k++] = arr2[j++];

    return arr;
}

int main() {
    // merge two arrays
    
    int n, m;
    if (!(std::cin >> n) || n < 0) {
        std::cout << "Error\n";
        std::exit(1);
    }

    int *arr1 = new int[n];
    for (int i = 0; i < n; i++) {
        if (!(std::cin >> arr1[i])) {
            std::cout << "Error\n";
            std::exit(1);
        }
    }

    if (!(std::cin >> m) || m < 0) {
        std::cout << "Error\n";
        std::exit(1);
    }

    int *arr2 = new int[m];
    for (int i = 0; i < m; i++) {
        if (!(std::cin >> arr2[i])) {
            std::cout << "Error\n";
            std::exit(1);
        }
    }

    int *arr = new int[m + n];
    arr = merge(arr, arr1, arr2, n, m);

    for (int i = 0; i < n + m; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
    delete[] arr;
    delete[] arr1;
    delete[] arr2;

    return 0;
}
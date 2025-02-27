#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// Recursive Binary Search
int recursiveBinarySearch(const std::vector<int>& arr, int target, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] > target) {
            return recursiveBinarySearch(arr, target, low, mid - 1);
        }
        else {
            return recursiveBinarySearch(arr, target, mid + 1, high);
        }
    }
    return -1; // Not found
}

// Iterative Binary Search
int iterativeBinarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1; // Not found
}

// Sequential Search
int sequentialSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1; // Not found
}

int main() {
    std::vector<int> data = { 5, 2, 8, 1, 9, 3, 7, 4, 6 }; // Example data
    std::sort(data.begin(), data.end());

    int target1 = 6;
    int target2 = 10;

    // Output Sorted Vector
    std::cout << "Sorted Vector: ";
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Recursive Binary Search
    int index = recursiveBinarySearch(data, target1, 0, data.size() - 1);
    std::cout << "Recursive Binary Search: Target " << target1 << " found at index " << index << std::endl;
    index = recursiveBinarySearch(data, target2, 0, data.size() - 1);
    std::cout << "Recursive Binary Search: Target " << target2 << " not found, returned " << index << std::endl;

    // Iterative Binary Search
    index = iterativeBinarySearch(data, target1);
    std::cout << "Iterative Binary Search: Target " << target1 << " found at index " << index << std::endl;
    index = iterativeBinarySearch(data, target2);
    std::cout << "Iterative Binary Search: Target " << target2 << " not found, returned " << index << std::endl;

    // Sequential Search
    index = sequentialSearch(data, target1);
    std::cout << "Sequential Search: Target " << target1 << " found at index " << index << std::endl;
    index = sequentialSearch(data, target2);
    std::cout << "Sequential Search: Target " << target2 << " not found, returned " << index << std::endl;

    return 0;
}
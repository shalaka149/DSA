#include <iostream>
#include <algorithm>  // for min function
using namespace std;

// Function for Fibonacci Search
int fibonacciSearch(int arr[], int n, int target) {
    // Initialize Fibonacci numbers
    int fibMMm2 = 0;  // (m-2)'th Fibonacci Number
    int fibMMm1 = 1;  // (m-1)'th Fibonacci Number
    int fibM = fibMMm1 + fibMMm2;  // m'th Fibonacci Number

    // Find the smallest Fibonacci number greater than or equal to n
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm1 + fibMMm2;
    }

    // Marks the eliminated range from the front
    int offset = -1;

    // Continue comparing elements with Fibonacci numbers
    while (fibM > 1) {
        // Check if fibMMm2 is a valid index
        int i = min(offset + fibMMm2, n - 1);

        // If target is greater, move the range to the right
        if (arr[i] < target) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        // If target is smaller, move the range to the left
        else if (arr[i] > target) {
            fibM = fibMMm2;
            fibMMm2 = fibMMm1 - fibMMm2;
            fibMMm1 = fibM - fibMMm2;
        }
        // Target found
        else {
            return i;
        }
    }

    // If the last element is the target
    if (fibMMm1 && arr[offset + 1] == target) {
        return offset + 1;
    }

    // Target is not found
    return -1;
}

int main() {
    int n;

    // Input array size
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input array elements
    int arr[n];
    cout << "Enter the elements in the array (sorted order): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int target;
    // Input target value
    cout << "Enter the target value: ";
    cin >> target;

    // Perform Fibonacci Search
    int result = fibonacciSearch(arr, n, target);

    // Output result
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}


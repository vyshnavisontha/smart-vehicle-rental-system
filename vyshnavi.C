#include <stdio.h>

int main() {
    int arr[10] = {10, 20, 30, 40, 50}; // Array has extra space
    int n = 5;                          // Current number of elements
    int pos = 2;                        // Insert at index 2 (3rd position)
    int value = 25;

    // Shift elements to the right
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert new value
    arr[pos] = value;
    n++;

    // Print array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
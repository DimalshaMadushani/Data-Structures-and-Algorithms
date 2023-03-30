#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <chrono>

using namespace std;

// Function to swap two elements in an array
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* This function takes the last element of the array as pivot, places the pivot element 
   at its correct position in the sorted array, and places all elements smaller than the pivot 
   to its left and all greater elements to its right */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Select the last element as the pivot
    int i = low - 1; // Initialize the index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++; // Increment the index of the smaller element
            swap(&arr[i], &arr[j]); // Swap the current element with the smaller element
        }
    }

    swap(&arr[i + 1], &arr[high]); // Swap the pivot element with the element at the index of the smaller element
    return (i + 1); // Return the index of the pivot element
}

/* Function to perform quicksort on the given array A[] from index l to h */
void quickSort(int A[], int low, int high)
{
    if (low < high) {
        /* pi is the partitioning index, arr[p] is now at right place */
        int pi = partition(A, low, high);

        // Recursively sort the elements before and after partition
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

// Driver code to test quickSort function
int main(){
    int array_size = 19847;
    int arr[array_size];

    srand(time(NULL));

    // Create the array by adding random elements less than 1000;
    for (int i = 0; i < array_size; i++) {
        arr[i] = rand() % 1000;
    }

    // Start time
    auto start = chrono::high_resolution_clock::now();

    quickSort(arr, 0, array_size - 1);

    // End time
    auto stop = chrono::high_resolution_clock::now();

    // Get the execution time for Recursive QuickSort algorithm
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}
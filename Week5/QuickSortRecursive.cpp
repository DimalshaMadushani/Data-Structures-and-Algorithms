#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <chrono>
#include <vector>

using namespace std;

void quickSort(vector<int>& array, int left, int right) {
    // base case
    if (left >= right) 
        return; 

    // select pivot element
    int pivot = array[(left + right) / 2]; 
    // get hold of the indices for right and left array
    int i = left, j = right;

    while (i <= j) {
        // find element on left that is need to be swapped
        while (array[i] < pivot) 
            i++; // incremt i to go through the left partition
        // find element on right that is need to be swapped
        while (array[j] > pivot) 
            j--; //incremt j to go through the left partition

        // If i and j did not cross each other, swap the elements at i and j
        if (i <= j) { 
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    // recursive calls for left partion and right partition
    if (left < j) 
        quickSort(array, left, j);
    if (i < right) 
        quickSort(array, i, right);
}

int main(){
    int array_size = 16789;
    vector<int> arr(array_size);

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

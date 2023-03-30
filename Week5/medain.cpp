#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// declartion for insertion sort
void insertionSort(vector<int>& arr);
// declaratio  for median 
double getMedian(vector<int> & arr);

int main() {
    int num, count;
   
    // Create an empty vector
    vector<int> array;

    cout << "How many elements do you want to add to the array ?";
    // get the user input for length of the array.
    cin >> count;

    
    // get user inputs and find the median of the current array in each loop.
    for (int i = 0 ; i < count ; i++) {
        cout << "Enter the element : " ;
        cin >> num ;
        // push the user enetered element into the array.
        array.push_back(num);
        // sort the current array
        insertionSort(array);
        // get the median of the cuurent array
        double median = getMedian(array);
        // print the median of the current array
        cout << "Median : " << median << endl;
    }
    
    return 0;
}

// function to sort the array using insertion sort
void insertionSort(vector<int>& arr) {
    // assign the key as the last added elemnt to the array
    int key = arr[arr.size() - 1];
    // get hold the index of last sorted element in the array
    int j = arr.size() - 2;

    // indentify the correct position that key is needed to insert
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    // insert the key to correct position
    arr[j+1] = key;
}

// function to find the median of an array.
double getMedian(vector<int>& arr) {
    // get the size of the array
    int size = arr.size();
    double median;
    // initialize the mid position of the array
    int mid = size/2;
    
    // check if array size is odd
    if (size % 2) {
        median = arr[mid];
        // return rounded median
        return round(median * 10.0) / 10.0;
    // check if array size is even
    } else {
        // get the median
        median = (arr[mid-1] + arr[mid])/2.0;
        // return rounded median
        return round(median * 10.0) / 10.0;
    }
}

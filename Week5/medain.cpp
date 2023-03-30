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



// #include <iostream>
// #include <cmath>

// using namespace std;

// void InsertToSortedArr(vector<int>& num_arr, int num){
//     int j = num_arr.size() - 1;
//     // If the array has no elements, just insert the number.
//     if (j < 0){
//         num_arr.push_back(num);
//     }
//     else{
//         // Identify the correct position that number has to insert.
//         while (j >= 0 && num_arr[j] > num) {
//         j--;
//         }
//         // Insert the number to that correct position.
//         num_arr.insert(num_arr.begin() + j + 1, num);
//     }
// }


// double GetMedian(vector<int>& num_arr){
//     double median;
//     if (num_arr.size() % 2 == 1){ // If the array has odd number of elements get the middle element.
//         median = (double)num_arr[num_arr.size() / 2];
//     }
//     else {
//         // If the element has even number of elements, get the average of the two middle elements of the sorted array as median.
//         int mid = num_arr.size() / 2;
//         median = (num_arr[mid] + num_arr[mid - 1]) / 2.0;
//     }
//     return round(median * 10.0) / 10.0; // return the median round to first decimal place.
// }


// int main() {
//     vector<int> sorted_num_arr; // Store the user entered numbers
//     int num_of_inputs;
//     cout << "Enter number of inputs that you are going to input: "; // Get the number of inputs that the user is going to input.
//     cin >> num_of_inputs;
//     int num;
//     for (int i = 0; i < num_of_inputs; i++){ // Get inputs from the user
//         cout << "Enter number " << (i + 1) << ": ";
//         cin >> num;
//         InsertToSortedArr(sorted_num_arr, num); // Enter the number to the correct position of the sorted array.
//         cout << "Median: " << GetMedian(sorted_num_arr) << endl; // Print the median of the sorted array.
//     }
//     return 0;
// }
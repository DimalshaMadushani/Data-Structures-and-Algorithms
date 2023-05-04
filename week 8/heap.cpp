#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   //get the index of the left child of the parent(root)
   int left = 2*root + 1;
   //get the index of the right child of the parent(root)
   int right = 2 * root +2;
   //initialize the index of the largest value  to the root of the heap.
   int largest = root;
   //check if the left is the largest 
   if (left < n && arr[left] > arr[root]){
      largest = left;
   }
   //check if the left is the smallest
   if(right < n && arr[right] > arr[largest]){
      largest = right;
   }

   // if largest in not equal to root exchange the arr[root] and arr[largest]
   if(largest != root) {
      //to exchange, initialize a temporary variable and initialize it by arr[largest] and do the exchanging
      int temp = arr[largest];
      arr[largest] = arr[root];
      arr[root] = temp;
      //call the heapify recursively top to bottom
      heapify(arr,n,largest);
   }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build the heap by performing the heapify operation the heap bottom to top.
   for(int i = n/2 ; i >= 0; i--){
      heapify(arr,n,i);
   }
   
   // extracting elements from heap one by one
   for(int i = n - 1; i >= 1 ; i--){
      //get a temporary variable to exchange the root of the heap and the bottom most element in the max heap.
      int temp = arr[i];
      arr[i] = arr[0];
      arr[0] = temp;
      //reduce the heap size by one since we extract one largest element from the heap.
      n = n - 1;
      //since the heap is now again not a max heap, again call heapify to built the max heap.
      heapify(arr,n,0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   //int heap_arr[] = {4,17,3,12,9,6};
   //get the user input for the heap size
   int n; // size of the heap
   cout << "Enter the heap size: ";
   cin >> n;
   //declare an array for the heap with user input heap size
   int* heap_arr = new int[n] ;
   //get the elements of the heap as user inputs
   cout << "Enter the element you want to insert: \n";
   for(int i = 0; i < n; i++) {
      cin >> heap_arr[i];
   }
   // int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
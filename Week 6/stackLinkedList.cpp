
#include <iostream>
#include <chrono>

using namespace std;

// creating a structure for a node in the linked list
struct node {
    int data;
    struct node * next;
} ;

// create a pointer (called top ) to the stack and set it to NULL
struct node *top  = NULL;
// initializea pointer to the size of the stack
int *stackSize;
// set the current size of the stack to  zero
int currentSize = 0;

// check if the stack is empty
bool isEmpty() {
    return (top == NULL);
}

// check if the stack is full
bool isFull() {
    return (currentSize >= *stackSize);
}



// a function to push the data  to stack.
void Push(int num) {
    // creating a new node
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
    // put the data to new node
    newNode->data = num; 
     // set the  next pointer of the new node to the current top
    newNode-> next = top;
    // set the top to the new node
    top = newNode; 
    // increase the current size of the stack
    currentSize++;
}

//function to pop data from the stack
int Pop() {
    // check if stack is already empty
    if (isEmpty()) { 
        cout << "Stack Underflow\n";
        return 0;
    }
    else {
        // retrieve the data from the top node
        int num = top->data; 
         // store the top node in a temporary pointer variable
        struct node* temp = top;
        // set the top to the next node
        top = top->next; 
        // free the memory of the top node using free function
        free(temp); 
        //decrease the cuurent szie of the stack
        currentSize--;
        return num;
    }
}

// function to get the top of the stack
int stackTop() {
    if (isEmpty()){
        cout << "Stack is empty\n";
        return 0;
    } else {
        // return the data of top node.
         return top -> data;
    }
       
}

// function to disply the stack
void displayStack() {
    // check if stack is empty before printing
    if (isEmpty()){
        cout << "Stack is empty\n";
    }
    else {
        // create a pointer called current node to traverse through the linklist stack.
        struct node *current_Node = top;
        // print the elments of the stack untill the top is not null
        while(current_Node != NULL) {
            // print the data of the current node
            cout << current_Node -> data << endl;
            // set the current node to the next current node.
            current_Node = current_Node -> next;
        }
        cout << endl;
    
    }
}

int main() {
    
    
    stackSize = new int;
    // take the stack size as a user input
    cout << "Enter the size of the stack : " ;
    // assign it to the stack size
    cin >> *stackSize;

     // get current time
    
    auto start = chrono::high_resolution_clock::now();
    // operations on stack
    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    displayStack();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    displayStack();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    displayStack();

    auto end = chrono::high_resolution_clock::now(); // get current time
    auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start); // calculate time difference in microseconds
    std::cout << "Time taken for the execution: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
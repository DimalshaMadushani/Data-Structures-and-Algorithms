

#include <iostream>
#include <chrono>

using namespace std;


// initialize top to -1, that means the stack is empty
int top = -1; 
int *stack;
int *stackSize;

// function declarations
void Push(int num);
int Pop();
bool isEmpty();
bool isFull();
int stackTop();
void displayStack();

int main() {
    stackSize = new int;
    cout << "Enter the size of the stack :" ;
    cin >> *stackSize;
    
    stack = new int[*stackSize];
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
    std::cout << "Time taken for the execution : " << duration.count() << " microseconds" << std::endl;

    return 0;
}



void Push(int num) {
    // Go to the top of the stack
    top++;
    // check if stack is already full
    if (isFull()) { 
        cout << "Stack Overflow\n";
        return;
    }
    else {
        // insert the element
        stack[top] = num; 
    }
}

int Pop() {
    // check if stack is already empty
    if (isEmpty()) { 
        cout << "Stack Underflow\n";
        return 0;
    }
    else {
        //decrement the top .
        top--;
        // remove and return the top element
        return stack[top + 1]; 
    }
}

bool isEmpty(){
    return (top == -1);
}

bool isFull() {
    return (top+1 >= *stackSize);
}

int stackTop() {
    if (!isEmpty())
        return stack[top];
}

void displayStack() {
    if (isEmpty()){
        cout << "Stack is empty\n";
    }
    
    // printing the stack elements top to bottom.
    else {
        cout << endl;
    for(int i = top ; i > -1; i-- ) {
        cout << stack[i] << endl;
    }
    cout << endl;
    }
}
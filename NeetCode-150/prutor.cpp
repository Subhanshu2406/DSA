#include <iostream>
#define MAX_SIZE 100  // Define the maximum size of the array

using namespace std;

// Class representing two stacks using a single array
class TwoStacks {
    int arr[MAX_SIZE];
    int top1; // Top for the first stack
    int top2; // Top for the second stack

public:
    // Constructor to initialize the two stacks
    TwoStacks() {
        initialize();
    }

    // Function to initialize the two stacks
    void initialize() {
        top1 = 0;
        top2 = MAX_SIZE - 1;
    }

    // Function to push an element onto the first stack
    void push1(int x) {
        if(top1 + 1 < top2) arr[++top1] = x;
        // TODO: Implement the logic to push an element onto the first stack
        // Ensure that you check for overflow
    }

    // Function to push an element onto the second stack
    void push2(int x) {
        if(top2 - 1 > top1) arr[-top2] = x;
        // TODO: Implement the logic to push an element onto the second stack
        // Ensure that you check for overflow
    }

    // Function to pop an element from the first stack
    int pop1() {
        if(top1 >= 0) top1--;
        // TODO: Implement the logic to pop an element from the first stack
        // Ensure that you check for underflow
    }

    // Function to pop an element from the second stack
    int pop2() {
        if(top2 < MAX_SIZE) top2++;
        // TODO: Implement the logic to pop an element from the second stack
        // Ensure that you check for underflow
    }

    // Function to print the elements of both stacks
    void printBoth() {
        for(int i = 0;i <= top1;i++){
            cout << arr[top1] << " ";
        }
        cout << '\n';
        for(int i = top2; i < MX_SIZE;i++){
            cout << arr[top2] << " ";
        }
        // TODO: Implement the logic to print both stacks
    }
};

// Main function
int main() {
    TwoStacks ts;
    ts.initialize();

    int n1, n2;
    cin >> n1 >> n2;
    for(int i = 0; i< n1;i++){
        int data;
        cin >> data;
        ts.push1(data);
    }
    for(int i = 0; i< n2;i++){
        int data;
        cin >> data;
        ts.push2(data);
    }
    // TODO: Add user input logic for the number of elements and elements for both stacks
    // Use push1 and push2 to add elements to the stacks

    // TODO: Perform a series of stack operations like pop and print
    
    return 0;
}
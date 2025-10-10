#include <iostream>
#include <algorithm>

using namespace std;

// Class for AVL Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new AVL tree node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to get the height of a node
int getHeight(Node* node) {
    // Implement this function to return the height of a node
    if(!node) return 0;
    return node -> height;
}

// Function to create a new AVL tree node
Node* createNode(int data) {
        return new Node(data);
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    // Implement this function to perform a right rotation
}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    // Implement this function to perform a left rotation
}

// Get Balance factor of node N
int getBalance(Node* N) {
    // Implement this function to calculate and return the balance factor
}

// Function to insert a node in AVL tree and balance the tree
Node* insert(Node* node, int data) {
    // Implement this function to insert a node and balance the AVL tree
    if(!node) return    
}

// Function to check if a tree is a valid AVL tree
bool isValidAVL(Node* root) {
    // Implement this function to check if a tree is a valid AVL tree
}

// Function to perform preorder traversal of the AVL tree
void preorderTraversal(Node* root) {
    // Implement this function to perform a preorder traversal and print nodes
}


int main() {
    int n;

    cin >> n;
    Node* root = nullptr;


    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        root = insert(root, data);
    }


    preorderTraversal(root);
    cout << endl;

    if (isValidAVL(root)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
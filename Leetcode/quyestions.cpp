Problem Statement
WAP to implement the insertion of nodes into an AVL tree and check whether the resulting tree is a valid AVL tree. 
Your main program should take the following input:
The number of nodes n to be inserted into the AVL tree. n integers representing the data of each node to be inserted.

Inputs: number of nodes and value of nodes.
Output: root node of resultant and "True " or "False" to represent validity.

input: 2 1 3
output :
2 1 3 
True
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









Problem Statement
Build an AVL tree by inserting a predefined set of keys.
Allow the user to input a key to delete from the AVL tree.
Perform the necessary rotations to maintain the AVL tree's balance after deletion.
Display the tree's preorder traversal after the deletion to illustrate its balanced structure.

Inputs: 1) a integer value which represents "Number of nodes"; 2) Take node values ;3) Another input which represents target node to delete.
Output : Preorder traversal of tree

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    struct Node *left, *right;
    int height;
};

// Utility function to get maximum of two integers
int max(int a, int b) {
    // TODO: Implement max function
}

// Function to get height of the tree
int height(Node *N) {
    // TODO: Implement height function
}

// Helper function to create a new node with the given key
Node* newNode(int key) {
    // TODO: Allocate memory for a new node and initialize it
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node *y) {
    // TODO: Implement rightRotate function
}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node *x) {
    // TODO: Implement leftRotate function
}

// Get Balance factor of node N
int getBalance(Node *N) {
    // TODO: Implement getBalance function
}

// Recursive function to insert a key into the subtree rooted with node
// and returns the new root of the subtree.
Node* insert(Node* node, int key) {
    // TODO: Implement AVL tree insertion logic
    // Remember to update the height of the node and balance the tree
}

// Recursive function to delete a node with given key from subtree with given root
// It returns root of the modified subtree.
Node* deleteNode(Node* root, int key) {
    // TODO: Implement AVL tree deletion logic
    // Remember to update the height of the node and balance the tree
}

// A utility function to do preorder traversal of the tree
void preOrder(Node *root) {
    if(root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}



int main() {
    Node *root = NULL;
    int n, key;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>key;
        root = insert(root, key);
    }

    cin>>key;
    root = deleteNode(root, key);

    preOrder(root);

    return 0;
}




















Problem Statement
For any Binary Tree, write a program that calculates the number of rooted paths, whose alternating sum matches the required targets. Rooted Paths are paths that start from the root of the tree, and may end on any node in the tree. Alternating Sum of a rooted path is the value obtained by alternatingly adding and subtracting node values from the root to the path end. For e.g., for a path 5 -> 4 -> 1 -> 3 -> 2, in a tree rooted at 5, the alternating Sum is 5 - 4 + 1 - 3 + 2 = 1.

Input format:
n and k, where n is the size of the level-order array representation of the BT, and k is the number of targets to check
The level-order array representation of the BT (-1 for null nodes)
The 'k' targets 'ti' (i = 1 to k)
Output:
'k' numbers 'ci' (i = 1 to k) giving the count of paths satisfying alternating path sum of 'ti'

E.g.
Input:
7 3
1 3 2 6 1 -1 5
4 -1 0
Output:
2 2 0

Explanation: The given tree is
          1
    3         2
6     1    null   5
Here the rooted paths 1->3->6 and 1->2->5 give the alternating sum of 4, hence the first count is 2. 
Similarly, the rooted paths 1->2 and 1->3->1 give the alternating sum of -1, hence the second count is also 2.
However, no rooted path gives the alternating sum of 0, hence the third count is 0.




roblem Statement
You are given a tree with n vertices labelled 1,2,…,n The length of a simple path in the tree is the number of vertices in it. You are to select a set of simple paths of length at least two each, but you cannot simultaneously select two distinct paths contained one in another. Find the largest possible size of such a set.

Formally, a set S of vertices is called a route if it contains a least two vertices of a simple path in the tree. A collection of distinct routes is called a timetable. A route S in a timetable T is called redundant if there is different route S' that belongs to T such that S is a subset of S'. A timetable is called efficient if it contains no redundant routes. Find the largest possible number of routes in an efficient timetable.

Input format:
First line contains n, which is the number of nodes
Nex n lines contains u-v pairs of edges

Output format:
One integer with your answer

Example
Input:
4
1 2
1 3
1 4

OUTPUT
3



















Problem Statement
Create a BST from given inputs (+ve) and find the in-order successor for the given element and if no successor is there print -1.
Input: n
n number of inputs element whose successor needs to be printed

Input: 1)number of nodes and values ; 2) target node sought for successor
Output : successor node#include <iostream>
using namespace std;

// Class definition for a Node in the BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Class definition for the Binary Search Tree
class BST {
private:
    Node* root;

    // Helper function to insert a node in the BST
    Node* insert(Node* node, int data) {
        // TODO: Implement the insert function
    }

    // Helper function to find the minimum value node in a subtree
    Node* findMin(Node* node) {
        // TODO: Implement the findMin function
    }

    // Helper function to find a node with a given value
    Node* findNode(Node* node, int data) {
        // TODO: Implement the findNode function
    }

public:
    // Constructor to initialize the root of the BST
    BST() {
        root = nullptr;
    }

    // Public function to insert a node in the BST
    void insert(int data) {
        root = insert(root, data);
    }

    // Function to find the in-order successor of a given node
    int findInOrderSuccessor(int data) {
        // TODO: Implement the findInOrderSuccessor function
    }
};

// Main function to execute the program
int main() {
    int n, target;
    cin >> n;

    BST tree;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }

    cin >> target;

    int successor = tree.findInOrderSuccessor(target);
    if (successor != -1) {
        cout << successor << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}








Problem Statement
A ride-hailing company wants to keep track of all driver fares in real time. Each driver sets a base fare (an integer). Drivers can join or leave the system at any time, and riders can ask questions about the fares. The system should support four operations:
I X : Add a driver with fare X (ignore if already present).
D X :  Remove the driver with fare X (ignore if not present).
R X :  Find the rank of fare X (rank means its position in the sorted list of fares, starting from 1 for the smallest fare). If X is not present, print -1.
K K :  Find the K-th cheapest fare among all active drivers. If fewer than K drivers exist, print -1.
You are given Q operations, and you must process them in order. For every R and K query, print the answer on a new line.

Input Format: 
First line: an integer Q (number of operations).
Next Q lines: each operation in one of the following forms:



I X
D X
R X
K K

Output Format:
For every R or K query, print the result on a new line.

Sample I/p
10
I 300
I 150
I 500
I 100
I 250
R 150
K 3
D 150
R 150
K 3

Output:
2
250
-1
300#include <stdio.h>
#include <stdlib.h>

// -------- AVL Node Definition --------
struct Node {
    int key;
    int height;
    int size;
    struct Node *left, *right;
};

// -------- Utility Functions --------
int height(struct Node* n) { return n ? n->height : 0; }
int size(struct Node* n)   { return n ? n->size : 0; }

void update(struct Node* n) {
    if (n) {
        n->height = 1 + (height(n->left) > height(n->right) ? height(n->left) : height(n->right));
        n->size   = 1 + size(n->left) + size(n->right);
    }
}

int getBalance(struct Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->height = 1;
    node->size = 1;
    node->left = node->right = NULL;
    return node;
}

// -------- Rotations --------
struct Node* rotateRight(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    update(y);
    update(x);

    return x;
}

struct Node* rotateLeft(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    update(x);
    update(y);

    return y;
}

// -------- Balancing --------
struct Node* balance(struct Node* n) {
    update(n);
    int bf = getBalance(n);

    if (bf > 1) {
        if (getBalance(n->left) < 0)
            n->left = rotateLeft(n->left);
        return rotateRight(n);
    }
    if (bf < -1) {
        if (getBalance(n->right) > 0)
            n->right = rotateRight(n->right);
        return rotateLeft(n);
    }
    return n;
}

// -------- Insert --------
struct Node* insert(struct Node* root, int key) {
    if (!root) return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // ignore duplicates
    return balance(root);
}

// -------- Delete --------
struct Node* minValueNode(struct Node* n) {
    struct Node* curr = n;
    while (curr->left) curr = curr->left;
    return curr;
}

struct Node* erase(struct Node* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = erase(root->left, key);
    else if (key > root->key)
        root->right = erase(root->right, key);
    else {
        // node found
        if (!root->left || !root->right) {
            struct Node* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        } else {
            struct Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = erase(root->right, temp->key);
        }
    }
    return balance(root);
}

// -------- Queries --------
int getRank(struct Node* root, int key) {
    if (!root) return -1;
    if (key == root->key) {
        return size(root->left) + 1;
    } else if (key < root->key) {
        return getRank(root->left, key);
    } else {
        int r = getRank(root->right, key);
        if (r == -1) return -1;
        return size(root->left) + 1 + r;
    }
}

int getKth(struct Node* root, int k) {
    if (!root || k <= 0 || k > size(root)) return -1;
    int leftSize = size(root->left);
    if (k == leftSize + 1)
        return root->key;
    else if (k <= leftSize)
        return getKth(root->left, k);
    else
        return getKth(root->right, k - leftSize - 1);
}

// -------- Driver Code --------
int main() {
    int Q; 
    scanf("%d", &Q);
    struct Node* root = NULL;

    while (Q--) {
        char op; int x;
        scanf(" %c %d", &op, &x);
        if (op == 'I') root = insert(root, x);
        else if (op == 'D') root = erase(root, x);
        else if (op == 'R') printf("%d\n", getRank(root, x));
        else if (op == 'K') printf("%d\n", getKth(root, x));
    }
    return 0;
}











Problem Statement
You are given a list of elements, including possible null values, to create a Binary Search Tree (BST). 

Input:
1. Number of elements (N): An integer representing the total number of elements
2. Elements: A list of integers

Output:
Print the in-order traversal of the constructed BST, omitting the `null` values.

Example:

Input:
Number of elements: 5
Elements: 50, 30, 20, 40, 70

Output:
In-order Traversal: 20, 30, 40, 50, 70

Explanation:
The constructed BST is:
       50
      /  \
    30   70
   /  \
 20   40

Hence, the "in-order" traversal is => 20, 30, 40, 50, 70


#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
    vector<int> inOrderTraversal() {}
};

int main() {
    int n;
    cin >> n;
    
    BST bst;
    
    vector<int> inOrder = bst.inOrderTraversal();
    for (int val : inOrder) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}


Problem Statement Ash has two binary trees, “Tree-1" and “Tree-2”, where each node of the tree has a positive integer value. Now Ash wants to give these trees to Serena, but he can't decide which Tree should be gifted. So to keep the good traits of both the trees, he decides to merge them in a common binary tree and gift this merged tree to Serena. But since Ash is good in catching Pokemons and not in coding, you need to help him in merging these binary trees. Rules: 1. If two nodes overlap, the sum of their values should be the new value of the merged node and If either node in the overlapping position is null, the non-null node should be used as the value of the new node. 2. The binary tree contains only positive integer elements. -1 denotes a null node. Input Format: First line contains a single integer n, denoting the number of nodes in the 1st binary tree. Second line contains the n integers, nodes of the 1st binary tree in level order. Third line contains a single integer m, denoting the number of nodes in the 2nd binary tree. Fourth line contains the m integers, nodes of the 2nd binary tree in level order. Output Format: Print the inorder traversal of the merged binary tree. Sample Input: 7 1 2 3 -1 4 -1 5 7 1 2 2 6 -1 7 -1 Output: 6 4 4 2 7 5 5 #include <iostream> #include <vector> using namespace std; class node { public: int data; node* left; node* right; node(int val) : data(val), left(nullptr), right(nullptr) {} }; class binary_tree { public: node* root = nullptr; void make_binary_tree_from_array(vector<int>& arr) { this->root = construct_binary_tree_from_level_order_array(arr, 0); } node* construct_binary_tree_from_level_order_array(vector<int>& arr, size_t index) { //Implement your code Here }; // Merge Trees Function node* merge_trees(node* root1, node* root2) { //Implement your code here } // Inorder Traversal void inorder(node* root) { //Implement your code here } int main() { int n, m; cin >> n; vector<int> arr(n); for (int i = 0; i < n; i++) cin >> arr[i]; // Take the level-order of Tree 1 cin >> m; vector<int> brr(m); for (int i = 0; i < m; i++) cin >> brr[i]; // Take the level-order of Tree 2 binary_tree tree1, tree2; tree1.make_binary_tree_from_array(arr); tree2.make_binary_tree_from_array(brr); node* mergedRoot = merge_trees(tree1.root, tree2.root); inorder(mergedRoot); // Print the inorder traversal of the merged tree cout << endl; return 0; }

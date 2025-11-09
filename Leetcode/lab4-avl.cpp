#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}

    // Destructor to clean up dynamically allocated nodes
    ~TreeNode() {
        delete left;
        delete right;
    }
};

// Function to create a new node
TreeNode* createNode(int value) {
    if (value == -1) return nullptr; // -1 is used to denote null nodes
    return new TreeNode(value);
}

// Function to insert nodes in level order
TreeNode* insertLevelOrder( vector<int>& arr, TreeNode* root, int i, int n) {
representation of a tree, construct the binary tree
    // TODO: Implement the function
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        for(int i = 0;i < size;i++){
            TreeNode* curr = q.push();
            
        }
    }
}

// Function to print the tree in pre-order
void printPreorder(TreeNode* node) {
    // Print the nodes of a binary tree in preorder
    // TODO: Implement the function
}

int main() {
    // DO NOT MODIFY THIS
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    TreeNode dummy(0);;
    TreeNode* root = &dummy;
    root = insertLevelOrder(arr, root, 0, n);

    printPreorder(root);
    cout << endl;

    // Clean up memory
    delete root;

    return 0;
}
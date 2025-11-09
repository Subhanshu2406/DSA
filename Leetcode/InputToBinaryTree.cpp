#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
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
    // TODO: Implement the function
    queue<TreeNode*> q;
    root = new TreeNode(arr[0]);
    i++;
    q.push(root);

    while(!q.empty() && i < n){
        int size = q.size();
        for(int counter = 0; counter < size; counter++){
            TreeNode* curr = q.front();

            curr -> left = createNode(arr[i]);
            if(curr -> left) q.push(curr -> left);
            i++;

            curr -> right = createNode(arr[i]);
            if(curr -> right) q.push(curr -> right);
            i++;

            q.pop();
        }
    }
    return root;
}

bool isBalanced(TreeNode* root){
    stack<TreeNode*> stk;
    stack<bool> visit;
    stk.push(root);
    visit.push(false);
    unordered_map<TreeNode*,int> height;

    while(!stk.empty()){
        TreeNode* curr = stk.top();
        bool flag = visit.top();
        stk.pop();
        visit.pop();
        if(curr){
            if(flag){
                int left = (curr -> left) ? height[curr -> left] : 0;
                int right = (curr -> right) ? height[curr -> right] : 0;
                height[curr] = max(left,right) + 1;
                if(abs(left - right) > 1) return false;
            }
            else{
                stk.push(curr);
                visit.push(true);
                stk.push(curr -> right);
                visit.push(false);
                stk.push(curr -> left);
                visit.push(false);
            }
        }
    }
    return true;
}


int main() {
    // DO NOT MODIFY THIS
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    TreeNode* root = insertLevelOrder(arr, nullptr, 0, n);
    cout << (isBalanced(root) ? "true" : "false");
    cout << endl;

    // Clean up memory
    delete root;

    return 0;
}
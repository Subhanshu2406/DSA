#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this -> val = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;
    BinaryTree(){
        root = nullptr;
    }

    // TODO: Implement buildTree() to create binary tree from level order input
    Node* buildTree(const vector<int>& arr){
        if(arr.size() == 0) return nullptr;
        Node* head = new Node(arr[0]);
        queue<pair<Node*,int>> q;
        q.push({head, 0}); 

        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size; i++){
                Node* curr = q.front().first;
                int currindex = q.front().second;

                if(currindex * 2 + 1 < arr.size()) curr -> left = new Node(arr[currindex * 2 + 1]);
                if(currindex * 2 + 2 < arr.size()) curr -> right = new Node(arr[currindex * 2 + 2]);


                q.pop();
                if(currindex * 2 + 1 < arr.size()) q.push({curr -> left, currindex * 2 + 1});
                if(currindex * 2 + 2 < arr.size()) q.push({curr -> right, currindex * 2 + 2});
            }
        }
        return head;
    }

    // TODO: Implement isHeap() to check if the tree satisfies heap property
    bool isHeap(Node* root){
        if(!root) return true;
        if(root -> left && root -> left -> val > root -> val) return false;
        if(root -> right && root -> right -> val > root -> val) return false;

        return isHeap(root -> left) && isHeap(root -> right);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    BinaryTree bt;
    Node* root = bt.buildTree(arr);

    // TODO: Call isHeap() and print "true" or "false"
    if(bt.isHeap(root)) cout << "true";
    else cout << "false";
    return 0;
}
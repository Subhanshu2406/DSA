#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) { ch = c; freq = f; left = right = nullptr; }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        // TODO: return true if a.freq > b.freq
        return false;
    }
};

class Huffman {
private:
    Node* root;

    void generateCodes(Node* node, string code, unordered_map<char,string>& codes) {
        // TODO: Recursively generate codes for each leaf
    }

public:
    Huffman(vector<char>& chars, vector<int>& freq) {
        // TODO: Build Huffman Tree using min-heap
        root = nullptr;
    }

    void printCodes() {
        unordered_map<char,string> codes;
        generateCodes(root, "", codes);
        // TODO: print codes for each character
    }
};

int main() {
    int n;
    cin >> n;
    vector<char> chars(n);
    vector<int> freq(n);
    for (int i = 0; i < n; i++) cin >> chars[i];
    for (int i = 0; i < n; i++) cin >> freq[i];

    Huffman h(chars, freq);
    h.printCodes();

    return 0;
}
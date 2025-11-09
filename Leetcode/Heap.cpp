#include <iostream>
#include <vector>
using namespace std;

class HeapSort {
private:
    vector<int> arr;

    // TODO: Write the heapify function here
    void heapify(int n, int i) {
        // Your code here
        int largest = i;       // assume root is largest
        int left = 2*i + 1;    // left child (0-based indexing)
        int right = 2*i + 2;   // right child

        // Check if left child exists and is greater than root
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // Check if right child exists and is greater than current largest
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // If largest is not root, swap and heapify affected subtree
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(n, largest);  // recursive call
        }
        return;
    }

public:
    // TODO: Constructor to initialize arr
    HeapSort(const vector<int>& input) {
        // Your code here
        for(int i = 0;i < input.size(); i++){
            arr.push_back(input[i]);
        }
    }

    // TODO: Implement the sort() function
    void sort() {
        // Step 1: Build a max heap
        int size = arr.size();
        for(int i = size/2 - 1; i >= 0; i--){
            heapify(size, i);
        }

        // Step 2: Repeatedly extract the largest element and rebuild heap
        for(int i = 0;i < size; i++){
            swap(arr[0], arr[size - i - 1]);
            heapify(size - i - 1, 0);
        }
    }

    // TODO: Implement display() function
    void display() const {
        // Print array elements separated by spaces
        for(int i = 0; i < arr.size() ; i++){
            cout << arr[i] << " ";
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];

    // TODO: Create HeapSort object, call sort(), and display()
    HeapSort obj(input);
    obj.sort();
    obj.display();
    
    return 0;
}
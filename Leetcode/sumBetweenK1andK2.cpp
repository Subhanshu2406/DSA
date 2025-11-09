#include <iostream>
#include <vector>
using namespace std;

// TODO: Write a function to min-heapify a subtree rooted at index 'i'
void minheapify(vector<int>& arr, int i, int heapSize) {
    // Your code here
    if(i >= heapSize) return;

    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if(left < heapSize && arr[left] < arr[smallest]) smallest = left;
    if(right < heapSize && arr[right] < arr[smallest]) smallest = right;

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        minheapify(arr, smallest, heapSize);
    }
    return;
}

// TODO: Write function to compute sum between k1-th and k2-th smallest
int sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
    int n = arr.size();
    // Step 1: Build the min-heap
    for(int i = n/2 - 1; i >= 0; i--){
        minheapify(arr, i, n);
    }

    // Step 2: Remove smallest elements until k1-th smallest
    for(int i = 0; i < k1 ; i++){
        swap(arr[0], arr[n - 1 - i]);
        minheapify(arr, 0, n - 1 - i);
    }

    // Step 3: Continue removing and summing until (k2 - 1)-th smallest
    int res = 0;
    for(int i = k1 ; i < k2 - 1; i++){
        res += arr[0];
        swap(arr[0], arr[n - 1 - i]);
        minheapify(arr, 0, n - 1 - i);
    }
    // Step 4: Return the total sum
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k1, k2;
    cin >> k1 >> k2;

    cout << sumBetweenK1K2(arr, k1, k2);

    return 0;
}
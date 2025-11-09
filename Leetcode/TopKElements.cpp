#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// Function to find top K frequent elements using min-heap
vector<int> topKFreq(vector<int>& arr, int k) {
    unordered_map<int,int> freq;

    // Step 1: Count frequency of each element
    for(int num : arr)
        freq[num]++;

    // Step 2: Declare min-heap with custom comparator
    auto cmp = [](pair<int,int> a, pair<int,int> b){
        // TODO: Implement comparator
        // Hint: Smaller frequency first, if tie → smaller element first
        if(a.second > b.second) return true;
        else if(a.second < b.second) return false;
        else{
            if(a.first > b.first) return true;
            else if(a.first < b.first) return false;
        } 
        return false; 
    };

    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

    // Step 3: Push all frequency-element pairs into min-heap
    //         Maintain heap size <= k

    for(auto &p : freq){
        // TODO: push pair into heap
        // TODO: if heap size > k, pop the top element
        pq.push({p.first, p.second});
        while(pq.size() > k) pq.pop();
    }

    // Step 4: Extract elements from heap into a vector
    vector<int> res;
    // TODO: Pop all elements from heap and add to res
    while(!pq.empty()) {
        res.push_back(pq.top().first);
        pq.pop();
    }

    // Step 5: Reverse vector to get most frequent elements first
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int k;
    cin >> k;

    vector<int> result = topKFreq(arr, k);

    for(int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
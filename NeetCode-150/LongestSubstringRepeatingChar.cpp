// brute force method:
//     1. start with a empty string s at index 1
//     2. iterate to the next characters and add them to the string if the char is unique
//     3. if char is not unique, we find the index where it appeared first as i and then start a new stirng from i+1
//     4. before starting the new string we calculate the len of the prev string and compare with the max len and update accordingly
//     5. continue till we reach the end 
// However this will result in a O(n2) solution.


//my first try at implementing sliding window
//this solution although best and avg case is O(n), i used clear() everytime it needed to break the string which causes this to become O(n^2).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 1;
        int maxSize = 1;
        int counter = 1;
        int size = s.size();
        unordered_map<char,int> map = {{s[l],l}};

        if(size == 0 || size == 1) return size;

        while(r < size){
            if(map.count(s[r])){
                if(counter > maxSize) maxSize = counter;
                l = map[s[r]] + 1;
                r = l + 1;
                map.clear();
                map[s[l]] = l;
                counter = 1; 
            }

            else{
                counter++;
                map[s[r]] = r;
                r++;
            }
        }

        if(counter > maxSize) maxSize = counter;

        return maxSize;

        }
};



//now above i was bringing back the right pointer back whenever we found a duplicate but that leads to O(n^2) sol
//thats why now we always move l,r righwards as thats the correct sliding window method, we will just keep moving l rightwards till we encouter the duplicate char.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size == 0 || size == 1) return size;
        int l = 0;
        int r = 1;
        int max = 0;
        int counter = 1;
        unordered_set<char> set = {s[l]};

        while(r < size){
            while(set.find(s[r]) != set.end()){
                set.erase(s[l]);
                l++;
                counter--;
            }

            set.insert(s[r]);
            r++;
            counter++;
            max = max(max,counter);
        }

        return max;
    }
};
class Solution {
    public:
        bool isPalindrome(string s) {
            vector<char> arr{};
            for(char c : s)
            {
                if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                    arr.push_back(tolower(c));
                }
            }
            int sizeofArray = arr.size();

            if(sizeofArray == 0) return true;

            char* begin = &arr[0];
            int prefix = 0 ;
            int suffix = sizeofArray - 1;

            while(prefix<suffix){
                if(begin[prefix] != begin[suffix]) return false;
                prefix++;
                suffix--;
            }
            return true;
        }
    };
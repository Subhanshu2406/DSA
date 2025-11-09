class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> vec;
        ListNode* it = head;
        int counter = 0;
        while(it){
            vec.push_back(it);
            counter++;
        }
        int index = counter - n;
        vec[index] = vec[index] -> next;
        return head;

    }
};

//recursion method
class Solution {
public:

    ListNode* helper(ListNode* head, int &n){
        if(!head) return head;

        head -> next = helper(head -> next, n);
        n--;
        if(n == 0) return head -> next ;
        return head;

    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return helper(head, n);
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;
        head = &dummy;
        ListNode* tail = head;
        while(tail -> next){
            tail = reverse(tail,k);
        }
        return dummy.next;
    }

    ListNode* reverse(ListNode* tail, int k){
        stack<ListNode*> stk;
        ListNode* temptail = tail;
        for(int i = 0;i < k; i++){
            if(!tail -> next) return tail;
            tail = tail -> next;
        }

        tail = temptail;
        for(int i = 0; i < k; i++){
            if(tail -> next) stk.push(tail -> next);
            else break;
            tail = tail -> next;
        }

        ListNode* nextGroup = tail -> next;
        tail = temptail;
        while(!stk.empty()){
            tail -> next = stk.top();
            stk.pop();
            tail = tail -> next;
        }
        tail -> next = nextGroup;
        return tail;
    }
};


// for prutor i did it using stack, just use ther reverse linked list logic via iteration to get constant space complexity
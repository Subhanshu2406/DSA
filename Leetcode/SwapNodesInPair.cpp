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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        head = &dummy;
        ListNode* tail = head;
        while(tail -> next && tail -> next -> next){
            ListNode* temp = tail -> next -> next -> next;
            ListNode* temp2 = tail -> next -> next;
            tail -> next -> next -> next =  tail -> next;
            tail -> next -> next = temp;
            tail -> next = temp2;
            tail = tail -> next -> next;
        }

        return dummy.next;
    }
};
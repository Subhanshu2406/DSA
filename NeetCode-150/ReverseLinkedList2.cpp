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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy;
        dummy.next = head;
        head = &dummy;
        ListNode* tail = head;
        for(int i = 0;i < left - 1;i ++){
            tail = tail -> next;
        }
        ListNode* prev = tail;
        ListNode* curr = tail -> next;
        ListNode* after = curr -> next;
        for(int i = left;i < right;i++){
            curr -> next = prev;
            prev = curr;
            curr = after;
            after = after -> next;
        }
        curr -> next = prev;
        tail -> next -> next = after;
        tail -> next = curr;
        return dummy.next;
    }
};
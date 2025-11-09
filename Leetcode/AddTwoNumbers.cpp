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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* it = nullptr;
        int sum = 0;
        int carry = 0;

        while(l1 && l2){
            ListNode* temp = new ListNode();
            if(!head){
                head = temp;
                it = head;
            }
            else{
                it -> next = temp;
                it = it -> next;
            }

            sum = l1 -> val + l2 -> val + carry;
            carry = sum / 10;
            sum = sum % 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
            it -> val = sum;
        }

        while(l1){
            ListNode* temp = new ListNode();
            it -> next = temp;
            it = it -> next;
            sum = l1 -> val + carry;
            carry = sum /10;
            sum = sum % 10;
            it -> val = sum;
            l1 = l1 -> next;
        }

        while(l2){
            ListNode* temp = new ListNode();
            it -> next = temp;
            it = it -> next;
            sum = l2 -> val + carry;
            carry = sum /10;
            sum = sum % 10;
            it -> val = sum;
            l2 = l2 -> next;
        }
        if(carry){
            ListNode* temp = new ListNode();
            it -> next = temp;
            it -> next -> val = carry;
        }

        return head;
    }
};

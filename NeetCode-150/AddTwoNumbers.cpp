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
        int num1 = 0;
        int num2 = 0;
        int counter1 = 1;
        int counter2 = 1;

        while(l1){
            num1 = num1 + ((l1 -> val) * counter1);
            counter1 *= 10;
            l1 = l1 -> next;
        }

        while(l2){
            num2 = num2 + ((l2 -> val) * counter2);
            counter2 *= 10;
            l2 = l2 -> next;
        }

        int num3 = num1 + num2;

        ListNode* head = nullptr;
        ListNode* it = nullptr;
        while(num3){
            ListNode* temp = new ListNode();
            if(!head){
                head = temp;
                it = head;
                it -> val = num3 % 10;
                num3 = num3/10;
                continue;
            } 
            it -> next = temp;
            it = it -> next;
            it -> val = num3 % 10;
            num3 = num3/10;
        }
        return head;
    }
};
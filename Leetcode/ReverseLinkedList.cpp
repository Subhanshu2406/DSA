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
    ListNode* reverseList(ListNode* head) {
        if(head -> next == nullptr) return head; //edge case

        ListNode* head2 = nullptr;      //new list head
        ListNode* temp = head;          //old list iterator
        while(temp != nullptr){
            ListNode* newNode = new ListNode();
            newNode -> val = temp -> val;
            newNode -> next = nullptr;
            head2 = newNode;
            temp = temp -> next;

        }

        return head2;
    }
};


//without using a second linked list and using iteration

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        head = nullptr;

        while(curr != nullptr){
            ListNode* after = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = after;
        }
        head = prev;
        return head;
    }
};


//using recursion

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* newHead = head; 
        if(head -> next != nullptr){
            newHead = reverseList(head -> next);
            head->next->next = head;
        }
        head -> next = nullptr;
        return newHead;
            

    }
};
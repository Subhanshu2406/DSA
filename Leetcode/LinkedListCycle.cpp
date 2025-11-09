/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //O(n) space complexity solution
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while(head){
            if(!set.insert(head).second) return true;
            head = head->next;
        }
        return false;
    }
};

//now we will use the slow and fast pointer approach for O(1) space complexity.
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow && fast->next){
            if(slow == fast) return true;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return false;
    }
};
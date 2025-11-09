/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        helper(head);
        return head;
    }

    Node* helper(Node* head){
        if(!head) return nullptr;
        if(!head -> next && !head -> child) return head;
        if(!head -> child) return helper(head -> next);

        Node* childMapTail = helper(head -> child);
        Node* nextNode = head -> next;
        head -> next = head -> child;
        head -> child -> prev = head;
        head -> child = nullptr;
        childMapTail -> next = nextNode;
        if(nextNode) {
            nextNode -> prev = childMapTail;
            return helper(nextNode);
        }
        return childMapTail;
    }
};
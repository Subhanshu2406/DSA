class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode* newHead = nullptr;
        ListNode* it = nullptr;
        if(list1 -> val <= list2 -> val){
            newHead = list1;
            list1 = list1 -> next;
        }
        else{
            newHead = list2;
            list2 = list2 -> next;
        }
        it = newHead;
        
        while(list1 && list2){
            if(list1 -> val <= list2 -> val){
                it -> next = list1;
                it = it -> next;
                list1 = list1 -> next;
            }
            else{
                it -> next = list2;
                it = it -> next;
                list2 = list2 -> next;
            }
        }
        if(list1 != nullptr) list2 -> next = list1;
        if(list2 != nullptr) list1 -> next = list2;
        
        return newHead;
    }
};
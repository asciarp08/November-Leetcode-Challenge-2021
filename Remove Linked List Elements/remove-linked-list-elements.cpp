/**
Time = O(n)
Space = O(1)
**/


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* prev = NULL;
        ListNode* cur = head;
        
        while(cur!=NULL){
            if(cur->val!=val){
                prev = cur;
            }
            else{
                if(prev==NULL && head==cur){
                    head = head->next;
                    
                }
                else{
                    ListNode* next = cur->next;
                    prev->next = next;
                    
                }
            }
            
            cur = cur->next;
        }
        return head;
    }
};

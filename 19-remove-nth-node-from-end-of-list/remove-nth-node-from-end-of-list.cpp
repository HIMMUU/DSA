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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0 ; 
        ListNode * temp = head ; 
        while( temp  != NULL){
            size++;
            temp = temp->next ;
        }
        
        int trv = size - n; 
        if( n == size  ) {
            if( size > 1){
                ListNode * tmep = head->next ; 
                head->next == NULL ; 
                head = tmep ; 
                return head;
             
            }else
            return NULL; }
        ListNode * curr = head ; 
        ListNode * next = head ; 
        
        while(trv > 0 && next->next  != NULL ){
            curr = next ; 
            next = next->next ; 
            trv--;
        }
        curr->next = next->next ; 
        next->next = NULL ; 
        return head ;

    }
};
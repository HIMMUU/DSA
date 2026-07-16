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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        int size = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        k = k%size ;
        for (int i = 0; i < k; i++) {
            ListNode* curr = head;
            ListNode* neext = head;
            while (neext->next != NULL) {
                curr = neext;
                neext = neext->next;
            }

            neext->next = head;
            curr->next = NULL;
            head = neext;
        }
        return head;
    }
};
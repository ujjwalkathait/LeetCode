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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        ListNode *temp = head;
        int n = 0;
        while(temp){
            temp = temp->next;
            n++;
        }
        if(n < k){
            return head;
        }
        int i = 0;
        ListNode *curr = head, *forward = NULL, *prev = NULL;
        while(curr!=NULL && i < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            i++;
        }

        if(forward != NULL){
            head->next = reverseKGroup(forward, k);
        }
        return prev;
    }
};
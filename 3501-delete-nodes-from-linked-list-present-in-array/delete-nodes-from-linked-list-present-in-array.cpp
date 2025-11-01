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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> mp;
        for(auto x: nums){
            mp[x]++;
        }
        if(head == NULL){
            return head;
        }
        while(mp[head->val] == 1){
            head = head->next;
        }
        ListNode *prev = head;
        ListNode *curr = head->next;
        while(curr){
            if(mp[curr->val] == 1){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                prev = curr;   
                curr = curr->next;
            }
        }
        return head;
        
    }
};
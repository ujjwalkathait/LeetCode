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
        int sum = 0;
        ListNode *temp = l1, *temp1 = l2;
        while(temp && temp1){
            sum += (temp->val + temp1->val);
            temp->val = sum%10;
            sum /= 10;
            temp = temp->next;
            temp1 = temp1->next;
        }
        while(temp){
            sum += temp->val;
            temp->val = sum%10;
            sum /= 10;
            temp = temp->next;
        }
        temp = l1;
        while(temp->next)
            temp = temp->next;
        while(temp1){
            sum += temp1->val;
            temp1->val = sum%10;
            temp->next = temp1;
            sum /= 10;
            temp = temp->next;
            temp1 = temp1->next;
        }
        temp = l1;
        while(temp->next)
            temp = temp->next;
        if(sum != 0){
            ListNode *NODE = new ListNode;
            NODE->val = sum;
            temp->next = NODE;
            NODE->next = NULL;

        }
        return l1;

        // ListNode* dummy=new ListNode();
        // ListNode* temp=dummy;
        // int carry=0;
        // while(l1!=NULL || l2!=NULL || carry){
        //     int sum=0;
        //     if(l1!=NULL){
        //         sum+=l1->val;
        //         l1=l1->next;
        //     }
        //     if(l2!=NULL){
        //         sum+=l2->val;
        //         l2=l2->next;
        //     }
        //     sum+=carry;
        //     carry=sum/10;
        //     ListNode* newnode=new ListNode(sum%10);
        //     temp->next=newnode;
        //     temp=temp->next;
        // }
        // return dummy->next;
    }
};
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
    void insertInList(ListNode **head,int value){
        ListNode *temp = new ListNode;
        temp->val = value;
        if((*head)==NULL){
            temp->next = (*head);
            (*head) = temp;
        }
        else{
            ListNode *temp1=(*head);
            while(temp1->next!=NULL){
                temp1=temp1->next;
            }
            temp->next=temp1->next;
            temp1->next = temp;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head1=list1,*head2=list2,*head3=NULL;
        // cout<<"running 0"<<endl;
        while(head1!=NULL && head2!=NULL){
            // cout<<"running while"<<endl;
            if(head1->val<=head2->val){
                insertInList(&head3,head1->val);
                if(head1->val==list1->val){
                    list1=list1->next;
                }
                head1=head1->next;
                cout<<"running 1"<<endl;
            }
            else{
                insertInList(&head3,head2->val);
                if(head2->val==list2->val){
                    list2=list2->next;
                }
                head2=head2->next;
                cout<<"running 2"<<endl;
                
            }
        }
        while(head1!=NULL){
            insertInList(&head3,head1->val);
            head1=head1->next;
        }
        // cout<<"running 5"<<endl;
        while(head2!=NULL){
            insertInList(&head3,head2->val);
            head2=head2->next;
        }
        // cout<<"running 6"<<endl;
        return head3;
    }
};
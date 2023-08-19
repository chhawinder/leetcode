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
    ListNode* reversell(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode*prev=NULL;
        ListNode*nxt=head->next;
        while(head!=NULL){
            head->next=prev;
            prev=head;
            head=nxt;
            if(nxt!=NULL)
            nxt=nxt->next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1=reversell(l1);
        l1=temp1;
        ListNode*temp2=reversell(l2);
        int carry=0;
        while(temp1&&temp2){
            int sum=temp1->val+temp2->val+carry;
            temp1->val=sum%10;
            carry=sum/10;
            temp1=temp1->next;temp2=temp2->next;
        }
        if(temp1){
            ListNode*k=temp1;
            while(carry&&temp1){
                int sum=temp1->val+carry;
                temp1->val=sum%10;
                carry=sum/10;
                temp1=temp1->next;
            }
            
        }
        if(temp2){
            ListNode*k=l1;
            while(k->next)k=k->next;
            k->next=temp2;
            while(carry&&temp2){
                int sum=temp2->val+carry;
                temp2->val=sum%10;
                carry=sum/10;
                temp2=temp2->next;
            }
        }
        
        if(carry){
                ListNode*k=l1;
                while(k->next)k=k->next;
                ListNode*newnode=new ListNode(carry);
                k->next=newnode;
                
            }
        return reversell(l1);
    }
};
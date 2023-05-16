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
    void swap(ListNode*t,ListNode*t2,ListNode*pre){
        ListNode*k=t2->next;
        t2->next=t;
        if(pre!=NULL)
        pre->next=t2;
        t->next=k;
        return ;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)return head;
        ListNode*temp2=head->next;
        ListNode*temp=head;
        ListNode*pre=NULL;
        while(temp!=NULL&&temp2!=NULL){
            swap(temp,temp2,pre);
            if(pre==NULL)
            head=temp2;
            pre=temp;
            temp=temp->next;
            if(temp!=NULL)
            temp2=temp->next;
            
        }
        return head;
    }
};
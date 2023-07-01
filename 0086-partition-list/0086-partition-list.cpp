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
    ListNode* partition(ListNode* head, int x) {
        ListNode*l=nullptr;
        ListNode*tl=nullptr;

        ListNode*r=nullptr;
                ListNode*tr=nullptr;

        ListNode*temp=head;
        while(temp){
            if(temp->val<x){
                if(l==nullptr){
                    l=tl=temp;
                    
                }else{
                    tl->next=temp;
                    tl=tl->next;
                }
              
            }else{
                if(r==nullptr){
                    r=tr=temp;
                    
                }else{
                    tr->next=temp;
                    tr=tr->next;
                }
            }
              temp=temp->next;
        }
        if(l){
            tl->next=r;
            if(tr)
            tr->next=NULL;
            return l;
        }
        return r;
    }
};
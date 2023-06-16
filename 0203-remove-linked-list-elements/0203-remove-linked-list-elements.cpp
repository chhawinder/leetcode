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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*pre=NULL;
        ListNode*curr=head;
       
        while(curr!=NULL){
            
            if(curr->val==val){
                if(pre==NULL){
                    curr=head=curr->next;
                }else{
                     pre->next=curr->next;
                curr=pre->next;
                }
               
            }else{
                pre=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};
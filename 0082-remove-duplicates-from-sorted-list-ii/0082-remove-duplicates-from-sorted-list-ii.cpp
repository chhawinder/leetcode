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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)return head;
        ListNode*temp=head;
        ListNode*pre=NULL;
        while(temp&&temp->next){
            if(temp->next->val==temp->val){
                if(temp==head){
                    while(temp->next&&temp->next->val==temp->val){
                        temp=temp->next;
                    }
                    head=temp->next;
                }else{
                    while(temp->next&&temp->next->val==temp->val){
                    temp=temp->next;
                }
                pre->next=temp->next;
                }
                
                
            }
            else pre=temp;
            temp=temp->next;
        }
        return head;
    }
};
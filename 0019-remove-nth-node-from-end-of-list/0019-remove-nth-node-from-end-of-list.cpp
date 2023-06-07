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
    int length(ListNode* head){
        int n=0;
        while(head){
            n++;
            head=head->next;
        }
        return n;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL)return head;
        int k=length(head)-n-1;
        if(k<0)return head->next;
        ListNode*temp=head;
        while(k--){
            temp=temp->next;
            
        }
        temp->next=temp->next->next;
        return head;
    }
};
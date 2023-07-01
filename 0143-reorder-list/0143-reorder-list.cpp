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
    int len(ListNode*head){
        int i=0;
        while(head){
            i++;
            head=head->next;
        }return i;
    }
    void reorderList(ListNode* head) {
        ListNode*temp=head;
        int l=len(head);
        if(l%2==0)
            l=len(head)/2 -1;
        else
            l=len(head)/2;
        while(l--){
            ListNode*n=temp->next;
            ListNode*k=temp;
            while(temp->next->next){
                temp=temp->next;
            }
            k->next=temp->next;
            temp->next=NULL;
            k->next->next=n;
            temp=n;
            
        }
        
    }
};
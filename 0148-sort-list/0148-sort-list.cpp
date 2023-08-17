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
    
    ListNode*merge(ListNode*l1,ListNode*l2){
        ListNode*head=nullptr;ListNode*temp=nullptr;
        while(l1&&l2){
            if(l1->val<=l2->val){
                if(head==nullptr){
                    head=temp=l1;
                }else{
                    temp->next=l1;
                    temp=temp->next;
                }
                l1=l1->next;
            }else{
                if(head==nullptr){
                    head=temp=l2;
                }else{
                    temp->next=l2;
                    temp=temp->next;
                }
                l2=l2->next;
            }
        }
        if(l1){
            temp->next=l1;
            
        }
        if(l2){
            temp->next=l2;
        }
        return head;
    }
    int len(ListNode*head){
        int i=0;
        while(head){
            i++;
            head=head->next;
        }return i;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        int l=len(head);
        l=l/2;l--;
        ListNode*temp=head;
        while(l--){
            temp=temp->next;
        }
        ListNode*l2=temp->next;
        temp->next=nullptr;
        head=sortList(head);
        l2=sortList(l2);
        ListNode*res=merge(head,l2);
        return res;
        
    }
};
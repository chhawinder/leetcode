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
    ListNode*rev(ListNode*head){
        ListNode*pre=nullptr;
        ListNode*curr=head;
        ListNode*n=head->next;
        while(curr){
            curr->next=pre;
            pre=curr;
            curr=n;
            if(n)
            n=n->next;
            
        }
        return pre;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr)return head;
        ListNode*th=head;
        ListNode*temp=nullptr;
        ListNode* tail=nullptr;
        int i=1;
        while(i<left){
            i++;
            th=th->next;
        }
        temp=th;
        while(i<right){
            i++;
            th=th->next;
        }
        tail=th->next;
        th->next=NULL;
        temp=rev(temp);
        if(left==1)head=temp;
        th=head;
        i=1;
        while(i<left-1){
            i++;
            th=th->next;
        }
        if(left!=1)
        th->next=temp;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=tail;
        return head;
        
        
        
    }
};
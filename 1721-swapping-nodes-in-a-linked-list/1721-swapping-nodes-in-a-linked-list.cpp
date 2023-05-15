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
        int i=0;
        while(head!=NULL){
            head=head->next;
            i++;
        }
        return i;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int p=length(head)-k;
        ListNode*temp1=head;
        ListNode*temp2=head;
        k--;
        while(k--){
            temp1=temp1->next;
        }
        while(p--){
            temp2=temp2->next;
        }
        int n=temp1->val;
        temp1->val=temp2->val;
        temp2->val=n;
        return head;
    }
};
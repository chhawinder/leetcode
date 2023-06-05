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
        }return n;
    }
    int getDecimalValue(ListNode* head) {
        int l=length(head)-1;
        int res=0;
        while(head){
            res+=head->val*pow(2,l--);
            head=head->next;
        }
        return res;
    }
};
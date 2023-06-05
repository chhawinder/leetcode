/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*>c;
       while(head!=NULL){
           if(c.find(head)!=c.end())return true;
           
           c.insert(head);
           head=head->next;
       } 
        return false;
    }
};
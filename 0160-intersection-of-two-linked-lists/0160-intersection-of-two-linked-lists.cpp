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
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        set<ListNode*>s;
        ListNode*temp=h1;
        while(temp){
            s.insert(temp);temp=temp->next;
        }
        temp=h2;
        while(temp){
            if(s.find(temp)!=s.end())return temp;
            temp=temp->next;
        }
        return nullptr;
        
    }
};
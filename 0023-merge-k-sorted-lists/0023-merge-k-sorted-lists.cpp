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
    struct CompareNodes {
        bool operator()(const ListNode* a, const ListNode* b) const {
            return a->val > b->val; // Using '<' for min-heap behavior
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,CompareNodes>pq;
        for(auto it:lists){
            if(it)
            pq.push(it);}
        ListNode*head=nullptr;
        ListNode*temp=nullptr;
        while(pq.size()){
            auto t=pq.top();pq.pop();
            // cout<<t->val<<" ";
            if(t->next){ListNode*n=t->next;pq.push(n);}
            if(head==nullptr){
                head=temp=t;
            }else{
                temp->next=t;
            temp=temp->next;
            }
            
            
        }
        if(temp)temp->next=nullptr;
        return head;
        
    }
};
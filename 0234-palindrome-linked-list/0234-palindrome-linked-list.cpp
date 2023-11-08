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
    // ListNode* reverse(ListNode* n){
    //     ListNode*prev=NULL;
    //     ListNode*curr=n;
    //     ListNode*nx=n->next;
    //     while(curr!=NULL){
    //         curr->next=prev;
    //         prev=curr;
    //         curr=nx;
    //         if(nx!=NULL)
    //         nx=nx->next;
    //     }
    //     return prev;
    // }
    bool isPalindrome(ListNode* head) {
        // ListNode*temp=head;
        // vector<int>c;
        // while(temp!=NULL){
        //     c.push_back(temp->val);
        //     temp=temp->next;
        // }
        // temp=reverse(head);
        // vector<int>p;
        // while(temp!=NULL){
        //     p.push_back(temp->val);
        //     temp=temp->next;
        // }
        // if(p==c)return true;
        // return false;
        
        string s="";
    while(head){
        s+=head->val;
        head=head->next;
    }
    string k=s;
    reverse(s.begin(),s.end());
    return s==k;
    }
};
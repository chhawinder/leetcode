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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*list=nullptr;
        ListNode*head=nullptr;
        while(list1&&list2){
            if(list1->val<list2->val){
                if(list==nullptr){
                    head=list1;
                    list=list1;
                }else{
                   list->next=list1;
                    list=list->next;
                } 
                list1=list1->next;
            }else{
                if(list==nullptr){
                    head=list2;
                    list=list2;
                }else{
                   list->next=list2;
                    list=list->next;
                }
                list2=list2->next;
            }
        }
        if(list1){
            if(list==nullptr){
                    head=list1;
                    list=list1;
                }else
            list->next=list1;
        }
        if(list2){
            if(list==nullptr){
                    head=list2;
                    list=list2;
                }else
            list->next=list2;
        }
        return head;
    }
};
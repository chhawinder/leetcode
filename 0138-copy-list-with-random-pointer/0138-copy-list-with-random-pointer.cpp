/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)return head;
        Node*newnode=new Node(head->val);
	map<Node*,Node*>m;
	m[head]=newnode;
        Node*head2=head;
	head=head->next;
	Node*temp=newnode;
	
	
	while(head){
			Node*nn=new Node(head->val);
			m[head]=nn;
			head=head->next;
			temp->next=nn;
			temp=temp->next;
	}
	Node* tempCopy = newnode;  // New pointer to iterate through the deep copy

	while (head2) {
        if(head2->random!=nullptr){
            tempCopy->random = m[head2->random];
        }
		
		tempCopy = tempCopy->next;
		head2 = head2->next;
	}
return newnode;
    }
};
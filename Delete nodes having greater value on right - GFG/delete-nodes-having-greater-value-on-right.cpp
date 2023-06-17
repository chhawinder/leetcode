//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
      Node*pre=NULL;
      Node*curr=head;
      while(curr->next){
          if(curr->next->data>curr->data){
              if(pre){
                  pre->next=curr->next;
                  Node*temp=head;
                  if(temp==pre){
                      curr=pre;
                      pre=NULL;
                      
                  }else{
                      while(temp->next!=pre){
                      temp=temp->next;
                  }
                  curr=pre;
                  pre=temp;
                }
                  
              }else{
                  head=curr->next;
                  curr=curr->next;
              }
          }else{
              pre=curr;
              curr=curr->next;
          }
      }
      return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends
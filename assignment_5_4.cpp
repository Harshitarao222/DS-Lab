#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val){data=val;next=NULL;}
};
void insert(Node*& head,int val){
    Node* n=new Node(val);
    if(!head){head=n;return;}
    Node* temp=head;
    while(temp->next)temp=temp->next;
    temp->next=n;
}
Node* reverse(Node* head){
    Node* prev=NULL,*curr=head,*next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void display(Node* head){
    while(head){cout<<head->data<<" ";head=head->next;}
    cout<<endl;
}
int main(){
    Node* head=NULL;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){cin>>x;insert(head,x);}
    head=reverse(head);
    display(head);
}

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
int middle(Node* head){
    Node* slow=head,*fast=head;
    while(fast&&fast->next){slow=slow->next;fast=fast->next->next;}
    return slow->data;
}
int main(){
    Node* head=NULL;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){cin>>x;insert(head,x);}
    cout<<middle(head);
}

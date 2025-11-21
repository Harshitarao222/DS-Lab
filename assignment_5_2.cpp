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
int deleteKey(Node*& head,int key){
    int count=0;
    while(head&&head->data==key){Node* del=head;head=head->next;delete del;count++;}
    Node* temp=head;
    while(temp&&temp->next){
        if(temp->next->data==key){Node* del=temp->next;temp->next=del->next;delete del;count++;}
        else temp=temp->next;
    }
    return count;
}
void display(Node* head){
    while(head){cout<<head->data<<" ";head=head->next;}
    cout<<endl;
}
int main(){
    Node* head=NULL;
    int n,x,key;
    cin>>n;
    for(int i=0;i<n;i++){cin>>x;insert(head,x);}
    cin>>key;
    cout<<deleteKey(head,key)<<endl;
    display(head);
}

#include<bits/stdc++.h>
using namespace std;


//making data type
struct Node{
    int data;
    Node* next;
    Node* back;
//constructor
    Node(int val,Node* x,Node* y){
        data=val;
        next=x;
        back=y;
    }
};



//traversal and display
void displayLL(Node* head){
  
    Node* temp=head;
    if(temp==nullptr){
      cout<<"LL is empty "<<endl;
      return;
    }

    //tevel through LL
    while(temp!=nullptr){
        cout<<temp->data;
        temp=temp->next;
        if(temp!=nullptr) cout<<"<->";
    }

}


Node* arrayToDLL(vector<int>&arr){
    if(arr.size()==0) {
         cout<<"array has no el"<<endl;
         return nullptr;
    }
    Node* head=new Node(arr[0],nullptr,nullptr);
    Node* connector=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,connector);
        connector->next=temp;
        connector=temp;
    }
    return head;

}


//----------------Reverse----------------------//

Node* reversell(Node* head){
     if(head==nullptr || head->next==nullptr) return head;
     Node* prev=nullptr;
     Node* curr=head;
     Node* front=nullptr;
     while(curr!=nullptr){
        front=curr->next;
        curr->next=prev;
        curr->back=front;
        prev=curr;
        curr=front;
     }
    return prev;
   

}
//---------------------------------------------//

int main(){
    
  vector<int>arr={3,4,5,6};
  Node* head= arrayToDLL(arr);
  if(head != nullptr) {
        cout << "head -> data : " << head->data << endl;
    }
  //display LL
  displayLL(head);
  cout<<endl;
  
  head=reversell(head);
  if(head != nullptr) {
        cout << "head -> data : " << head->data << endl;
    }
   //display reversed LL
  displayLL(head); 
  cout<<endl;


}
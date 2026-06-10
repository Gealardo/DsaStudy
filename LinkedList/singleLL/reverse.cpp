#include<bits/stdc++.h>
using namespace std;

// new data type holds int+ptr
struct Node{
    int data;
    Node* next;

    ///constructor
    Node(int val,Node* ptr=nullptr){
        data=val;
        next=ptr;
    }
};


//traversal and display
void displayLL(Node* head){
    Node* temp=head;
    if(temp==nullptr){
        cout<<"LL id empty"<<endl;
        return;
    }
    //tevel through LL
    while(temp!=nullptr){
        cout<<temp->data;
        temp=temp->next;
        if(temp!=nullptr) cout<<"->";
    }
    cout<<endl;

}

// making sll
Node* arrayToSLL(vector<int>&arr){
    if(arr.size()==0) {
         cout<<"array has no el"<<endl;
         return nullptr;
    }
    Node* head=new Node(arr[0]);
    Node* connector=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        connector->next=temp;
        connector=temp;
    }
    return head;
}


//----------------Reverse ----------------------//

Node* reversell(Node* head){
      if(head==nullptr || head->next==nullptr) return head;
     
      Node* prev=nullptr;
      Node* curr=head;
      while(curr!=nullptr){
        Node* front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
        }

       
      return prev;

}
//---------------------------------------------//


int main(){
  vector<int>arr={3,4,5,6,7,8};
  Node* head= arrayToSLL(arr);


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
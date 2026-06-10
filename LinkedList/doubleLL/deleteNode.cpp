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


//Making DLL

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

//---------------------Deletion of node-----------------//
Node* delkth(Node* &head,int k){

   //hunt
    
   if(head==nullptr) return nullptr;

   Node* curr=head;
   for(int i=1;i<k && curr!=nullptr;i++){
        curr=curr->next;
   }

   if(curr==nullptr){
    cout<<"position not exist"<<endl;
    return head;
   }

   //surgury
   //no left node
   if(curr->back==nullptr){
    head=head->next;
    if(head!=nullptr) head->back=nullptr;
    delete curr;
    return head;    
   }

   //no right node
   if(curr->next==nullptr){
    curr->back->next=nullptr;
   }


   //having right and left both
   else{
    curr->next->back=curr->back;
    curr->back->next=curr->next;
   }
   delete curr;
   return head;


}

int main(){
    
  vector<int>arr={34,5,6,7};
  Node* head= arrayToDLL(arr);
  if(head != nullptr) {
        cout << "head -> data : " << head->data << endl;
    }
  //display LL
  displayLL(head);


   cout<<endl;
  head=delkth(head,1);
  if(head != nullptr) {
        cout << "head -> data : " << head->data << endl;
    }
  //display LL
  displayLL(head);

  

}
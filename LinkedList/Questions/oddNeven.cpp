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
//----------------------tcO(2N)+scO(N)-------------------------//
vector<int>v;
void oddEven(Node* head) {
    if (!head || !head->next) return;
    Node* temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        v.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) v.push_back(temp->data);
    Node* temp2=head->next;
    while(temp2!=nullptr && temp2->next!=nullptr){
        v.push_back(temp2->data);
        temp2=temp2->next->next;
    }
    if(temp2) v.push_back(temp2->data);

}
//------------------optimal tcO(N)----------------------------//
Node* oddfirstenen(Node* head)
{
    if(head==nullptr || head->next==nullptr) return head;
    Node* even=head->next;
    Node* odd=head;
    Node* evenhead=head->next;
    while(even!=nullptr && even->next!=nullptr){
         //odd ahead even
         odd->next=even->next;
         odd=odd->next;
         //even over odd
         even->next=odd->next;
         even=even->next;
    }
    odd->next=evenhead;
    return head;
}
















//====================================================//

int main(){
  vector<int>arr={31,32,33,34};
  Node* head= arrayToSLL(arr);


 if(head != nullptr) {
        cout << "head -> data : " << head->data << endl;
    }

 //display LL
  displayLL(head);
  cout<<endl;
  
  oddEven(head);
  Node* x= arrayToSLL(v);
  displayLL(x);
  cout<<endl;
   Node* optimizedHead = oddfirstenen(head);
    
    cout << "Optimal Odd-Even LL: ";
    displayLL(optimizedHead);
    cout << endl;
  


}
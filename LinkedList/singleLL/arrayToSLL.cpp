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

// making sll
Node* arrayToSLL(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* connector=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        connector->next=temp;
        connector=temp;
    }
    return head;
}

int main(){
  vector<int>arr={10,20,30};
  Node* head= arrayToSLL(arr);
  cout<<"head -> data : "<<head->data<<endl;
  
}
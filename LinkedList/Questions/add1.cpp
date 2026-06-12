//add 1 in the number represent by linked list.
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
    node(int val){
        data=val;
        next=nullptr;
    }
};

node* ll(vector<int> &arr){
    if(arr.size()==0) return nullptr;
    node* head=new node(arr[0]);
    node* connector=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i]);
        connector->next=temp;
        connector=temp;
    }
    return head;
}

node* rev(node* &head){
    node* curr=head;
    node* prev=nullptr;
    while(curr!=nullptr){
        node*front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }
    return prev;
}

void display(node* head){
    if(head==nullptr) {
        cout<<"linked list is emplty"<<endl;
        return;
    }
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
//.......................................................
node* add_one(node* &head){
    //edhe case

    if(head==nullptr){
        vector<int>arr={1};
       node*newhead=ll(arr);
       return newhead;
    }

    node* newhead=rev(head);
    int carry =1,sum=0;
    node* temp=newhead;
    while(temp!=nullptr){
        sum=carry + temp->data;
        carry=sum/10;
        temp->data=sum%10;
        node*carryprev=temp;
        temp=temp->next;
        if(carry==0) break;
        if(temp==nullptr && carry!=0){
             node*carrynode=new node(carry);
             carryprev->next=carrynode;
             break;
        }

    }
    node* h=rev(newhead);
    return h;
}
//.........................................................

int main(){
    vector<int>arr={9,9,9};
    node*head=ll(arr);
    if(head!=nullptr){
    cout<<"head->data "<<head->data<<endl;
    }
    
    display(head);
    cout<<"after adding one"<<endl;
    node* h=add_one(head);
     display(h);
    
    


}

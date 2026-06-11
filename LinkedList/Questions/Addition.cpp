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

node* makell(vector<int>&no){
     node* head=new node(no[no.size()-1]);
     node* connector=head;
     for(int i=no.size()-2;i>=0;i--){
        node* temp=new node(no[i]);
        connector->next=temp;
        connector=temp;
     }
     return head;
}

node* addno(node* &head1,node*head2){
    int carry=0;
    node* dnode=new node(-1);
    node* t1=head1;
    node* t2=head2;
    node* curr=dnode;
   
    while(t1!=nullptr || t2!=nullptr){
         int sum=carry;
       if(t1) {
        sum=sum+t1->data;
       }
       if(t2) {
        sum=sum+t2->data;
       }
       
       node * newnode=new node(sum%10);
       carry=sum/10;
       curr->next=newnode;
       curr=newnode;

       if(t1) t1=t1->next;
       if(t2) t2=t2->next;

    }
    if(carry) {
        node* newnode=new node(carry);
        curr->next=newnode;
    }
    return dnode->next;
}
void display(node* &head){
    if(head==nullptr) {
        cout<<"empty"<<endl;
    }
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data;
        temp=temp->next;
        if(temp) cout<<"->";
    }
}


int main(){
    vector<int>no1={ 5,6,7,4,9};
    vector<int>no2={1,2,3};
    node* head1=makell(no1);
    node* head2=makell(no2);
    cout<<head1->data<<" "<<head2->data<<endl;

    node* sum=addno(head1,head2);
    display(sum);


}
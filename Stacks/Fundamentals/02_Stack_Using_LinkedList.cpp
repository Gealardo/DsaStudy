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


//push
node* push_in_stack(node* &top,int val){
  if(top==nullptr){
    node* head=new node(val);
    top=head;
  }
  else{
    node* head=new node(val);
    head->next=top;
    top=head;  
  }
  return top;
}

//pop
node* pop_in_stack(node* &top){
  if(top==nullptr){
    cout<<"underflow"<<endl;
    return nullptr;
  }
  else{
    node* temp=top;
    top=top->next;
    delete(temp);
  }
  return top;
}
//peek
void peek_in_stack(node*& top){
   if(top==nullptr) {
    cout<<"stack is empty"<<endl;
    return;
   }
   else{
    cout<<"top is : "<<top->data<<endl;
    return;
   }

}
//display
void display_stack(node* &top){
  if(top==nullptr) {
    cout<<"stack is empty"<<endl;
    return;
  }
  node* temp=top;
  while(temp!=nullptr){
    cout<<temp->data<<"->";
    temp=temp->next;
    if(temp==nullptr){
      cout<<"NULL"<<endl;
    }
  }
  return;
  
}


int main(){
  
  node* top=nullptr;
  
  pop_in_stack(top);
  peek_in_stack(top);
  display_stack(top);

  cout<<"10 pushed : ";
  push_in_stack(top,10);
  display_stack(top);

  cout<<endl;

  cout<<"11 pushed : ";
  push_in_stack(top,11);
  display_stack(top);

  cout<<endl;
  peek_in_stack(top);

  cout<<"top is poped :";
  pop_in_stack(top);
  display_stack(top);

  

}
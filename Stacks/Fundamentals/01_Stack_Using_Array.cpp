#include<bits/stdc++.h>
using namespace std;

//push
void push_in_stack(vector<int>&st,int &top,int val){
     if(top==st.size()-1){
      cout<<"stack is overflow"<<endl;
      return;
     }
     else{
     top++;
     st[top]=val;
     }
}

//pop
void pop_in_stack(vector<int>&st,int &top){
     if(top==-1){
      cout<<"stack is underflow"<<endl;
      return;
     }
     else{
      top--;
     }
}
//peek
void peek_in_stack(const vector<int>&st,int top){
     if(top==-1){
      cout<<"stack is empty"<<endl;
      return;
     }
     else{
      cout<<"top element is: "<<st[top]<<endl;
     }
}
//display
void display_stack(const vector<int>&st,int top){
     if(top==-1){
      cout<<"stack is empty"<<endl;
     }
     else{
      cout<<"stack elements are: ";
      for(int i=0;i<=top;i++){
       cout<<st[i]<<" ";
      }
      cout<<endl;
     }
}

int main(){
  vector<int>st(10);
  int top=-1;

  pop_in_stack(st,top);
  peek_in_stack(st,top);
    display_stack(st,top);
  push_in_stack(st,top,10);
    display_stack(st,top);
  push_in_stack(st,top,20);
    display_stack(st,top);
  pop_in_stack(st,top);
    display_stack(st,top);

}
#include<bits/stdc++.h>
using namespace std;

int st[10];
int top=-1;
void push(int val){
    if(top == 9){
        cout<<"stack is overflow"<<endl;
        return;
    }
    top++;
    st[top]=val;
    cout<<st[top]<<" pushed"<<endl;
}
void pop(){
    if(top==-1) {
        cout<<"stack is empty"<<endl;
        return;
    }
    cout << st[top] << " popped" << endl;
    top--;
    
}
void peek(){
    if(top==-1){
        cout<<"stack is underflow"<<endl;
        return;
    }
    cout << st[top] << " peek" << endl;
   
}
void display_stack(){
    int i=top;
    if(i==-1){
        cout<<"stack is empty"<<endl;
        return;
    }
    cout<<"-------top->bottom---------"<<endl;
    for(int j=i;j>=0;j--){
     cout<<st[j]<<endl;
     if(j!=0)cout<<"^"<<endl;
    }
    cout<<"----------------"<<endl;
}

int main(){
    push(10);
    push(20);
    push(30);
    peek();
    display_stack();
    push(40);
    push(50);
    peek();
    pop();
    peek();
    display_stack();
}

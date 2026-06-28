#include<bits/stdc++.h>
using namespace std;

bool valid_parenthesis(const string s){
   stack<char>st;
   for(auto ch:s){
     if(ch=='{' || ch=='[' || ch=='('){
        st.push(ch);
     }
     else{
        if(st.empty()) return false;

        char top=st.top();
        st.pop();
        if(ch=='(' && top!=')') return false;
        if(ch=='[' && top!=']') return false;
        if(ch=='{' && top!='}') return false; 
     }
   }
   if(st.empty()) return true;
   else return false;
}
int main(){
    string s;
    cout<<"Enter parenthesis string : ";
    cin>>s;
    cout<<endl;
    cout<<"Valid? Ans: "<<valid_parenthesis(s)<<endl;
}
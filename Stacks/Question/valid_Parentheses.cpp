#include<bits/stdc++.h>
using namespace std;

bool valid_parenthesis(string s){
    stack<char>st;
    for(char ch : s){
        if(ch=='(' || ch=='{' ||ch=='['){
            st.push(ch);
        }
        else{
            if(st.empty()) return false;
            char peek=st.top();
            st.pop();
            if (ch == ')' && peek != '(') return false;
            if (ch == '}' && peek != '{') return false;
            if (ch == ']' && peek != '[') return false;
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
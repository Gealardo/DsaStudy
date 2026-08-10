#include<bits/stdc++.h>
using namespace std;

//node creation  
//Tires clas creation
//root cretion
//root initialization
//intsert function
//search function
//startsWith function

class node{
  public:
  node* links[26];
  bool flag;

  node(){
    for(int i=0;i<26;i++){
      links[i]=nullptr;
      flag=false;
    }
  }
  bool alphaExist(char ch){
    return links[ch-'a']!=nullptr;
  }
  void put(char ch,node* newNode){
        links[ch-'a']=newNode;
  }
  node* getNextCh(char ch){
    return links[ch-'a'];
  }
  void setEnd(){
    flag=true;
  }
};

class Tries{
  private: node* root;

  public:
  Tries(){
    root=new node();
  }
  //--------code your functions---------

     void insert(string word){
      node* temp=root;
      for(auto ch:word){
        if(temp->alphaExist(ch)==false){
          temp->put(ch,new node());
        }
        temp=temp->getNextCh(ch);
      }
      temp->setEnd();
     }


     bool startsWith(string word){
        node* temp=root;
       for(auto ch:word){
         if(temp->alphaExist(ch)==false){
          return false;
         }
         temp=temp->getNextCh(ch);
       }
       return true;

     }

  //------------------------------------
};

int main(){

  Tries tries;

  tries.insert("ayun");
  tries.insert("ayush");
  cout<<"Put word to find if any word starts with: ";
  string s;
  cin>>s;
  cout<<tries.startsWith(s)<<endl;


}

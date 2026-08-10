#include<bits/stdc++.h>
using namespace std;

// search function implementation;


//node creation
class node{
  public:
   node*links[26];
   bool flag;

   node(){
    for(int i=0;i<26;i++){
      links[i]=nullptr;
      flag=false;
    }
   }
   bool alphaExist(char alpha){
    return links[alpha-'a']!=nullptr;
   }
   void put(char alpha,node* newNode){
      links[alpha-'a']=newNode;
   }
   node* getNextChar(char alpha){
      return links[alpha-'a'];     
   }
   void setEnd(){
    flag=true;
   }
   bool isEnd(){
      return flag;
   }

};
// root initialize
class Trie{
private: node* root;

public:
    Trie(){
      root=new node();
    }
    //insert function
    void insert(string word){
      node*temp=root;
       for(int i=0;i<word.length();i++){
          if(temp->alphaExist(word[i])==false){

            temp->put(word[i],new node());
          }
         temp= temp->getNextChar(word[i]);
       }
       temp->setEnd();
    }
    //search function(is word exist)
    bool search(string word){
      node* temp=root;
      for(int i=0;i<word.length();i++){
        if(temp->alphaExist(word[i])==false){
          return false;
        }
        temp=temp->getNextChar(word[i]);
      }
      return temp->isEnd();
    }

};

int main() {

    Trie trie;

    trie.insert("apple");
    trie.insert("app");

    cout << trie.search("apple") << endl;      // 1
    cout << trie.search("app") << endl;        // 1
    cout << trie.search("appl") << endl;       // 0

   

    return 0;
}
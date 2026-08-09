#include<bits/stdc++.h>
using namespace std;
/*
insert(word)


if we want to store ...
apple
app
ape
bat
                 root
                /    \
               a      b
               |      |
               p      a
              / \      |
             p   e     t
             |
             l
             |
             e

its will be like one node have two things:
1) array size 26 for storing alphabets
2) a flag (true->word ends/ false->not a end).

*/


// node construction
class node{

public:
 // any node/root contain these two things along..
  node* links[26];
  bool flag;

  //constructor
  node(){

    for(int i=0;i<26;i++){

      links[i]=nullptr;
      flag=false;
    }
  }
   bool alphaExist(char alpha){
      int index= alpha-'a';
       if(links[index]!=nullptr) return true;
       else return false;
    }
    void put(char alpha,node* newNode){
      int index=alpha-'a';
      links[index]=newNode;
    }

    node* getNextChar(char alpha){
      return links[alpha-'a'];
    }
    void setEnd(){
      flag=true;
    }
};

/*
links[0]  → a
links[1]  → b
links[2]  → c
...
links[25] → z
so for index we will use..... int index = ch - 'a';
*/

// creating the root node and trie initially root points to nothing

class Trie{

private: node* root;

public:
    Trie(){

    root=new node();
}
   
 // insert
   void insert(string word){
      node* temp=root;
      for(int i=0;i<word.length();i++){
         
        // if alredy exit there
        if(temp->alphaExist(word[i])==false){
              temp->put(word[i], new node());
        }
        // move next to next alphabets
        temp=temp->getNextChar(word[i]);

      }
      // finally temp refering to null link and flag false ,which need to end means flag=false;
      temp->setEnd();
   }

};
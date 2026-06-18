//1) make struct ->node for tree
//2) make binary tree from array
//3) traversal -> a) recursive  (i) preorder
//                             (ii) inorder
//                            (iii) postorder
//             ->b)  iterative  (i) preorder
//                             (ii) inorder
//                            (iii) postorder
#include<bits/stdc++.h>
using namespace std;
//----------------1----------------------------------
struct node{
    int data;
     node* left;
      node* right;
       node(int val){
        data=val;
         left=nullptr;
          right=nullptr;
   }
};
//-----------------2------------------------------------
node* arraytoTree(vector<int>&nodes){
    if(nodes.size()==0 || nodes[0]==-1) return nullptr;
      node* root=new node(nodes[0]);
       queue<node*>q;
        q.push(root);
         int i=1;
          while(i<nodes.size()){
            node* curr=q.front();
             q.pop();
              if(nodes[i]!=-1){
               curr->left=new node(nodes[i]);
                q.push(curr->left);
        }
        i++;
        if(i<nodes.size() && nodes[i]!=-1){
             curr->right=new node(nodes[i]);
               q.push(curr->right);
        }
        i++;
    }
    return root;

}


//------------3ai-----------------------------------
void preorderRecursive(node* &root){
      if(root==nullptr) return;
       cout<<root->data<<" ";
        preorderRecursive(root->left);
         preorderRecursive(root->right);
}
//------------3aii-----------------------------------
void inorderRecursive(node* &root){
      if(root==nullptr) return;
       inorderRecursive(root->left);
        cout<<root->data<<" ";
         inorderRecursive(root->right);
}
//------------3aiii-----------------------------------
void postorderRecursive(node* &root){
      if(root==nullptr) return;
       postorderRecursive(root->left);
        postorderRecursive(root->right);
         cout<<root->data<<" ";
}



//------------3bi------------------------------------
vector<int> preorderIterative(node*&root){
    if(root==nullptr) return{};
     vector<int>ans;
       stack<node*>s;
        s.push(root);
         while(!s.empty()){
          node*curr=s.top();
           s.pop();
            ans.push_back(curr->data);
        if(curr->right!=nullptr) s.push(curr->right);
         if(curr->left!=nullptr) s.push(curr->left);
    } 
    return ans;   
}
//--------------3bii-------------------------------
vector<int> inorderIterative(node* &root){
     if(root==nullptr) return{};
      vector<int>ans;
       stack<node*>s;
        node*curr=root;
         while(curr!=nullptr || !s.empty()){
           while(curr!=nullptr){
            s.push(curr);
             curr=curr->left;
       }
       curr=s.top();
         s.pop();
           ans.push_back(curr->data);
            curr=curr->right;
     }
     return ans;
}
//--------------3biii-----------------------------
vector<int> postorderIterative(node*&root){
    if(root==nullptr) return{};
     vector<int>ans;
       stack<node*>s;
        s.push(root);
         while(!s.empty()){
          node*curr=s.top();
           s.pop();
            if(curr->left!=nullptr) s.push(curr->left);
             if(curr->right!=nullptr) s.push(curr->right);
              ans.push_back(curr->data);
    } 
    return ans;   
}
//--------------------------------------------------
void print(vector<int>&ans){
    for(const auto i:ans){
      cout<<i<<" ";
       }
        cout<<endl;
}
void reverseprint(vector<int>&ans){
    for(int i=ans.size()-1;i>=0;i--){
       cout<<ans[i]<<" ";
    }
         cout<<endl;
}
//---------------------------------------------------
int main(){
    vector<int>nodes={1,2,-1,4,5};
      node* root=arraytoTree(nodes);
//-------------Recursive Method-------------------------
   
     cout<<"-------Recursive Method------\n"<<"pre order : ";
       preorderRecursive(root);
        cout<<endl;
         cout<<"In order : ";
          inorderRecursive(root);
           cout<<endl;
            cout<<"Post order : ";
             postorderRecursive(root);
              cout<<endl;

//--------------Iterative Method------------------------

     cout<<"------Iterative Method-------\n"<<"pre order : ";
      vector<int> preorder=preorderIterative(root);
         print(preorder);
           cout<<"post order : ";
             vector<int> inorder=inorderIterative(root);
              print(inorder);
               cout<<"post order : ";
                 vector<int> postorder=postorderIterative(root);
                  reverseprint(postorder);

}

#include<bits/stdc++.h>
using namespace std;
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
node* arrayToTree(vector<int>&nodes){
    if(nodes.size()==0 || nodes[0]==-1) return nullptr;
    node* root = new node(nodes[0]) ;
    queue<node*>q;
    q.push(root);
    int i=1;
    while(i<nodes.size()  && !q.empty()){
        node* curr= q.front();
        q.pop();
        if(nodes[i]!=-1) {
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
//-------------level order traversal---------
vector<vector<int>> levelTra(node*root){
     vector<vector<int>>result;
     if(!root) return result;
     queue<node*>q;
     q.push(root);
    
     while(!q.empty()){
         int n=q.size();
        vector<int>row;
        while(n--){
        node* curr=q.front();
        q.pop();
        row.push_back(curr->data);
        if(curr->left!=nullptr) q.push(curr->left);
        if(curr->right!=nullptr) q.push(curr->right);
    }
     result.push_back(row);
    }
    return result;

}
//-------------------------------------------
int main(){
    vector<int>nodes={1,2,3,4,5,-1,7};
    node* root=arrayToTree(nodes);
    vector<vector<int>>result=levelTra(root);
    for(int i=0;i<result.size();i++){
        cout<<"{ ";
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";            
        }
        cout<<"} ";
    }

}
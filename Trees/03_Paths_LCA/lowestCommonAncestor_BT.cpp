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
node* Tree(vector<int>&arr){
    int n=arr.size();
    if(n==0 || arr[0]==-1) return nullptr;
    node* root=new node(arr[0]);
    queue<node*>q;
    q.push(root);
    int i=1;
    while(i<n && !q.empty()){
        node* curr= q.front();
        q.pop();
        //left
        if(arr[i]!=-1) {
            curr->left=new node(arr[i]);
            q.push(curr->left);
        }
        i++;
        //right
        if(i<n && arr[i]!=-1){
            curr->right=new node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
node* ans=nullptr;
int dfs(node* &root,node*p,node*q){
    if(root==nullptr) return 0;
    int left=dfs(root->left,p,q);
    int right=dfs(root->right,p,q);
    int self= (root==p || root==q)? 1:0;
    int total=self+right+left;
    if(total>=2 && ans==nullptr){
         ans=root;
    }
    return total;

}
node* lca(node*root,node*p,node*q){
    ans=nullptr;
    dfs(root,p,q);
    return ans;
}
node* findNode(node* root, int target) {
    if(root==nullptr) return nullptr;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        while(n--){
          node*curr=q.front();
          q.pop();
          if(curr->data==target) return curr;
          if(curr->left!=nullptr) q.push(curr->left);
          if(curr->right!=nullptr) q.push(curr->right);
        }
    }
    return nullptr;
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    node* root = Tree(arr);          // Don't forget to add return root; in Tree()!
    
    node* p = findNode(root, 4);     // ✅ Gets actual node
    node* q = findNode(root, 5);     // ✅ Gets actual node
    
    node* lcN = lca(root, p, q);
    cout << lcN->data << " ";        // Should print: 1
}
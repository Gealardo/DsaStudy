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
vector<int> inorder(node* &root){
    vector<int>Inorder;
    stack<node*>s;
    node* temp=root;
    while(temp!=nullptr || !s.empty()){
        while(temp!=nullptr){
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        Inorder.push_back(temp->data);
        temp=temp->right;
    }
    return Inorder;
}
pair<int,int> twosum(vector<int>arr,int k){
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        int s=arr[i]+arr[j];
        if(s==k){
            return {arr[i],arr[j]};
        }
        if(s<k) i++;
        else j--;
    }
    return {-1,-1};
}


int main(){
    vector<int> arr={10,7,15,6,8,11,20};
    node* root=Tree(arr);
    vector<int>aa=inorder(root);
   

    pair<int,int> x=twosum(aa,27);
    cout<<x.first<<" "<<x.second<<endl;
}
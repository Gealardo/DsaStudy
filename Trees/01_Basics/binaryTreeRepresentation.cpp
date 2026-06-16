#include<bits/stdc++.h>
using namespace std;
// CREATED DATA TYPE FOR TREE -> .ROOT .LEFT .RIGHT
struct node{
    int data;
    node*left;
    node* right;

// CONSTRUCTOR

    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
    
};
// CREATING THE TREE
node* arraytoTree(vector<int>& nodes){

    if(nodes.size() == 0 || nodes[0] == -1) return nullptr;

    node* root = new node(nodes[0]);
    queue< node* > q ;   q.push(root);

    int i=1; //pointing to the next element in the nodes;
    
    while(i < nodes.size()){
        node* parent=q.front();
        q.pop();

        // left child
        if(nodes[i]!=-1){
            parent->left = new node(nodes[i]);
            q.push(parent->left);
        }
        i++; //pointing to i+2
        //right child
        if(i<nodes.size() && nodes[i]!=-1){
            parent->right = new node(nodes[i]);
            q.push(parent->right);
        }
        i++;
     }
     return root;

}

void preorder(node* &root){
    if(root==nullptr) return;
    cout<<root->data<<"->";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* &root){
     if (!root) return;
     inorder(root->left);
    cout<<root->data<<"->";
     inorder(root->right);
}
void postorder(node* &root){
     if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"->";
}

int main(){

    vector<int>nodes={1,2,3,4};
    node* root=arraytoTree(nodes);

     // ADD THESE LINES TO PROVE IT WORKS!
    cout << "Preorder:    "; preorder(root); cout <<"null"<< "\n";
    cout << "Inorder:     "; inorder(root); cout << "null"<<"\n";
    cout << "Postorder:   "; postorder(root); cout <<"null"<<"\n";
    // cout << "Level Order: "; levelOrder(root); cout << "\n";
    
    return 0;
}
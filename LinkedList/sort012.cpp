#include<bits/stdc++.h>
using namespace std;

// new data type holds int+ptr
struct Node{
    int data;
    Node* next;

    ///constructor
    Node(int val,Node* ptr=nullptr){
        data=val;
        next=ptr;
    }
};


//traversal and display
void displayLL(Node* head){
    Node* temp=head;
    if(temp==nullptr){
        cout<<"LL id empty"<<endl;
        return;
    }
    //tevel through LL
    while(temp!=nullptr){
        cout<<temp->data;
        temp=temp->next;
        if(temp!=nullptr) cout<<"->";
    }
    cout<<endl;

}

// making sll
Node* arrayToSLL(vector<int>&arr){
    if(arr.size()==0) {
         cout<<"array has no el"<<endl;
         return nullptr;
    }
    Node* head=new Node(arr[0]);
    Node* connector=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        connector->next=temp;
        connector=temp;
    }
    return head;
}


//--------------------------brut-------------------//




Node* sort(Node* &head){
    //edge case
    if(head==nullptr || head->next==nullptr) return head;
    //counting;
    int c0=0,c1=0,c2=0;
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==0) c0++;
        else if(temp->data==1) c1++;
        else if(temp->data==2) c2++;
        temp=temp->next;
    }
    //data overwriting 
    Node* ptr=head;
    for(int i=0;i<c0;i++){
        ptr->data=0;
        ptr=ptr->next;
    }
     for(int i=c0;i<c0+c1;i++){
        ptr->data=1;
        ptr=ptr->next;
    }
     for(int i=c0+c1;i<c0+c1+c2;i++){
        ptr->data=2;
        ptr=ptr->next;
    }
    return head;

}

//----------optimal--------------------------//

Node* opsort(Node* &head){
    // Edge case
    if(head == nullptr || head->next == nullptr) return head;

    // 1. Create 3 Dummy Heads
    Node* zerohead = new Node(-1);
    Node* onehead  = new Node(-1);
    Node* twohead  = new Node(-1);

    Node* zerotail = zerohead;
    Node* onetail  = onehead;
    Node* twotail  = twohead;
    
    // 2. Traverse and Detach/Attach
    Node* temp = head;
    while(temp != nullptr){
        Node* newnode = temp->next; // Save the future
        temp->next = nullptr;       // Detach the node (Your genius move!)
        
        if(temp->data == 0){
            zerotail->next = temp;
            zerotail = temp;
        }
        else if(temp->data == 1){
            onetail->next = temp;
            onetail = temp;
        }
        else if(temp->data == 2){
            twotail->next = temp;
            twotail = temp;
        }
        temp = newnode; // Move forward
    }

    // 3. Stitching the chains (Handling missing chains)
    if(onehead->next != nullptr){
        zerotail->next = onehead->next;
        onetail->next = twohead->next;
    }
    else{
        zerotail->next = twohead->next;
    }

    // 4. Find the true new head
    Node* newHead;
    if(zerohead->next != nullptr)
        newHead = zerohead->next;
    else if(onehead->next != nullptr)
        newHead = onehead->next;
    else
        newHead = twohead->next;

    // 🌟 FIX 1: Clean up the dummy nodes to prevent memory leaks!
    delete zerohead;
    delete onehead;
    delete twohead;

    // 🌟 FIX 2: Actually return the head!
    return newHead; 
}











//-----------------------------------------

int main(){
    // 1. Setup for Brute Force
    vector<int> arr = {1, 1, 1, 0, 2, 0, 2, 0, 1, 1};
    Node* head = arrayToSLL(arr);
    
    cout << "Original LL: ";
    displayLL(head);

    cout << "\n--- Testing Brute Force ---\n";
    Node* bruteHead = sort(head); 
    cout << "Brute Sorted: ";
    displayLL(bruteHead);

    // 2. Setup for Optimal (Fresh unsorted list!)
    vector<int> arr2 = {2, 0, 1, 2, 0, 1, 2, 1, 0};
    Node* head2 = arrayToSLL(arr2);
    
    cout << "\n--- Testing Optimal ---\n";
    cout << "Unsorted LL: ";
    displayLL(head2);
    
    Node* optHead = opsort(head2);
    cout << "Optimal Sorted: ";
    displayLL(optHead);
    
    return 0;
}
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 1. THE NODE STRUCTURE (The Foundation)
struct Node {
    int data;
    Node* next;

    // Constructor for easy initialization
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// 2. UTILITY: Create a Linked List from an Array (For quick testing)
Node* createLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* mover = head;
    
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// 3. UTILITY: Print the Linked List (To verify your logic)
void printLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// 4. UTILITY: Delete the Linked List (Prevent memory leaks - Good Habit)
void deleteLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}
//-----------------------------------------------
 bool palindrom(Node* head){
     if(head==nullptr) return false;
     if(head->next==nullptr) return true;
     stack<int>st;
     Node* temp=head;
     while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
     }
     temp=head;
     while(temp!=nullptr){
        if(temp->data!=st.top()) return false;
        temp=temp->next;
        st.pop();
     }
     return true;

 }

//====================optimal (reverse 2nd half of list)==========================

bool oppalin(Node* head){
     if(head==nullptr) return false;
     if(head->next==nullptr) return true;
     Node*slow=head;
     Node* fast=head;
     while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
     }
     fast=head;
     //slow is the mid.
     Node* curr=slow->next;
     slow->next=nullptr;
     Node* prev=nullptr;
     while(curr!=nullptr){
        Node* front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }
    //slow is the head.
    Node * head2=slow;
    while(fast!=nullptr && slow!=nullptr){
        if(fast->data != slow->data) return false;
        fast=fast->next;
        slow=slow->next;
    }
    return true;
}

//-------=====================--------------------


int main() {
    // 1. Create test data
    vector<int> arr = {0,1,1,1,1,0};
    
    // 2. Build the Linked List
    Node* head = createLL(arr);
    
    cout << "Original List: ";
    printLL(head);

   //---------------------test-----
    bool oppalin=palindrom(head);
    cout<<oppalin<<endl;

   //------------------------------

    // 4. Clean up memory
    deleteLL(head);
   

    return 0;
}
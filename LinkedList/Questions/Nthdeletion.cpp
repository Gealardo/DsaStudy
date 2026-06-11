//deleting the nth node from the end of ll
#include <iostream>
#include <vector>

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

// ==================T.C. aprox O(2N)========================
    Node* delnth(Node* &head,int k){
        //edge case
        if(head==nullptr || k<1){
            return head;
        }
        //go to last node
        Node* temp=head;
        int count=0;
        while(temp!=nullptr){
            temp=temp->next;
            count++;
        }
        int x=count-k-1;
        if(x==-1){
           Node * ptr=head;
             head=head->next;
             delete ptr;
             return head;
        }
        else if(x<-1 ) return head;
        else{
        Node* ptr=head;
        while(x>0){
             x--;
             ptr=ptr->next;

        }
    
       //ptr ->next is the node need to delete.
       Node* ptr2=ptr->next;
       ptr->next=ptr2->next;
       delete ptr2;
       return head;
    }
       
    }

// =================optimal O(n)=========================
Node* opdelnth(Node* &head, int k) {
    Node* fast = head;
    Node* slow = head;

    // 1. Move fast forward by k steps to create the gap
    for(int i = 0; i < k; i++) {
        if(fast == nullptr) return head; // k > length
        fast = fast->next;
    }

    // 2. If fast is null now, we need to delete the head
    if(fast == nullptr) {
        Node* delNode = head;
        head = head->next;
        delete delNode;
        return head;
    }

    // 3. Move both until fast reaches the LAST node
    while(fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    // 4. Delete the node after slow
    Node* delNode = slow->next;
    slow->next = delNode->next;
    delete delNode;

    return head;
}




//======================================================


int main() {
    // 1. Create test data
    vector<int> arr = {1, 2, 3, 4, 5};
    
    // 2. Build the Linked List
    Node* head = createLL(arr);
    
    cout << "Original List: ";
    printLL(head);

   //---------------------test-----
    Node* x=opdelnth(head,5);
    printLL(x);

   //------------------------------

    // 4. Clean up memory
    deleteLL(head);
   

    return 0;
}
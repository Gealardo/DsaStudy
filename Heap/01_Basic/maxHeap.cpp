/*


Pattern 1 — Kth element
Kth Largest
Kth Smallest

Pattern 2 — Top K
Top K Frequent
Top K Frequent Words

Pattern 3 — K Closest
K Closest Points
K Closest Elements

Pattern 4 — Merge K
Merge K Sorted Arrays
Merge K Sorted Lists

Pattern 5 — Two Heaps
Median of Data Stream
Sliding Window Median

Pattern 6 — Heap + Greedy
Task Scheduler
Connect Ropes
IPO

*/


#include<bits/stdc++.h>
using namespace std;

class maxHeap
{
  public:
  int *arr;
  int heapSize;
  int arrSize;

  maxHeap(int n){
    arr= new int[n];// creating ans array of size n
    heapSize=0;// without inserting anything (total ele in heap)
    arrSize=n; // size of array
  }

  void insert(int val){

    if(arrSize==heapSize) {
      cout<<"Heap is overflow"<<endl;
      return;
    }

    arr[heapSize]= val;
    heapSize++;

    int index=heapSize-1;
    int parent=(index-1)/2;  

    while(arr[parent]<arr[index]) {

       swap(arr[parent],arr[index]);

       index=parent;  if(index==0) break;

       parent=(index-1)/2;

      }

      return;

    }

    void printHeap() {
          for(int i = 0; i < heapSize; i++) {
              cout << arr[i] << " ";
          }
          cout << endl;
    }
    

};



int main(){

  maxHeap h(5);

    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);

    h.printHeap();

    h.insert(60);

    h.printHeap();

    return 0;

}


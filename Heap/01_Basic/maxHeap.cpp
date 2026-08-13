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


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

   void del(){

    if(heapSize==0){
      cout<<"heap underflow"<<endl;
      return;
    }

    //pick the last ele , make it temperary root
    arr[0]=arr[heapSize-1];
    heapSize--;
    // maintain the max heap
    int idx=0;
    int left=(2*idx)+1;
    int right=(2*idx)+2;
    while(left<heapSize){
       // have only left child
        if(right>=heapSize){
           if(arr[idx]>=arr[left]) break;
           else{
            swap(arr[left],arr[idx]);
            idx=left;
           }
        }
      // have both the child
        else{

          if(arr[idx]>=arr[left] && arr[idx]>=arr[right]) break;
    
           else{

            int swapwithidx=(arr[right]>arr[left])? right:left;
            swap(arr[idx],arr[swapwithidx]);
             idx=swapwithidx;
           }
        }
          left=(2*idx)+1;
          right=(2*idx)+2;
    }

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
    h.del();
    h.printHeap();

    return 0;

}


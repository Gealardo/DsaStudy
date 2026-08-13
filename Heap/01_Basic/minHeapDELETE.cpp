#include<bits/stdc++.h>
using namespace std;

class minHeap
{
  public:
  int *arr;
  int heapSize;
  int arrSize;

  minHeap(int n){
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

    while(arr[parent]>arr[index]) {

       swap(arr[parent],arr[index]);

       index=parent;  if(index==0) break;

       parent=(index-1)/2;

      }

      return;

    }

  void del(){
    if(heapSize == 0) {
        cout << "Heap is underflow" << endl;
        return;
    }

    arr[0] = arr[heapSize - 1];
    heapSize--;

    int manageIdx = 0;
    int left = 2 * manageIdx + 1;
    int right = 2 * manageIdx + 2;

    while(left < heapSize) {

        if(right >= heapSize) {
            // only left child
            if(arr[manageIdx] <= arr[left])
                break;

            swap(arr[manageIdx], arr[left]);
            manageIdx = left;
        }
        else {
            // both children
            if(arr[manageIdx] <= arr[left] &&
               arr[manageIdx] <= arr[right])
                break;

            int swapwithIdx =
                (arr[left] < arr[right]) ? left : right;

            swap(arr[manageIdx], arr[swapwithIdx]);
            manageIdx = swapwithIdx;
        }

        left = 2 * manageIdx + 1;
        right = 2 * manageIdx + 2;
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

  minHeap h(5);

    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(90);
    h.insert(20);

    h.printHeap();

    h.insert(60);

    h.printHeap();

    h.del();
   h.printHeap();
    return 0;

}


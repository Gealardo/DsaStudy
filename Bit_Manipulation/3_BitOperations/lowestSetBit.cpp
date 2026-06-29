#include<bits/stdc++.h>
using namespace std;

/*
| Operation             | Think Like                                         | Operator    |   |
| --------------------- | -------------------------------------------------- | ----------- | - |
| **getBit**            | "Is this light ON?"                                | `&`         |   |
| **setBit**            | "Turn this light ON."                              | `           | ` |
| **clearBit**          | "Turn this light OFF."                             | `&` + `~`   |   |
| **toggleBit**         | "Press the switch."                                | `^`         |   |
| **updateBit**         | "Set to exactly what I want."                      | Clear + Set |   |
| **lowestSetBit**      | "Keep only the first glowing bulb from the right." | `n & (-n)`  |   |
| **clearLowestSetBit** | "Remove the first glowing bulb from the right."    | `n & (n-1)` |   |

*/// Kernighan's Algorithm
int count1s(int n){
  int count = 0;
  int temp = n;
  while(temp > 0) {
    temp = temp & (temp - 1); // Clear the lowest bit
    count++;                  // Count it!
 }
   return count;
}

void printbinary(int k){
   for(int i=31;i>=0;i--){
    cout<<((k>>i)&1);
   }
   cout<<endl;
}

int main(){
  int n;
  cout<<"enter a no. : ";
  cin>>n;

  printbinary(n);
  printbinary(n&(-n));
  cout<<count1s(n)<<endl;
  

}
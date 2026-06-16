#include <bits/stdc++.h>
using namespace std;

// 🛑 VERSION 1: Brute Force O(n^2) - YOU IMPLEMENT THIS!

int trapBruteForce(vector<int>& height) {
    int n=height.size();
    int water_max=0;
    for(int i=0;i<n;i++){
        int water=0;
        int leftmax=0,rightmax=0;
        for(int j=i;j>=0;j--){
          leftmax=max(leftmax,height[j]);
        }
        for(int j=i;j<n;j++){
          rightmax=max(rightmax,height[j]);
        }
        water = min(leftmax,rightmax)-height[i];
        water_max+=water;
    }
    return water_max;
}

// 🛑 VERSION 2: Prefix/Suffix Max Arrays O(n) time, O(n) space
int trapWithArrays(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    
    vector<int> left_max(n,0);
    vector<int> right_max(n,0);
    
    for(int i=1;i<n;i++){
        left_max[i]=max(left_max[i-1],height[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        right_max[i]=max(right_max[i+1],height[i+1]);
    }
    int max_water=0;
    for(int i=0;i<n;i++){
        int water=min(left_max[i],right_max[i])-height[i];
        if(water<0) water=0;
        else max_water+=water;
    }
    return max_water;
}

// 🛑 VERSION 3: Two Pointers O(n) time, O(1) space - THE OPTIMAL
int trapOptimal(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int leftmax = 0;
    int rightmax = 0;
    int total_water = 0;
    
    while(left<right){
        if(height[left]<height[right]){
               if(height[left]>leftmax) leftmax=height[left];
               //height[left]<leftmax->add water
               else{
                  total_water+=leftmax-height[left];
               }
               left++;
        }
        
        // height[left]>=height[right]
        else{
            if(height[right]>rightmax) rightmax=height[right];
            else{
                total_water+=rightmax-height[right];
            }
            right--;

        }
    }
    
    return total_water;
}

void printArray(const vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Test Case 1: Classic example
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Heights 1: "; printArray(height1);
    cout << "Brute Force: " << trapBruteForce(height1) << " (Expected: 6)\n";
    cout << "With Arrays: " << trapWithArrays(height1) << " (Expected: 6)\n";
    cout << "Optimal:     " << trapOptimal(height1) << " (Expected: 6)\n";
    cout << "-------------------\n";

    // Test Case 2: Simple valley
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << "Heights 2: "; printArray(height2);
    cout << "Brute Force: " << trapBruteForce(height2) << " (Expected: 9)\n";
    cout << "With Arrays: " << trapWithArrays(height2) << " (Expected: 9)\n";
    cout << "Optimal:     " << trapOptimal(height2) << " (Expected: 9)\n";
    cout << "-------------------\n";

    // Test Case 3: Increasing - no water
    vector<int> height3 = {1, 2, 3, 4, 5};
    cout << "Heights 3: "; printArray(height3);
    cout << "Brute Force: " << trapBruteForce(height3) << " (Expected: 0)\n";
    cout << "With Arrays: " << trapWithArrays(height3) << " (Expected: 0)\n";
    cout << "Optimal:     " << trapOptimal(height3) << " (Expected: 0)\n";
    cout << "-------------------\n";

    // Test Case 4: Single element
    vector<int> height4 = {5};
    cout << "Heights 4: "; printArray(height4);
    cout << "Brute Force: " << trapBruteForce(height4) << " (Expected: 0)\n";
    cout << "With Arrays: " << trapWithArrays(height4) << " (Expected: 0)\n";
    cout << "Optimal:     " << trapOptimal(height4) << " (Expected: 0)\n";

    return 0;
}
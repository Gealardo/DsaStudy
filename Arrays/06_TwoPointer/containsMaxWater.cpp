#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_water = 0;
    
    while(left<right){
        int w=right-left;
        int h=min(height[left],height[right]);
        int area=h*w;
        max_water=max(max_water,area);
        if(height[left]<height[right]) left++;
        else right--;
    }
    
    return max_water;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Test Case 1: Standard case
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Heights 1: ";
    for(int h : height1) cout << h << " ";
    cout << "\nMax Water: " << maxArea(height1) << " (Expected: 49)\n";
    cout << "-------------------\n";

    // Test Case 2: All same heights
    vector<int> height2 = {5, 5, 5, 5, 5};
    cout << "Heights 2: ";
    for(int h : height2) cout << h << " ";
    cout << "\nMax Water: " << maxArea(height2) << " (Expected: 20)\n";
    cout << "-------------------\n";

    // Test Case 3: Increasing heights
    vector<int> height3 = {1, 2, 3, 4, 5};
    cout << "Heights 3: ";
    for(int h : height3) cout << h << " ";
    cout << "\nMax Water: " << maxArea(height3) << " (Expected: 6)\n";
    cout << "-------------------\n";

    // Test Case 4: Two lines
    vector<int> height4 = {1, 1000};
    cout << "Heights 4: ";
    for(int h : height4) cout << h << " ";
    cout << "\nMax Water: " << maxArea(height4) << " (Expected: 1)\n";

    return 0;
}
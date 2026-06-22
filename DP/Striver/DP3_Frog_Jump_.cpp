#include<bits/stdc++.h>
using namespace std;



int frogJumpRec(int n, vector<int>& height) {
    
    if (n == 0) return 0;
    if (n == 1) return abs(height[1] - height[0]);

    
    int left1 = frogJumpRec(n - 1, height);
    int left2 = frogJumpRec(n - 2, height);

    
    int jump1 = left1 + abs(height[n] - height[n - 1]);
    int jump2 = left2 + abs(height[n] - height[n - 2]);

   
    return min(jump1, jump2);
}
int frogJumpRec2(int n,vector<int>&height,vector<int>&dp){
  
    if(n==0) return dp[n]=0;
    if(n==1) return dp[n]=abs(height[1] - height[0]);
    if(dp[n]!=-1) return dp[n];

    int left1=frogJumpRec2(n-1,height,dp);
    int left2=frogJumpRec2(n-2,height,dp);
    int jump1= left1+abs(height[n]-height[n-1]);
    int jump2= left2+abs(height[n]-height[n-2]);
    
    return dp[n]=min(jump1,jump2);
}

int frogJumpRec3(int n, vector<int>&height,vector<int>&dp2){
      dp2[0]=0;
      dp2[1]=abs(height[1]-height[0]);
      if(n<2){
        return dp2[n];
        }
      for(int i=2;i<height.size();i++){
            dp2[i]=min(dp2[i-1]+abs(height[i]-height[i-1]),dp2[i-2]+abs(height[i]-height[i-2]));
      }
      return dp2[n];
}

int frogJumpRec4(int n,vector<int>&height){
    if(n<2){
        if(n==0) return 0;
        return abs(height[1]-height[0]);
    }

    int prev2=0;
    int prev=abs(height[1]-height[0]);
    for(int i=2;i<n;i++){
          int curr=min(prev2+abs(height[i]-height[i-2]), prev+abs(height[i]-height[i-1]));
          prev2=prev;
          prev=curr;
    }
    return prev;
}

int main() {
    
    vector<int>height={10,20,30,10};
    int n=3;
    int t1=frogJumpRec(n,height);
    cout<<t1<<endl;
    vector<int>dp(n+1,-1);
    int t2=frogJumpRec2(n,height,dp);
    cout<<t2<<endl;
    vector<int>dp2(n+1,-1);
    int t3=frogJumpRec3(n,height,dp2);
    cout<<t3<<endl;

    int t4=frogJumpRec4(n,height);
    cout<<t4<<endl;
}
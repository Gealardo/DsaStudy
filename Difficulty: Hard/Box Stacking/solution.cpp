class Solution {
  public:
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
      int n=height.size();    
      vector<vector<int>>cuboid(3*n,vector<int>(3,0));
      int k=0;
      for(int i=0;i<n;i++){
          int h=height[i] ; int w=width[i] ; int l=length[i];
          cuboid[k++]={max(h,w),min(h,w),l};
          cuboid[k++]={max(w,l),min(w,l),h};
          cuboid[k++]={max(h,l),min(h,l),w};
      }
      // sort the col
      sort(cuboid.begin(),cuboid.end());
      int m=cuboid.size();
      vector<int>temp(m,0);
      int maxH=0;
      for(int i=0;i<m;i++){
          temp[i]=cuboid[i][2];
          for(int j=0;j<i;j++){
              if(cuboid[j][0]<cuboid[i][0] &&
                 cuboid[j][1]<cuboid[i][1] ){
                     
                  temp[i]=max(temp[i],temp[j]+cuboid[i][2]);
              }
          }
          maxH=max(maxH,temp[i]);
      }
      return maxH;
    }
};

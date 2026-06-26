#include<bits/stdc++.h>
using namespace std;

void reverse_row(vector<vector<int>>&m){
    for(int i=0;i<m.size();i++){
        int l=0;
        int r=m[0].size()-1;
        while(l<r){
            swap(m[i][l],m[i][r]);
            l++,r--;
        }
    }
}


void invert(vector<vector<int>>&m){
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[0].size();j++){
            m[i][j]=1-m[i][j];
        }
    }
}

void flip_invert(vector<vector<int>>&m){
    reverse_row(m);
    invert(m);
     for(int i=0;i<m.size();i++){
        for(int j=0;j<m[0].size();j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

void flip_invert2(vector<vector<int>>&m){
    for(int i=0;i<m.size();i++){
        int l=0;
        int r=m[0].size()-1;
        while(l<=r){
            if(l<r){
                m[i][l]=1-m[i][l];
                m[i][r]=1-m[i][r];
                swap(m[i][l],m[i][r]);
                l++,r--;
            }
            if(l==r){
                m[i][r]=1-m[i][r];
            }
        }
    }
     for(int i=0;i<m.size();i++){
        for(int j=0;j<m[0].size();j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>>m={
        {0,1,0,1},
        {1,1,0,0},
        {0,1,0,1},
        {1,1,1,0},
    };
    flip_invert2(m);

}
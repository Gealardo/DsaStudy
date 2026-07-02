#include<bits/stdc++.h>
using namespace std;

void make_al(int V,int E,vector<vector<int>>&al){
   for(int i=0;i<E;i++){
    int v,u;
    cin>>u>>v;
    al[u].push_back(v);
    al[v].push_back(u);
   }
   return ;
}

void printlist(int V,int E,vector<vector<int>>&al){
   
   for(int i=0;i<V;i++){
    cout<<i<<"->";
    for(int j=0;j<al[i].size();j++){
      cout<<al[i][j]<<" ";
    }
    cout<<endl;
   }
}
vector<int> dfs(int startNode, vector<vector<int>>& al, vector<int>& visited) {
    vector<int> ans;
    stack<int> st;
    st.push(startNode);
    
    
    while (!st.empty()) {
        int curr = st.top();
        st.pop(); 
        
        
        if (visited[curr] != 1) {
            visited[curr] = 1;
            ans.push_back(curr); 
            
            // Push all unvisited neighbors to the stack
            for (int neighbor : al[curr]) {
                if (visited[neighbor] != 1) {
                    st.push(neighbor);
                }
            }
        }
    }
    return ans;
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> al(V);
    make_al(V, E, al);
    printlist(V, E, al);

    vector<int> visited(V, 0);
    vector<int> finalAns; // To store the complete traversal
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
      
            vector<int> component = dfs(i, al, visited);
            for (int node : component) {
                finalAns.push_back(node);
            }
        }
    }

    // Print the  DFS traversal
    for (int node : finalAns) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
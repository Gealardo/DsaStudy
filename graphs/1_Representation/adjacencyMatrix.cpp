#include<bits/stdc++.h>
using namespace std;
// undirected graph(no-weight)
int main(){
   // taking no of vertex and edges graph contains
  int vertex,edges;
  cout<<"enter no. of vertex and edges: ";
  cin>>vertex>>edges;
   // making adjancey matrix (vertex × vertex)
  vector<vector<bool>>adj(vertex,vector<bool>(vertex,0));

  //for filling the matrix by taking edges inputs
   int u,v;
    for(int i=0;i<edges;i++){
      cin>>u>>v;
      // undirected , so from both side 
      adj[u][v]=1;
      adj[v][u]=1;// remove for directed no weight graph.

    }

   // print matrix
   cout<<endl;
   cout<<"Adjancey Matrix of Graph"<<endl;
   for(int i=0;i<vertex;i++){
    for(int j=0;j<vertex;j++){
      cout<<adj[i][j]<<" ";
    }
    cout<<endl;
   }

  }

  /*
  # Adjacency Matrix Notes (All 4 Types)

## 1) Undirected + Unweighted
- Edge `u v` means both directions.
- Update:
  - `adj[u][v] = 1`
  - `adj[v][u] = 1`


vector<vector<int>> adj(V, vector<int>(V, 0));
for (int i = 0; i < E; i++) {
    int u, v; cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
}


---

## 2) Directed + Unweighted
- Edge `u v` means `u -> v` only.
- Update:
  - `adj[u][v] = 1`

```cpp
vector<vector<int>> adj(V, vector<int>(V, 0));
for (int i = 0; i < E; i++) {
    int u, v; cin >> u >> v;
    adj[u][v] = 1;
}
```

---

## 3) Undirected + Weighted
- Edge `u v w` means both directions with same weight.
- Update:
  - `adj[u][v] = w`
  - `adj[v][u] = w`

```cpp
vector<vector<int>> adj(V, vector<int>(V, 0));
for (int i = 0; i < E; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u][v] = w;
    adj[v][u] = w;
}
```

---

## 4) Directed + Weighted
- Edge `u v w` means `u -> v` with weight `w`.
- Update:
  - `adj[u][v] = w`

```cpp
vector<vector<int>> adj(V, vector<int>(V, 0));
for (int i = 0; i < E; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u][v] = w;
}
```

---

## Complexity
- Space: `O(V^2)`
- Edge existence check: `O(1)`
- Traverse neighbors of one node: `O(V)`

## Notes
- Usually use **0-based indexing** unless problem says otherwise.
- For no edge in weighted graph:
  - either `0` (if weights positive and no 0-weight edges),
  - or `INF` for safer shortest-path style problems.
  */
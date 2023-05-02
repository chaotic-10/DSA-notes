    // O(V+E)
    // O(2N)    
    
    class Solution {

    private: 
    bool dfs (int node,vector<int> adj[] , int vis[], int pathVis[]){
        vis[node] =1;
        pathVis[node]=1;
        for(auto adjacentNode : adj[node]){
            
            if(!vis[adjacentNode]){
                // when the node is not visited 
              if(dfs(adjacentNode, adj, vis, pathVis)==true)
              return true;
            }
            // if the node has been previously visited
            // but it has to be visited on the same path 
            
            else if (pathVis[adjacentNode]){
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] ={0};
        int pathVis[V]={0};
        for( int i = 0 ; i < V ; i++)
        {
            if(!vis[i])
            {
                if  (dfs(i,adj,vis,pathVis) == true) return true;
            }
        }
        return false;
    }
};
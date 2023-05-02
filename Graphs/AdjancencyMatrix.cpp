class Solution {
  public:
  // tc : o(n)+o(2e)
  // sc : bfs + adj list + visited arr == o(3n) , n is number of nodes 
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // visited array konse node visit ho chuke uska check rakthi hai
        int vis[V] = {0}; // since zero based indexing hai islie n size
        queue<int> q;
        vis[0]=1;
        q.push(0);
        vector<int> bfs;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            // adj list-> stores neighbors of a node at every index 
            // now traverse all its neigbors
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
// tc : o(N+ 2(E)) + o(n) 
//sc : o(N)

class Solution {
    private: 
    bool detect(int src,vector<int> adj[],int vis[])
    {
        
        vis[src] =1;
        queue<pair<long,long>>q;
        q.push({src,-1});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjacentNode : adj[node])
            {
                if(!vis[adjacentNode])
                {
                    vis[adjacentNode]=1;
                    q.push({adjacentNode,node});
                }
        // if some node is visited suppose at 5, we mark 7 as visited.
        // but when we move to 6, 7 is alreaedt marked that means, 6 is not its parent, 5 was. therefore a cycle.
        // since we started a one node, and reached at a same node towards 
            
                else if (parent != adjacentNode){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        
        //V is no of nodes
        int vis[V]={0};
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if (detect(i,adj,vis)) return true;
            }
        }
        return false;
        
    }
};
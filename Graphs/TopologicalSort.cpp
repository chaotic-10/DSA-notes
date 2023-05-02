// PS : Given a Directed Acyclic Graph (DAG) 
//with V vertices and E edges, Find any Topological Sorting of that Graph.



class Solution
{
    private: 
    void dfs(int node,int vis[],vector<int> adj[], stack<int>&s)
    {
        vis[node]= 1;
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]){
                dfs(adjnode,vis,adj,s);
            }
        }
        // jaise hi ek node ke saare dfs khtm hue push that node into stack
        // stack ordering will be one of the linear ordering, it is k/a topolocial sorting
        s.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> s;
	    // code here
	    int vis [V] = {0};
	   for(int i = 0 ; i < V ; i ++){
	       if(!vis[i]){
	           dfs(i,vis,adj,s);
	       }
	   }
	   vector<int> ans;
	   
	   while(!s.empty())
	   {
	       ans.push_back(s.top());
	       s.pop();
	   }
	    return ans;
	}
};
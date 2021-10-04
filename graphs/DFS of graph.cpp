/* DFS of Graph 

Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right 
according to the graph..

*/

class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	void dfs(int v, vector<int> adj[], vector<int>&res, bool visited[])
	{
	    visited[v] = true;
	    res.push_back(v);
	    
	    for(int i: adj[v])
	    {
	        if(visited[i]==false)
	            dfs(i,adj,res,visited);
	    }
	}
	vector<int>dfsOfGraph(int v, vector<int> adj[])
	{
	    vector<int>res;
	    bool visited[v];
	    for(int i=0; i<v; i++)
	        visited[i] = false;
	   dfs(0,adj,res,visited);
        return res;
	}
};

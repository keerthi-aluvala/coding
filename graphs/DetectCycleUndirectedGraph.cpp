/* Detect cycle in an undirected graph 

Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

*/

class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool isCycleUtil(vector<int>adj[],vector<int>visited,int curr)
    {
        if(visited[curr]==2) return true;
        visited[curr] = 1;
        bool flag = false;
        for(int i=0; i<adj[curr].size(); i++)
        {
            if(visited[adj[curr][i]]==1)
                visited[adj[curr][i]]=2;
            else
            {
                flag = isCycleUtil(adj,visited,adj[curr][i]);
                if(flag==true)
                    return true;
            }
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int>visited(V,0);
	   bool flag = false;
	   for(int i=0; i<V; i++)
	   {
	       visited[i] = 1;
	       for(int j=0; j<adj[i].size(); j++)
	       {
	           flag = isCycleUtil(adj,visited,adj[i][j]);
	           if(flag==true) return true;
	       }
	       visited[i] = 0;
	   }
	   return false;
	}
};

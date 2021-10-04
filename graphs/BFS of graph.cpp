/* BFS of graph 

Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting 
from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly 
connected from Node 0 in consideration.

*/

class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int>res;
	    bool visited[V+1];
	    for(int i=0; i<V; i++)
	        visited[i] = false;
	    queue<int>Q;
	    Q.push(0);
	    visited[0] = true;
	    while(!Q.empty())
	    {
	        int node = Q.front();
	        Q.pop();
	        res.push_back(node);
	        for(auto i: adj[node])
	        {
	            if(!visited[i])
	            {
	                visited[i] = true;
	                Q.push(i);
	            }
	        }
	    }
	    return res;
	}
};

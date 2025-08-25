/*
A topological ordering is an ordering of the nodes in a directed graph where for each directed edge from node A 
to node B, node A appears before node B in the ordering. A topological ordering is possible if and only if the graph 
has no directed cycles, i.e., if it is a directed acyclic graph (DAG). 
Topological sorting is often used in scenarios such as task scheduling, where certain tasks must be completed 
before others can begin.

Note: Topological ordering is not unique; there can be multiple valid topological orderings for a given DAG.

Directed cyclic graph cannot be topologically sorted.
Only Directed Acyclic Graphs (DAGs) can be topologically sorted.


Indegree of a node: The number of incoming edges to a node.



Algorithm:

while(All the nodes are not processed) {
    1. Pick a node with indegree 0 (no incoming edges)
    2. Add it to the topological order
    3. Remove it from the graph (decrease the indegree of its neighbors by 1)
}
*/



#include <iostream>
#include<vector>
#include<queue> 
using namespace std;

int main()
{
    int n, m;
    cout<<"Enter number of nodes and edges: "<<endl;
    cin >> n >> m; // n = number of nodes, m = number of edges  
    vector<int> adj[n]; // adjacency list
    vector<int> indegree(n, 0); // indegree of each node
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout<<"Enter directed edge (u v): "<<endl;
        cin >> u >> v; // directed edge from u to v
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    // push all nodes with indegree 0 to the queue
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            // node with indegree 0
            q.push(i);
        }
    }
    vector<int> output; // to store the topological order
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        //cout << node << " "; // print the topological order
        output.push_back(node);
        // decrease the indegree of its neighbors by 1
        for(auto neighbor : adj[node]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    cout<<"OUTPUT SIZE: "<<output.size()<<endl;
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    cout<<endl; 



    return 0;
}

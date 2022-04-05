#include "graph.h"



void Graph::addEdge(int v, int w){

    adj[v].push_back(w);
    ++this->v_count;

}


// perform DFS on the graph from a given edge 
void Graph::DFS(int v){

    visited[v] = true;
    cout << v << " ";

    vector<int>::iterator it;

    for (it = adj[v].begin () ; it != adj[v].end() ; ++it )
        if (!visited[*it])
            DFS(*it);

    
}

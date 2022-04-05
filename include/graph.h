#ifndef GRAPH_H
#define GRAPH_H


#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Graph{
  private:

    int v_count; // n of vertices
    map <int, vector<int>> adj;
    map <int, bool> visited;

  public:
    Graph():v_count(0){}
    void addEdge(int v, int w);
    void DFS(int v );

};

#endif

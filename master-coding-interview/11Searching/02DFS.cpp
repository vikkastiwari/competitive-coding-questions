/*
Depth first search(BFS)

Graph
0->[1,3]
1->[0,2]
2->[1,3]
3->[0,2,4]
4->[3,5]
5->[4]
*/

#include <bits/stdc++.h>
using namespace std;

// to work with graph of int as well as strings
template <typename T>
class Graph
{
    map<T, list<T>> l;
    // eg. 2->[1,3,4] - 2 is connected with 1, 3, and 4

public:
    // unweighted graph so we only need to store source and destination
    void addEdge(int x, int y)
    {
        // assuming the edges are bidirectional
        l[x].push_back(y);
        l[y].push_back(x);
    }

    // Recursive function that will traverse the graph
    void dfs_helper(T src, map<T, bool> &visited)
    {
        cout << src << " ";
        // mark node as visited
        visited[src] = true;

        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited);
            }
        }
    }

    void dfs(T source)
    {
        // visited will keep track if the node is visited once or not
        map<T, bool> visited;

        // mark all node as unvisited in the start
        for (auto val : l)
        {
            T node = val.first;
            visited[node] = false;
        }

        // calling dfs_helper function
        dfs_helper(source, visited);
    }
};

int main()
{
    Graph<int> g;
    // edges are bidirectional
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    // 0 is source
    g.dfs(0);

    return 0;
}
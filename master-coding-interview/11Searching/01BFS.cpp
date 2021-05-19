/*
Breadth first search(BFS) - cyclic, unweighted, bidirectional

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

    void bfs(T source)
    {
        // mark visited node as true
        // it will restrict the value to again enter a queue
        map<T, int> visited;

        // required to do the level order traversal
        queue<T> q;

        // we will push our source into queue and mark it as visited
        q.push(source);
        visited[source] = true;

        // until we traverse all the nodes the loop will go on
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";

            for (int nbr : l[node])
            {
                if (!visited[nbr])
                {
                    // when neighbour of the node is not visited
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
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
    g.bfs(0);

    return 0;
}

#include <iostream>
#include <vector>
#include "../headers/array1D.h"
#include <climits>
using namespace std;

int getMinDistantUnvisitedNode(vector<int> dist, vector<bool> flag)
{
    int min = -1;
    for (int i = 0; i < dist.size(); i++)
    {
        if (flag[i] == false && dist[i] < dist[min])
        {
            min = i;
        }
    }
    return min;
}

void SSSP(vector<vector<int>> adj, int source, vector<int> &dist, vector<string> &path)
{
    int n = adj.size(); // number of vertices
    vector<bool> flag(n, false);
    // initial distances of all vertices from source
    for (int i = 0; i < n; i++)
    {
        dist[i] = adj[source][i];
        path[i] = to_string(source) + "->" + to_string(i);
    }

    flag[source] = true;

    printArray(dist);
    printArray(flag);

    for (int i = 1; i < n; i++)
    {
        int minVertex = getMinDistantUnvisitedNode(dist, flag);
        cout << "min vertex: " << minVertex << endl;
        if (minVertex == -1)
        {
            break;
        }
        flag[minVertex] = true;
        for (int j = 0; j < n; j++)
        {
            if (!flag[j] && adj[minVertex][j] != INT_MAX && dist[j] > dist[minVertex] + adj[minVertex][j])
            {
                dist[j] = dist[minVertex] + adj[minVertex][j];
                path[j] = path[minVertex] + "->" + to_string(j);
            }
        }
    }
}
int main()
{
    // vertices-> 0, 1, 2, 3
    vector<vector<int>> adj = {
        {0, 5, 1, INT_MAX},
        {INT_MAX, 0, 7, 4},
        {INT_MAX, INT_MAX, 0, 6},
        {3, INT_MAX, INT_MAX, 0},
    };
    int source = 2, n = adj.size();
    vector<int> dist(n);
    vector<string> path(n);
    SSSP(adj, source, dist, path);
    printArray(dist);
    printArray(path);
    return 0;
}
#include <iostream>
#include <vector>
#include <climits>
#include "../../headers/array1D.h"
#include "../../headers/array2D.h"
#include "./15findStages.cpp"
using namespace std;

// Time complexity: n^2
void MGP(vector<vector<int>> &cost, int k, int n)
{
    vector<int> fdist(n, 0);
    vector<int> d(n, 0);
    vector<int> path(k, 0);
    fdist[n - 1] = 0;
    path[0] = 0;
    path[k - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        int min = INT_MAX;
        for (int j = i + 1; j < n; j++)
        {
            if (cost[i][j] != INT_MAX && cost[i][j] != 0)
            {
                if (cost[i][j] + fdist[j] < min)
                {
                    min = cost[i][j] + fdist[j];
                    fdist[i] = cost[i][j] + fdist[j];
                    d[i] = j;
                }
            }
        }
    }
    for (int i = 1; i < k - 1; i++)
    {
        path[i] = d[path[i - 1]];
    }
    cout << "fdist Array:" << endl;
    printArray(fdist);
    cout << "Path:" << endl;
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i != path.size() - 1) cout << " -> ";
    }
}
int main()
{
    vector<vector<int>> adj = {
        // {0, 4, 1, INT_MAX},
        // {INT_MAX, 0, INT_MAX, 6},
        // {INT_MAX, INT_MAX, 0, 8},
        // {INT_MAX, INT_MAX, INT_MAX, 0},
        {0, 2, 5, 10, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 0, INT_MAX, INT_MAX, 7, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, INT_MAX, 1, 9, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 0, 6, 3, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 6},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 4},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0},
    };
    int stages = countStages(adj);
    MGP(adj, stages, adj.size());

    return 0;
}       
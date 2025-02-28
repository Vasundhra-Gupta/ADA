#include <iostream>
#include <vector>
#include <climits>
#include "../headers/array1D.h"
#include "../headers/array2D.h"
using namespace std;

void MST(vector<vector<int>> adj, vector<vector<int>> &result,int &minWeight)
{
    int n = adj.size(), k = 0, l = 0;
    adj[k][l] = INT_MAX;
    vector<int> near(adj.size());
   
    //find minimum edge O(n^2)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] != 0 && adj[i][j] <= adj[k][l])
            {
                k = i;
                l = j;
            }
        }
    }
    result.push_back({k, l});
    near[k] = -1;
    near[l] = -1;
    minWeight += adj[k][l];

    //assign nearest vertex from processes vertex to unprocessed ones
    for (int i = 0; i < n; i++)
    {
        if (near[i] != -1)//unprocessed
        {
            if (adj[i][k] > adj[i][l])
            {
                near[i] = l;
            }
            else
            {
                near[i] = k;
            }
        }
    }

    for (int j = 0; j < n - 2; j++)
    {
        // find min near
        int minNear = j;
        int minNearVal = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (near[i] != -1 && adj[i][near[i]] < minNearVal)
            {
                minNearVal = adj[i][near[i]];
                minNear = i;
            }
        }
        // push that min near to vistited and
        result.push_back({minNear, near[minNear]});
        minWeight += adj[minNear][near[minNear]];
        near[minNear] = -1;
        // again update near vertex and minWeight acc. to minVertex(additional competitor now),
        for (int i = 0; i < n; i++)
        {
            if (near[i] != -1 && adj[i][near[i]] > adj[i][minNear])
            {
                near[i] = minNear;
            }
        }
    }
}

int main()
{
    // vertices (0, 1, 2, 3, 4)
    vector<vector<int>> adj = {
        {0, 4, 1, INT_MAX, INT_MAX},
        {4, 0, 2, 5, INT_MAX},
        {1, 2, 0, 8, 10},
        {INT_MAX, 5, 8, 0, 3},
        {INT_MAX, INT_MAX, 10, 3, 0}
    },
    result;
    int minWeight =0;

    MST(adj, result, minWeight);

    cout<<"Minimum Weight of MST: "<<minWeight<<endl;
    cout << "result: "<<endl;
    printArray(result);
    return 0;
}
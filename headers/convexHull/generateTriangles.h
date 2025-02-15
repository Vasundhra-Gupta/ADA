#define ARRAY_H
#ifdef ARRAY_H

#include <iostream>
#include <vector>
using namespace std;

//n(n-1)(n-3), O(n^3)
vector<vector<vector<int>>> allTriangles(vector<vector<int>> arr, int n)
{
    vector<vector<vector<int>>> triangles; // stores array inside 2D array.
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                triangles.push_back({arr[i], arr[j], arr[k]});
            }
        }
    }
    return triangles;
}

#endif

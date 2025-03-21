#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int countStages(vector<vector<int>> &cost)
{
    int n = cost.size();
    int stageCount = 1;
    // vector<vector<int>> stages;
    int i = 0;
    while (i < n - 1)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (cost[i][j] != INT_MAX)
            {
                // stages.push_back({i, j});
                i = j;
                stageCount++;
            }
        }
    }
    return stageCount;
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
    cout << "The number of stages are: " << stages;
    return 0;
}
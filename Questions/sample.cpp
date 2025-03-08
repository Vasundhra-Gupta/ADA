// generate minimum weighted spanning tree T = (V, E') of given graph G = (V,E) where |E'| = |V|-1
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printArray(auto arr)
{
    for (auto val : arr)
    {
        cout << val << "\t";
    }
    cout << endl;
}


void print(const vector<vector<int>> &arr)
{
    for (const vector<int> &row : arr)
    {
        cout << row[0] << " - " << row[1] << endl;
    }
}

// O(n)
int minWeightedNear(const vector<vector<int>> &cost, const vector<int> &near)
{
    int minCost = INT_MAX, u = -1;
    for (int j = 0; j < cost.size(); j++)
    {
        if (near[j] != -1 && cost[j][near[j]] < minCost)
        {
            minCost = cost[j][near[j]];
            u = j;
        }
    }
    return u;
}

// O(n^2)
void prims(const vector<vector<int>> &cost, const int &n, vector<vector<int>> &tree, int &weight)
{
    vector<int> near(n, 0);

    // find the minimum weighted (costed) edge
    int minCost = INT_MAX, k = -1, l = -1;
    for (int i = 0; i < n; i++) // O(n)
    {
        for (int j = 0; j < n; j++) // O(n)
        {
            if (i != j && cost[i][j] < minCost)
            {
                minCost = cost[i][j];
                k = i, l = j;
            }
        }
    }

    // if (k == -1 || l == -1)
    // {
    //     cout << "Graph is disconnected. No MST possible.1" << endl;
    //     return;
    // }

    // now push this min edge into the tree and mark these vertices as visited (near = 0)
    tree[0][0] = k, tree[0][1] = l;
    near[k] = -1, near[l] = -1;
    weight = cost[k][l];


    // initialize rest of the near array with respect to k & l
    for (int i = 0; i < n; i++) // O(n)
    {
        if (near[i] != -1)
        {
            near[i] = cost[i][k] <= cost[i][l] ? k : l;
        }
    }

    //fill the remaining tree that is indexed from 1 -> n-2 (size = n-1)
    for (int i = 1; i < n - 1; i++) // O(n)
    {
        // since near has been completely initialized, so now find the minimum cost edge in near, add it to the tree, mark it as visited (near = 0)
        int u = minWeightedNear(cost, near); // O(n)
        cout<<"u"<<u<<endl;
        if (u == -1)
        {
            cout << "Graph is disconnected. No MST possible.2" << endl;
            return;
        }

        tree[i][0] = u, tree[i][1] = near[u];
        weight += cost[u][near[u]];
        near[u] = -1; // update after weight increment
        printArray(near);
        cout<<"minWeight: "<<weight<<endl;

        // now repeat but before that update the near array (changes will be in the neighbour vertices of the newly visited vertex 'u')
        for (int j = 0; j < n; j++) // O(n)
        {
            if (near[j] != -1 && cost[u][j] != INT_MAX) // condn for checking the neighbour of 'u'
            {
                if (cost[j][u] < cost[j][near[j]])
                {
                    near[j] = u;
                }
            }
        }
    }

}

int main()
{
    // un-directed & weighted graph's adjacency matrix (cost)
    //   A B C ...
    // A * * * ...
    // B * * * ...
    // C * * * ...
    vector<vector<int>> cost = {
        {0, 28, INT_MAX, INT_MAX, INT_MAX, 10, INT_MAX},
        {28, 0, 16, INT_MAX, INT_MAX, INT_MAX, 14},
        {INT_MAX, 16, 0, 12, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 12, 0, 22, INT_MAX, 18},
        {INT_MAX, INT_MAX, INT_MAX, 22, 0, 25, 24},
        {10, INT_MAX, INT_MAX, INT_MAX, 25, 0, INT_MAX},
        {INT_MAX, 14, INT_MAX, 18, 24, INT_MAX, 0},
    };

    int n = cost.size(), weight = 0;
    vector<vector<int>> tree(n - 1, vector<int>(2));

    prims(cost, n, tree, weight);

    cout << "Edges in Minimum Spanning Tree:" << endl;
    print(tree);
    cout << "Total Weight of MST: " << weight << endl;

    return 0;
}

// {0, 10, 2, INT_MAX, INT_MAX, 2},
// {10, 0, INT_MAX, INT_MAX, 9, 8},
// {2, INT_MAX, 0, 5, INT_MAX, 1},
// {INT_MAX, INT_MAX, 5, 0, 7, 6},
// {INT_MAX, 9, INT_MAX, 7, 0, INT_MAX},
// {2, 8, 1, 6, INT_MAX, 0},
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> x)
{
    for (int val : x)
    {
        cout << val << " ";
    }
    cout << endl;
}

bool Color(int k, int i, vector<int> x, vector<vector<int>> rooms)
{
    for (int j = 0; j < k; j++)
    {
        if (x[j] == i && rooms[k][j])
            return false;
    }
    return true;
}

void FC(int k, vector<vector<int>> rooms, int m, vector<int> &x)
{
    int n = rooms.size();
    if (k == n)
    {
        return;
    }
    for (int i = 0; i < m; i++)
    {
        cout << "k: " << k << endl;
        if (Color(k, i, x, rooms))
        {
            x[k] = i;
            cout << "i: " << i << endl;
            if (k == n - 1)
            {
                print(x);
            }
            FC(k + 1, rooms, m, x);
        }
    }
    cout << "B" << endl;
}

int main()
{
    int m;
    cout << "Enter number of colors" << endl;
    cin >> m;
    vector<vector<int>> rooms = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0},
    };
    vector<int> x(rooms.size());
    FC(0, rooms, m, x);
}
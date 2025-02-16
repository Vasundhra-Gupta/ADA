#include <vector>
#include <iostream>
#include <ctime>
using namespace std;
void generateRandomPoints(vector<vector<int>> &arr, int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 10 + 1;
        int y = rand() % 10 + 1;
        arr.push_back({x, y});
    }
}

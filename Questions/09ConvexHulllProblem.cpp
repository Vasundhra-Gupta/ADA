#include <iostream>
#include <vector>
#include <ctime>
#include "../headers/array2D.h"
#include "../headers/convexHull/generateTriangles.h"
#include "../headers/convexHull/isInsideTriangle.h"
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

//O(n^4) complexity.
void ConvexHull(vector<vector<int>> arr)
{
    vector<vector<vector<int>>> triangles = allTriangles(arr, arr.size());//O(n^3)
    cout << triangles.size() << " triangles" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        bool isInternal;
        for (int j = 0; j < triangles.size(); j++)
        {
            isInternal = isPointInternalToTriangle(triangles[j], arr[i][0], arr[i][1]);
            if (isInternal)
                break;
        }
        if (!isInternal)
            cout << "(" << arr[i][0] << "," << arr[i][1] << ")" << endl;
    }
}

int main()
{
    cout << "Enter the value of n" << endl;
    int n;
    cin >> n;
    vector<vector<int>> arr;
    generateRandomPoints(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << "(" << arr[i][0] << "," << arr[i][1] << ")" << endl;
    }
    cout << "____________" << endl;

    ConvexHull(arr);

    return 0;
}
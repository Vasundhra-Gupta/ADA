#define ARRAY_H
#ifdef ARRAY_H
#include <iostream>
using namespace std;

void inputSquaredArray(int **arr, int n)
{
    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void inputSquaredArray(vector<vector<int>> &arr)
{
    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            cin >> arr[i][j];
        }
    }
}

void input2DArray(vector<vector<int>> &arr, int row, int col){
    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void printArray(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void printArray(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

#endif
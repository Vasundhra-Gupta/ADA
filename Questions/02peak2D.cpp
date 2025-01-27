#include <iostream>
#include <vector>
#include "../headers/array2D.h"
using namespace std;
//Time Complexity: O(nlogn)
//Space Complexity: O(logn) due to recursive call stack.

vector<int> peakGrid(int**arr,int low, int high, int row)
{
    vector<int> result(2);
    int mid = (low+high) / 2;
    int max = 0;
    for (int i = 0; i < row; i++)
    {
        if (arr[i][mid] > arr[max][mid])
        {
            max = i;
        }
    }
    if (mid > 0 && arr[max][mid] < arr[max][mid - 1])
    {
        return peakGrid(arr, low, mid - 1, row);
    }
    else if (mid < high && arr[max][mid] < arr[max][mid + 1])
    {
        return peakGrid(arr, mid + 1, high, row);
    }
    else
    {
        result[0] = max;
        result[1] = mid;
        return result;
    }
}

int main()
{
    cout<<"Enter the size of square matrix: "<<endl;
    int n;
    cin>>n;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    inputArray(arr, n);
    printArray(arr, n);
    vector<int> result = peakGrid(arr, 0, n-1, n);
    int i= result[0];
    int j = result[1];
    cout<<"The Peak element is at index ["<<i<<","<<j<<"]"<<endl;
    return 0;
}
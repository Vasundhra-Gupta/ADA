#include <iostream>
#include "../headers/array1D.h"
using namespace std;

void maxMin(int *arr, int low, int high, int &max, int &min)
{
    if (low == high)
    {
        max = min = arr[low];
    }
    else
    {
        int mid = (low + high) / 2;
        maxMin(arr, low, mid, max, min);
        int min1 = min;
        int max1 = max;
        maxMin(arr, mid + 1, high, max, min);
        if (max1 > max)
        {
            max = max1;
        }
        if (min1 < min)
        {
            min = min1;
        }
    }
}

int main()
{
    cout << "Enter size of array\n";
    int n;
    cin >> n;
    int *arr = new int[n];
    generateArray(arr, n);
    printArray(arr, n);
    int max = 0, min = 0;
    maxMin(arr, 0, n - 1, max, min);

    cout << "maximum value: " << max << endl
         << "minimum value: " << min << endl;
    return 0;
}
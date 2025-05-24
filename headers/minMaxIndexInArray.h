#include <iostream>
#include "../headers/array1D.h"
using namespace std;

void maxMin(vector<int> arr, int low, int high, int &max, int &min)
{
    if (low == high)
    {
        max = min = low;
    } 
    else
    {
        int mid = (low + high) / 2;
        maxMin(arr, low, mid, max, min);
        int min1 = min;
        int max1 = max;
        maxMin(arr, mid + 1, high, max, min);
        if (arr[max1] > arr[max])
        {
            max = max1;
        }
        if (arr[min1] < arr[min])
        {
            min = min1;
        }
    }
}

// int main()
// {
//     cout << "Enter size of array\n";
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     generateArray(arr, n);
//     printArray(arr, n);
//     int max = 0, min = 0;
//     maxMin(arr, 0, n - 1, max, min);

//     cout << "maximum value: " << arr[max] << endl
//          << "minimum value: " << arr[min] << endl;
//     return 0;
// }
#include <iostream>
#include "../headers/array1D.h"
using namespace std;
// Time Complexity: O(logn)
// Space Complexity: O(1), or O(logn) due to call Stack for recusrsion

int peak(int *nums, int low, int high)
{
    int mid = (low + high) / 2;
    if (mid > 0 && nums[mid] < nums[mid - 1])
    {
        return peak(nums, low, mid);
    }
    else if (mid < high && nums[mid] < nums[mid + 1])
    {
        return peak(nums, mid + 1, high);
    }else{
        return mid;
    }
}

int main()
{
    int n;
    cout << "Enter n for array: " << endl;
    cin >> n;
    int arr[n];
    inputArray(arr, n);
    printArray(arr, n);
    cout << "The Peak Element is at index " << peak(arr, 0, n - 1);
    return 0;
}
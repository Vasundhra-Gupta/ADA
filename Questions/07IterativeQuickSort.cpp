#include <iostream>
#include <stack>
#include "../headers/array1D.h"
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (arr[i] <= pivot && i <= high)
        {
            i++;
        };
        while (arr[j] > pivot && j > low)
        {
            j--;
        };
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    };
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    stack<int> st;
    while (true)
    {
        while (low < high)
        {
            int j = partition(arr, low, high);
            if (j - low <= high - j)
            {
                low = j + 1;
                st.push(low);
                st.push(high);
            }
            else
            {
                high = j - 1;
                st.push(low);
                st.push(high);
            }
        }
        if (st.empty())
        {
            return;
        }
        else
        {
            high = st.top();
            st.pop();
            low = st.top();
            st.pop();
        }
    }
}

int main()
{
    cout << "Enter size of an array" << endl;
    int n;
    cin >> n;
    int *arr = new int[n];
    generateArray(arr, n);
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
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

// void quickSort(int arr[], int low, int high)
// {
//     stack<int> st;
//     while (true)
//     {
//         while (low < high)
//         {
//             int j = partition(arr, low, high);
//             if (j - low <= high - j)
//             {
//                 low = j + 1;
//                 st.push(low);
//                 st.push(high);
//             }
//             else
//             {
//                 high = j - 1;
//                 st.push(low);
//                 st.push(high);
//             }
//         }
//         if (st.empty())
//         {
//             return;
//         }
//         else
//         {
//             high = st.top();
//             st.pop();
//             cout<<"high"<<high<<endl;
//             low = st.top();
//             st.pop();
//             cout<<"low"<<low<<endl;
//         }
//         // cout<<st.size()<<endl;
//     }
// }

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
                st.push(j+1);
                st.push(high);
                high = j-1;
            }
            else
            {
                st.push(low);
                st.push(j-1);
                low = j + 1;
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
        // cout<<st.size()<<endl;
    }
}

int main()
{
    // cout << "Enter size of an array" << endl;
    // int n;
    // cin >> n;
    // int *arr = new int[n];
    // generateArray(arr, n);
    int arr [] = {5, 3, 1, 0 , 7, 0};
    printArray(arr, 6);
    quickSort(arr, 0,6-1);
    printArray(arr, 6);
    return 0;
}
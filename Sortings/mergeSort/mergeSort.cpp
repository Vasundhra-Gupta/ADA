#include <iostream>
using namespace std;
#include "../../headers/array1D.h"
#include <chrono>

void merge(int *arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int* b = new int[high-low+1];
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            b[k++] = arr[i++];
        }
        else
        {
            b[k++] = arr[j++];
        }
    }

    while(i<=mid){
        b[k++] = arr[i++];
    }
    while(j<=high){
        b[k++] = arr[j++];
    }

    for(int i = low; i<=high; i++){
        arr[i] = b[i-low];
    }
      delete[] b;
}

void mergeSort(int *arr, int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    cout << "Enter size of array: " << endl;
    int n;
    cin >> n;
    int arr[n];
    int totalDuration = 0;

    for (int i = 0; i < 10; i++)
    {
        generateArray(arr, n);
        // printArray(arr, n);

        auto start = chrono::high_resolution_clock::now();
        mergeSort(arr, 0, n - 1);
        auto end = chrono::high_resolution_clock::now();
        // printArray(arr, n);
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        totalDuration+= duration.count();
        cout << "The duration is " << duration.count() << " milliseconds" << endl;
    }
    cout << "THE AVERAGE TIME TAKEN FOR THE PROGRAM FOR INPUT SIZE " << n << " IS " << totalDuration / 10 << " MILISECONDS" << endl;

    return 0;
}
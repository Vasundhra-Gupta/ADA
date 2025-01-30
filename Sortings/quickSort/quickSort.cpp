#include <iostream>
#include "../../headers/array1D.h"
#include <chrono>
using namespace std;
using namespace chrono;


int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low+1;      
    int j = high;
    
    while (i <= j){
        
        while (arr[i] <= pivot && i < high ){
            i++;
        } ;
        
        while (arr[j] > pivot && j > low){
            j--;
        } ;
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    } ;
    swap(arr[low], arr[j]);
    return j;
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    cout << "Enter size of the array: " << endl;
    int n;
    cin >> n;
    int totalDuration = 0;
    for (int i = 0; i < 10; i++)
    {
        int arr[n];
        generateArray(arr, n);
        // printArray(arr,n);
        auto start = high_resolution_clock::now();
        quickSort(arr, 0, n - 1);
        auto end = high_resolution_clock::now();
        // printArray(arr, n);

        auto duration = duration_cast<milliseconds>(end - start);
        totalDuration += duration.count();
        cout << "The duration is " << duration.count() << " milliseconds" << endl;
    }
    cout << "THE AVERAGE TIME TAKEN FOR THE PROGRAM FOR INPUT SIZE " << n <<" IS " << totalDuration / 10 << " MILISECONDS" << endl;

    return 0;
}

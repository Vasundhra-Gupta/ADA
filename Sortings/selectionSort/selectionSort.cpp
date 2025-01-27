#include <iostream>
#include "../headers/array1D.h"
#include <chrono>
using namespace std;
using namespace chrono;
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
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
        auto start = high_resolution_clock::now();
        selectionSort(arr, n);
        auto end = high_resolution_clock::now();
        // printArray(arr, n);

        auto duration = duration_cast<milliseconds>(end - start);
        totalDuration += duration.count();
        cout << "The duration is " << duration.count() << " milliseconds" << endl;
    }
    cout << "THE AVERAGE TIME TAKEN FOR THE PROGRAM FOR INPUT SIZE " << n << " IS " << totalDuration / 10<<" MILISECONDS"<<endl;

    return 0;
}
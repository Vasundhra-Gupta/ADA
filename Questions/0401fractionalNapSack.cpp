#include <iostream>
#include <time.h>
#include "../headers/array2D.h"
#include <vector>
#include <chrono>
using namespace chrono;
using namespace std;
//arr[i][0] = weight, arr[i][1] = profit
void generateArray(int**arr, int n , int m){
    srand(time(0));
    for(int i=0; i<n; i++){
        int wt = rand() %200 + 5;
        int profit = rand()%1000 + 100;
        arr[i][0] = wt;
        arr[i][1] = profit;
    }
}

int partition(int** arr, int low, int high)
{
    int pivot = arr[low][1];
    int i = low+1;      
    int j = high;
    while (i <= j){
        while (i <= high && arr[i][1] <= pivot ){
            i++;
        } ;
        while (j > low && arr[j][1] > pivot){
            j--;
        } ;
        if (i < j)
        {
            swap(arr[i][0], arr[j][0]);
            swap(arr[i][1], arr[j][1]);
        }
    } ;
    swap(arr[low][1], arr[j][1]);
    swap(arr[low][0], arr[j][0]);
    // printArray(arr, high+1, 2);

    return j;
}
void quickSort(int** arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

vector<double> fractionalNapSack(int** arr, int n, int m){
    int capacity = 500;
    int wt = 0; 
    int profit = 0;
    vector<double> finalList(n, 0);
    for(int i=0; i<n; i++){
        if(wt<=capacity){
            wt = wt + arr[i][0];
            profit = profit + arr[i][1];
            finalList[i] = 1;
        }else{
            int remainWt = wt - capacity;
            wt = wt+remainWt;
            double fraction = (double)remainWt/arr[i][0];
            profit = profit + fraction*arr[i][1];
            finalList[i] = fraction;
            break;
        }
    }
    cout<<"Total capicity"<<capacity<<endl;
    cout<<"Wait till recent item:"<<wt<<endl;

    if(capacity - wt > 0){
        cout<<"More stock can be bought\n";
    }
    return finalList;
}

int main(){
    int n, m;
    cout<<"Enter row and columns for matrix:\n";
    cin>>n>> m;
    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
    }
    generateArray(arr, n, m);
    quickSort(arr, 0, n-1);
    printArray(arr, n, m);
    auto start = high_resolution_clock::now();
    vector<double> list = fractionalNapSack(arr, n, m);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "The duration is " << duration.count() << " milliseconds" << endl;
    for(int i=0; i<list.size(); i++){
        cout<<"item no. "<<i+1<<"'s selling status is "<<list[i]<<endl;
    }
    return 0;
}
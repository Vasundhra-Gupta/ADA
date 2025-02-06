#include <iostream>
#include <time.h>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;
// arr[i][0] = weight, arr[i][1] = profit, arr[i][3]= profit per weight
void generateArray(double **arr, int n, int m)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int wt = rand() % 200 + 20;
        int profit = rand() % 1000 + 100;
        arr[i][0] = wt;
        arr[i][1] = profit;
        arr[i][2] = (double)arr[i][1]/arr[i][0];
    }
}

int partition(double **arr, int low, int high, int k, int m)
{
    double pivot = arr[low][k];
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (i <= high && arr[i][k] <= pivot)
        {
            i++;
        };
        while (j > low && arr[j][k] > pivot)
        {
            j--;
        };
        if (i < j)
        {
            for (int p = 0; p < m; p++)
            {
                swap(arr[i][p], arr[j][p]);
            }
        }
    };
    for (int p = 0; p < m; p++)
    {
        swap(arr[low][p], arr[j][p]);
    }
    // printArray(arr, high+1, 2);

    return j;
}
void quickSort(double **arr, int low, int high, int k, int m)
{
    if (low < high)
    {
        int p = partition(arr, low, high, k, m);
        quickSort(arr, low, p - 1, k, m);
        quickSort(arr, p + 1, high, k, m);
    }
}

void printArray(double **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
vector<double> fractionalKnapSack(double **arr, int n, int m)
{
    int capacity = 500;
    int wt = 0;
    double profit = 0;
    vector<double> finalList(n, 0);
    int i = 0;
    while (wt <= capacity)
    {
        wt = wt + arr[i][0];
        if (wt <= capacity) // so that extra profit cant be added!
        {
            profit = profit + arr[i][1];
            finalList[i] = 1;
            i++;
        }
    }
    int remainWt = wt - capacity;
    wt = wt - remainWt;
    double fraction = (double)( arr[i][0]- remainWt) / arr[i][0];
    profit = profit + fraction * arr[i][1];
    finalList[i] = fraction;

    if (capacity - wt > 0)
    {
        cout << "More stock can be bought\n";
    }

    cout<<"Total Profit is "<<profit<<" for "<<i+1<<" items"<<endl;
    return finalList;
}

void result(double**arr, int n, int m){
    auto start = high_resolution_clock::now();
    vector<double> list = fractionalKnapSack(arr, n, m);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "The duration is " << duration.count() << " milliseconds" << endl;
    for (int i = 0; i < list.size(); i++)
    {
        cout << "item no. " << i + 1 << "'s " << list[i] << endl;
        if(list[i]==0){
            break;
        }
    }
}

int main()
{
    int n;
    int m=3;
    cout << "Enter row and columns for matrix:\n";
    cin >> n ;
    double **arr = new double *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new double[m];
    }
    generateArray(arr, n, m);

    cout<<"--------------------------"<<endl;
    cout<<"Sort Weights"<<endl;
    quickSort(arr, 0, n - 1, 0, m);
    cout << "Weight\tProfit\tProfit/Weight" << endl;
    printArray(arr, n, m);
    result(arr, n, m);
    
    cout<<"--------------------------"<<endl;
    cout<<"Sort Profits"<<endl;
    quickSort(arr, 0, n - 1, 1, m);
    cout << "Weight\tProfit\tProfit/Weight" << endl;
    printArray(arr, n, m);
    result(arr, n, m);

    cout<<"--------------------------"<<endl;
    cout<<"Sort Profit per Weight"<<endl;
    quickSort(arr, 0, n - 1, 2, m);
    cout << "Weight\tProfit\tProfit/Weight" << endl;
    printArray(arr, n, m);
    result(arr, n, m);
    return 0;
}
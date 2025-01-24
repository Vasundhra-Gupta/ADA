#include <iostream>
#include "headers/array2D.h"
using namespace std;

void generateMagicSquare(int **arr, int n)
{
    int i = 0;
    int j = n / 2;
    arr[i][j] = 1;
    int k = 2;
    // row nahi hai;
    // column nahi hai;
    // hai but filled hai;
    // row column dono nahi hai;
    while (k <= n * n)
    {
        int temp_i = i - 1;
        int temp_j = j - 1;

        if (temp_i < 0)
        {
            temp_i = n - 1;
        }
        if (temp_j < 0)
        {
            temp_j = n - 1;
        }
        if (temp_i < 0 && temp_j < 0)
        {
            temp_i = i + 1;
            temp_j = j;
        }
        if (arr[temp_i][temp_j] != 0)
        {
            temp_i = i + 1;
            temp_j = j;
        }

        i = temp_i;
        j = temp_j;

        arr[i][j] = k;
        k++;
    }
}

int main()
{
    int n;
    cout << "Enter size of matrix " << endl;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "Magic Square is possible only with odd matrix.";
        return 0;
    }
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n]();
    }
    generateMagicSquare(arr, n);
    printArray(arr, n);
    return 0;
}
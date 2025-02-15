#define DETERMINANT_H
#ifdef DETERMINANT_H
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getMinor(vector<vector<int>> matrix, int row, int column)
{
    vector<vector<int>> minor;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (i == row)
            continue;
        vector<int> temp;
        for (int j = 0; j < matrix.size(); j++)
        {
            if (j == column)
                continue;
            temp.push_back(matrix[i][j]);
        }
        minor.push_back(temp);
    }
    return minor;
}

//T(n) = n(T(n-1) + n^2)
//o(n(n! + n^2)) but here n is always 3 so time complexity is constant , i.e 3(3!+9)= 45 O(45);
int determinant(vector<vector<int>> &matrix, int n)
{
    if (n == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    int det = 0;
    //loop n times
    for (int j = 0; j < n; j++)
    {
        vector<vector<int>> minor = getMinor(matrix, j, 2);// O(n^2)
        int cofactor = (j % 2 == 0 ? 1 : -1) * matrix[j][2] * determinant(minor, n - 1);//(n-2)! times
        det += cofactor;
    }
    return det;
}

#endif
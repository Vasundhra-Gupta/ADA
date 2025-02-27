#include <iostream>
#include <vector>
#include "../headers/array2D.h"

using namespace std;

vector<vector<int>> addMatrix(vector<vector<int>> mat1, vector<vector<int>> mat2)
{
    int n = mat1.size();
    // order should be same
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}

vector<vector<int>> multiply(vector<vector<int>> mat1, vector<vector<int>> mat2)
{
    int n = mat1.size();
    if (n == 1)
    {
        return {{mat1[0][0] * mat2[0][0]}};
    }
    int mid = n / 2;
    vector<vector<int>>
        M1(mid, vector<int>(mid)),
        M2(mid, vector<int>(mid)),
        M3(mid, vector<int>(mid)),
        M4(mid, vector<int>(mid)),
        N1(mid, vector<int>(mid)),
        N2(mid, vector<int>(mid)),
        N3(mid, vector<int>(mid)),
        N4(mid, vector<int>(mid));

    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            M1[i][j] = mat1[i][j];
            M2[i][j] = mat1[i][j + mid];
            M3[i][j] = mat1[i + mid][j];
            M4[i][j] = mat1[i + mid][j + mid];

            N1[i][j] = mat2[i][j];
            N2[i][j] = mat2[i][j + mid];
            N3[i][j] = mat2[i + mid][j];
            N4[i][j] = mat2[i + mid][j + mid];
        }
    }

    vector<vector<int>>
        A00(mid, vector<int>(mid)),
        A01(mid, vector<int>(mid)),
        A10(mid, vector<int>(mid)),
        A11(mid, vector<int>(mid));

    A00 = addMatrix(multiply(M1, N1), multiply(M2, N3));
    A01 = addMatrix(multiply(M1, N2), multiply(M2, N4));
    A10 = addMatrix(multiply(M3, N1), multiply(M4, N3));
    A11 = addMatrix(multiply(M3, N2), multiply(M4, N4));

    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            result[i][j] = A00[i][j];
            result[i][j + mid] = A01[i][j];
            result[i + mid][j] = A10[i][j];
            result[i + mid][j + mid] = A11[i][j];
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> matrix1 = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
    };
    vector<vector<int>> matrix2 = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
    };
    int row1 = matrix1.size(), col1 = matrix1[0].size(), row2 = matrix2.size(), col2 = matrix2[0].size();

    if (col1 != row2)
    {
        cout << "Matrix multiplication is not possible with these dimensions.\n";
        return 0;
    }
    vector<vector<int>> result = multiply(matrix1, matrix2);
    printArray(result);
    return 0;
}
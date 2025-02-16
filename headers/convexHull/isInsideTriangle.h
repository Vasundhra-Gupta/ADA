#define ISINSIDETRIANGLE_H
#ifdef ISINSIDETRIANGLE_H
#include <iostream>
#include <vector>
#include "./determinant.h"
using namespace std;

int crossProduct(int x1, int y1, int x2, int y2, int x, int y)
{
    vector<vector<int>> mat = {
        {x1, x2, x},
        {y1, y2, y},
        {1, 1, 1},
    };
    int det = determinant(mat, mat.size());//O(c) for 3*3 matrix
    return det;
}

//constant complexity
bool isPointInternalToTriangle(vector<vector<int>> triangle, int x, int y)
{
    int d1 = crossProduct(triangle[0][0], triangle[0][1], triangle[1][0], triangle[1][1], x, y);
    int d2 = crossProduct(triangle[1][0], triangle[1][1], triangle[2][0], triangle[2][1], x, y);
    int d3 = crossProduct(triangle[2][0], triangle[2][1], triangle[0][0], triangle[0][1], x, y);
    return (d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0);
}

#endif

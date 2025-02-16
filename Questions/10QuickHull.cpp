#include <iostream>
#include <vector>
#include "../headers/convexHull/generateRandomPoints.h"
#include "../headers/convexHull/isInsideTriangle.h"
#include "../headers/minMaxIndexInArray.h"
using namespace std;

void print(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "(" << arr[i][0] << "," << arr[i][1] << ") " ;
    }
    cout << endl;
}

vector<vector<int>> farthestPoint(vector<vector<int>> allPoints)
{
    int maxX = 0, minX = 0;
    vector<int> xCoordinates;
    for (int i = 0; i < allPoints.size(); i++)
    {
        xCoordinates.push_back(allPoints[i][0]);
    }
    maxMin(xCoordinates, 0, xCoordinates.size() - 1, maxX, minX);
    return {{allPoints[minX][0], allPoints[minX][1]}, {allPoints[maxX][0], allPoints[maxX][1]}};
}

vector<int> findMaxAreaPoint(vector<int> point1, vector<int> point2, vector<vector<int>> region)
{
    double maxArea = 0;
    int maxAreaIndex = 0;
    for (int i = 0; i < region.size(); i++)
    {
        double area = crossProduct(point1[0], point1[1], point2[0], point2[1], region[i][0], region[i][1]) / 2;
        if (area > maxArea)
        {
            maxArea = area;
            maxAreaIndex = i;
        }
    }
    return {region[maxAreaIndex][0], region[maxAreaIndex][1]};
}

void findRegions(vector<vector<int>> farthestPoints, vector<vector<int>> points, vector<vector<int>> &upper, vector<vector<int>> &lower)
{
    for (int i = 0; i < points.size(); i++)
    {
        int det = crossProduct(farthestPoints[0][0], farthestPoints[0][1], farthestPoints[1][0], farthestPoints[1][1], points[i][0], points[i][1]);
        if (det < 0)
        {
            lower.push_back({points[i][0], points[i][1]});
        }
        else if (det > 0)
        {
            upper.push_back({points[i][0], points[i][1]});
        }
    }
}

void findExteriorPoints(vector<vector<int>> points, vector<int> min, vector<int> max, vector<vector<int>> &polygon)
{
    if (!points.empty())
    {
        vector<int> newPoint = findMaxAreaPoint(min, max, points);
        cout << "point with maximum area: " << "(" << newPoint[0] << "," << newPoint[1] << ")" << endl;
        polygon.push_back(newPoint);
        vector<vector<int>> right, left;
        for (int i = 0; i < points.size(); i++)
        {
            int det1 = crossProduct(min[0], min[1], newPoint[0], newPoint[1], points[i][0], points[i][1]);
            if (det1 > 0)
            {
                left.push_back({points[i][0], points[i][1]});
            }
            int det2 = crossProduct(max[0], max[1], newPoint[0], newPoint[1], points[i][0], points[i][1]);
            if (det2 < 0)
            {
                right.push_back({points[i][0], points[i][1]});
            }
        }
        cout << "left regions for (" << min[0] << "," << min[1] << ") and (" << newPoint[0] << "," << newPoint[1] << "): " ;
        print(left);
        cout << "right regions for (" << max[0] << "," << max[1] << ") and (" << newPoint[0] << "," << newPoint[1] << "): ";
        print(right);
        findExteriorPoints(left, min, newPoint, polygon);
        findExteriorPoints(right, newPoint, max, polygon);
    }
}

int main()
{
    cout << "Enter size of array\n";
    int n;
    cin >> n;
    vector<vector<int>> points;
    generateRandomPoints(points, n);

    // vector<vector<int>> points = {
    //     {4, 10},
    //     {7, 10},
    //     {3, 8},
    //     {1, 2},
    //     {4, 6},
    //     {7, 10},
    //     {8, 6},
    //     {1, 3},
    //     {3, 2},
    //     {8, 4}};

    cout << "Given Points:" << endl;
    print(points);

    vector<vector<int>> polygon;
    vector<vector<int>> farthestPoints = farthestPoint(points);
    vector<int> min = farthestPoints[0], max = farthestPoints[1];
    polygon.insert(polygon.end(), {min, max});
    vector<vector<int>> upper, lower;
    findRegions(farthestPoints, points, upper, lower);
    cout<<"Upper Region: ";
    print(upper);
    cout<<"Lower Region: ";
    print(lower);
    findExteriorPoints(upper, min, max, polygon);
    findExteriorPoints(lower, max, min, polygon);
    print(polygon);
    return 0;
}
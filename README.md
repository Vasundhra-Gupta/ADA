# ADA

Analysis and Design of Algorithms

## 1. Find peak elements in a 1D array

### Problem :- 
Find the index [i] of any peak element (an element that is greater than or equal to its neighbors- left and right) present in a 1D array
**Note: No duplicates are allowed**

### Solution :- 
To find this, we use **Divide and Conquer Approach** implemented via **binary search**.
- At Each Step, we find middle element of the array.
- Then it is compared with its neighbours.
- If its left neighbour is greater than middle, then peak element must be in left and right part is discarded.
- If its right neighbour is greater than middle, then peak element must be in right and left part is discarded.
- If the middle element is greater than both neighbors (or at a boundary), it is a peak element, and we return its index.

**TIME COMPLEXITY** : O(logn)
<br>
**SPACE COMPLEXITY** : O(1), or O(logn) due to call Stack for recusrsion

```
#include <iostream>
#include "../headers/array1D.h"
using namespace std;

int peak(int *nums, int low, int high)
{
    int mid = (low + high) / 2;
    if (mid > 0 && nums[mid] < nums[mid - 1])
    {
        return peak(nums, low, mid);
    }
    else if (mid < high && nums[mid] < nums[mid + 1])
    {
        return peak(nums, mid + 1, high);
    }else{
        return mid;
    }
}

int main()
{
    int n;
    cout << "Enter n for array: " << endl;
    cin >> n;
    int arr[n];
    inputArray(arr, n);
    printArray(arr, n);
    cout << "The Peak Element is at index " << peak(arr, 0, n - 1);
    return 0;
}
```

---

## 2. Find peak elements in a 2D array

### Problem :- 
Find the index [i][j] of any the peak element (an element that is greater than or equal to its four neighbours- top, bottom, left, right) present in a 2D array
**Note: Edge elements are compared with only their existing neighbours**

### Solution :- 
To find this, we use **Divide and Conquer Approach** implemented via **Modified Binary Search on columns**.
- First, We find middle column and in this column we find the maximum element.
- Then it is compared with its neighbours.
- If its left neighbour is greater than middle, then peak element must be in left and right part is discarded.
- If its right neighbour is greater than middle, then peak element must be in right and left part is discarded.
- If the middle element is greater than both neighbors (or at a boundary), it is a peak element, and we return its index.

**TIME COMPLEXITY**: O(logn)
<br>
**SPACE COMPLEXITY**: O(1), or O(logn) due to call Stack for recusrsion

```
#include <iostream>
#include <vector>
#include "../headers/array2D.h"
using namespace std;

vector<int> peakGrid(int**arr,int low, int high, int row)
{
    vector<int> result(2);
    int mid = (low+high) / 2;
    int max = 0;
    for (int i = 0; i < row; i++)
    {
        if (arr[i][mid] > arr[max][mid])
        {
            max = i;
        }
    }
    if (mid > 0 && arr[max][mid] < arr[max][mid - 1])
    {
        return peakGrid(arr, low, mid - 1, row);
    }
    else if (mid < high && arr[max][mid] < arr[max][mid + 1])
    {
        return peakGrid(arr, mid + 1, high, row);
    }
    else
    {
        result[0] = max;
        result[1] = mid;
        return result;
    }
}

int main()
{
    cout<<"Enter the size of square matrix: "<<endl;
    int n;
    cin>>n;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    inputSquaredArray(arr, n);
    printArray(arr, n, n);
    vector<int> result = peakGrid(arr, 0, n-1, n);
    int i= result[0];
    int j = result[1];
    cout<<"The Peak element is at index ["<<i<<","<<j<<"]"<<endl;
    return 0;
}
```

---

## 3. Magic Square Problem

### Problem :-

### Solution :-

**TIME COMPLEXITY**: O(n*n)
<br>
**SPACE COMPLEXITY**: O(1)

```
#include <iostream>
#include "../headers/array2D.h"
using namespace std;

void generateMagicSquare(int **arr, int n)
{
    int i = 0;
    int j = n / 2;
    arr[i][j] = 1;
    int k = 2;
    
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
    printArray(arr, n, n);
    return 0;
}
```

--- 

## 4. Fractional KnapSack Problem

### Problem :-

### Solution :-

```
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
```

--- 

## 5. Maximum Stack Space used in Quick Sort in Recursion

### Problem :-

### Solution :-

```
#include <iostream>
using namespace std;
#include "../headers/array1D.h"

static int space = 0;
static int maxSpace= 0;
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {

        while (arr[i] <= pivot && i <= high)
        {
            i++;
        };

        while (arr[j] > pivot && j > low)
        {
            j--;
        };
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    };
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        space++;
        maxSpace= max(maxSpace,space);
        cout<<"Space "<<space<<endl;
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
        space--;
    }
}

int main()
{
    cout << "Enter size of the array" << endl;
    int n;
    cin >> n;
    int *arr = new int[n];
    generateArray(arr, n);
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    cout<<"Max Space used is "<<maxSpace<<endl;
    return 0;
}
```

--- 

## 6. Activity Selection Problem

### Problem :-

### Solution :-

--- 

## 7. Iterative Quick Sort

### Problem :-

### Solution :-

```
#include <iostream>
#include <stack>
#include "../headers/array1D.h"
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (arr[i] <= pivot && i <= high)
        {
            i++;
        };
        while (arr[j] > pivot && j > low)
        {
            j--;
        };
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    };
    swap(arr[low], arr[j]);
    return j;
}

// void quickSort(int arr[], int low, int high)
// {
//     stack<int> st;
//     while (true)
//     {
//         while (low < high)
//         {
//             int j = partition(arr, low, high);
//             if (j - low <= high - j)
//             {
//                 low = j + 1;
//                 st.push(low);
//                 st.push(high);
//             }
//             else
//             {
//                 high = j - 1;
//                 st.push(low);
//                 st.push(high);
//             }
//         }
//         if (st.empty())
//         {
//             return;
//         }
//         else
//         {
//             high = st.top();
//             st.pop();
//             cout<<"high"<<high<<endl;
//             low = st.top();
//             st.pop();
//             cout<<"low"<<low<<endl;
//         }
//         // cout<<st.size()<<endl;
//     }
// }

void quickSort(int arr[], int low, int high)
{
    stack<int> st;
    while (true)
    {
        while (low < high)
        {
            int j = partition(arr, low, high);
            if (j - low <= high - j)
            {
                st.push(j+1);
                st.push(high);
                high = j-1;
            }
            else
            {
                st.push(low);
                st.push(j-1);
                low = j + 1;
            }
        }
        if (st.empty())
        {
            return;
        }
        else
        {
            high = st.top();
            st.pop();
            low = st.top();
            st.pop();
        }
        // cout<<st.size()<<endl;
    }
}

int main()
{
    // cout << "Enter size of an array" << endl;
    // int n;
    // cin >> n;
    // int *arr = new int[n];
    // generateArray(arr, n);
    int arr [] = {5, 3, 1, 0 , 7, 0};
    printArray(arr, 6);
    quickSort(arr, 0,6-1);
    printArray(arr, 6);
    return 0;
}
```

---

## 8. Matrix Multiplication (Divide and Conquer)

### Problem :-

### Solution :-

```
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
```

--- 

## 9. Stressens Multiplication

### Problem :-

### Solution :-

--- 

## 10. Convex Hull Problem

### Problem :-

### Solution :-

```
#include <iostream>
#include <vector>
#include <ctime>
#include "../headers/array2D.h"
#include "../headers/convexHull/generateRandomPoints.h"
#include "../headers/convexHull/generateTriangles.h"
#include "../headers/convexHull/isInsideTriangle.h"
using namespace std;

// O(n^4) complexity.
void ConvexHull(vector<vector<int>> arr)
{
    vector<vector<vector<int>>> triangles = allTriangles(arr, arr.size()); // O(n^3)
    cout << triangles.size() << " triangles" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        bool isInternal;
        for (int j = 0; j < triangles.size(); j++)
        {
            isInternal = isPointInternalToTriangle(triangles[j], arr[i][0], arr[i][1]);
            if (isInternal)
                break;
        }
        if (!isInternal)
            cout << "(" << arr[i][0] << "," << arr[i][1] << ")" << endl;
    }
}

int main()
{
    cout << "Enter the value of n" << endl;
    int n;
    cin >> n;
    vector<vector<int>> arr;
    generateRandomPoints(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << "(" << arr[i][0] << "," << arr[i][1] << ")" << endl;
    }
    cout << "____________" << endl;

    ConvexHull(arr);

    return 0;
}
```
---

## 11. Quick Hull

### Problem :-

### Solution :-

```
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
```

--- 

## 12. Single Source Shortest Path

### Problem :-

### Solution :-

```
#include <iostream>
#include <vector>
#include "../headers/array1D.h"
#include <climits>
using namespace std;

int getMinDistantUnvisitedNode(vector<int> dist, vector<bool> flag)
{
    int min = -1;
    for (int i = 0; i < dist.size(); i++)
    {
        if (flag[i] == false && dist[i] < dist[min])
        {
            min = i;
        }
    }
    return min;
}

void SSSP(vector<vector<int>> adj, int source, vector<int> &dist, vector<string> &path)
{
    int n = adj.size(); // number of vertices
    vector<bool> flag(n, false);
    // initial distances of all vertices from source
    for (int i = 0; i < n; i++)
    {
        dist[i] = adj[source][i];
        path[i] = to_string(source) + "->" + to_string(i);
    }

    flag[source] = true;

    printArray(dist);
    printArray(flag);

    for (int i = 1; i < n; i++)
    {
        int minVertex = getMinDistantUnvisitedNode(dist, flag);
        cout << "min vertex: " << minVertex << endl;
        if (minVertex == -1)
        {
            break;
        }
        flag[minVertex] = true;
        for (int j = 0; j < n; j++)
        {
            if (!flag[j] && adj[minVertex][j] != INT_MAX && dist[j] > dist[minVertex] + adj[minVertex][j])
            {
                dist[j] = dist[minVertex] + adj[minVertex][j];
                path[j] = path[minVertex] + "->" + to_string(j);
            }
        }
    }
}
int main()
{
    // vertices-> 0, 1, 2, 3
    vector<vector<int>> adj = {
        {0, 5, 1, INT_MAX},
        {INT_MAX, 0, 7, 4},
        {INT_MAX, INT_MAX, 0, 6},
        {3, INT_MAX, INT_MAX, 0},
    };
    int source = 2, n = adj.size();
    vector<int> dist(n);
    vector<string> path(n);
    SSSP(adj, source, dist, path);
    printArray(dist);
    printArray(path);
    return 0;
}
```
---

## 13. Prims Algorithm

### Problem :-

### Solution :-

```
#include <iostream>
#include <vector>
#include <climits>
#include "../headers/array1D.h"
#include "../headers/array2D.h"
using namespace std;

void MST(vector<vector<int>> adj    , vector<vector<int>> &result, int &minWeight)
{
    int n = adj.size(), k = 0, l = 0;
    adj[k][l] = INT_MAX;
    vector<int> near(adj.size());

    // find minimum edge O(n^2)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] != 0 && adj[i][j] <= adj[k][l])
            {
                k = i;
                l = j;
            }
        }
    }
    result.push_back({k, l});
    near[k] = -1;
    near[l] = -1;
    minWeight += adj[k][l];

    // assign nearest vertex from processes vertex to unprocessed ones O(n)
    for (int i = 0; i < n; i++)
    {
        if (near[i] != -1) // unprocessed
        {
            if (adj[i][k] > adj[i][l])
            {
                near[i] = l;
            }
            else
            {
                near[i] = k;
            }
        }
    }

    // O(n^2)
    for (int j = 0; j < n - 2; j++)
    {
        // find min near
        int minNear = -1;
        int minNearVal = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (near[i] != -1 && adj[i][near[i]] < minNearVal)
            {
                minNearVal = adj[i][near[i]];
                minNear = i;
            }
        }
        if (minNear == -1)
        {
            cout << "No MST possible, disconnected graph." << endl;
            result.clear();
            minWeight = 0;
            return;
        }
        // push that min near to vistited and
        result.push_back({minNear, near[minNear]});
        minWeight += adj[minNear][near[minNear]];
        // cout<<"Minimum Weight for : "<<minNear<<" and" <<near[minNear]<<" is " <<minWeight<<endl;
        near[minNear] = -1;
        // again update near vertex and minWeight acc. to minVertex(additional competitor now),
        for (int i = 0; i < n; i++)
        {
            if (near[i] != -1 && adj[i][minNear] != INT_MAX)
            {
                if (adj[i][near[i]] > adj[i][minNear])
                {
                    near[i] = minNear;
                }
            }
        }
    }
}

int main()
{
    // vertices (0, 1, 2, 3, 4)
    vector<vector<int>> adj = {
                            // {0, 4, 1, INT_MAX, INT_MAX},
                            // {4, 0, 2, 5, INT_MAX},
                            // {1, 2, 0, 8, 10},
                            // {INT_MAX, 5, 8, 0, 3},
                            // {INT_MAX, INT_MAX, 10, 3, 0}
                            {0, 28, INT_MAX, INT_MAX, INT_MAX, 10, INT_MAX},
                            {28, 0, 16, INT_MAX, INT_MAX, INT_MAX, 14},
                            {INT_MAX, 16, 0, 12, INT_MAX, INT_MAX, INT_MAX},
                            {INT_MAX, INT_MAX, 12, 0, 22, INT_MAX, 18},
                            {INT_MAX, INT_MAX, INT_MAX, 22, 0, 25, 24},
                            {10, INT_MAX, INT_MAX, INT_MAX, 25, 0, INT_MAX},
                            {INT_MAX, 14, INT_MAX, 18, 24, INT_MAX, 0},
                        },
                        result;
    int minWeight = 0;

    MST(adj, result, minWeight);

    if (result.size())
    {
        cout << "result: " << endl;
        printArray(result);
        cout << "Minimum Weight of MST: " << minWeight << endl;
    }
    return 0;
}
```

---

## 14. Kruskal Algorithm

### Problem :-

### Solution :-

---

## 15. MultiStage Graph Problem

### Problem :-

### Solution :-

```
#include <iostream>
#include <vector>
#include <climits>
#include "../../headers/array1D.h"
#include "../../headers/array2D.h"
#include "./15findStages.cpp"
using namespace std;

// Time complexity: n^2
void MGP(vector<vector<int>> &cost, int k, int n)
{
    vector<int> fdist(n, 0);
    vector<int> d(n, 0);
    vector<int> path(k, 0);
    fdist[n - 1] = 0;
    path[0] = 0;
    path[k - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        int min = INT_MAX;
        for (int j = i + 1; j < n; j++)
        {
            if (cost[i][j] != INT_MAX && cost[i][j] != 0)
            {
                if (cost[i][j] + fdist[j] < min)
                {
                    min = cost[i][j] + fdist[j];
                    fdist[i] = cost[i][j] + fdist[j];
                    d[i] = j;
                }
            }
        }
    }
    for (int i = 1; i < k - 1; i++)
    {
        path[i] = d[path[i - 1]];
    }
    cout << "fdist Array:" << endl;
    printArray(fdist);
    cout << "Path:" << endl;
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i != path.size() - 1) cout << " -> ";
    }
}
int main()
{
    vector<vector<int>> adj = {
        // {0, 4, 1, INT_MAX},
        // {INT_MAX, 0, INT_MAX, 6},
        // {INT_MAX, INT_MAX, 0, 8},
        // {INT_MAX, INT_MAX, INT_MAX, 0},
        {0, 2, 5, 10, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 0, INT_MAX, INT_MAX, 7, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, INT_MAX, 1, 9, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 0, 6, 3, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 6},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 4},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0},
    };
    int stages = countStages(adj);
    MGP(adj, stages, adj.size());

    return 0;
}       
```

---


## 16. Number of Stages in Graph

### Problem :-

### Solution :-

```
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int countStages(vector<vector<int>> &cost)
{
    int n = cost.size();
    int stageCount = 1;
    // vector<vector<int>> stages;
    int i = 0;
    while (i < n - 1)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (cost[i][j] != INT_MAX)
            {
                // stages.push_back({i, j});
                i = j;
                stageCount++;
            }
        }
    }
    return stageCount;
}

// int main()
// {
//     vector<vector<int>> adj = {
//         // {0, 4, 1, INT_MAX},
//         // {INT_MAX, 0, INT_MAX, 6},
//         // {INT_MAX, INT_MAX, 0, 8},
//         // {INT_MAX, INT_MAX, INT_MAX, 0},
//         {0, 2, 5, 10, INT_MAX, INT_MAX, INT_MAX},
//         {INT_MAX, 0, INT_MAX, INT_MAX, 7, 3, INT_MAX},
//         {INT_MAX, INT_MAX, 0, INT_MAX, 1, 9, INT_MAX},
//         {INT_MAX, INT_MAX, INT_MAX, 0, 6, 3, INT_MAX},
//         {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 6},
//         {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 4},
//         {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0},
//     };

//     int stages = countStages(adj);
//     cout << "The number of stages are: " << stages;
//     return 0;
// }
```

---


## 17. All Pair Shortest Path

### Problem :-

### Solution :-

---

## 18. N Queen Problem

### Problem :-

In n dimensional space , we need to adjust queens such that, no two queens are in the same row, same column or diagnal to each other.

### Solution :-

1. Going from 1 to n, check if current queen can be placed in the ith column ---> Then move to next queen and check where it can be placed---> if no place is found, then backtracking happens and again the queens are replaces

```
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> x){
    for(int val: x){
        cout<<val<<" ";
    }
    cout<<endl;
}

bool Place(int k, int i, vector<int> x){
    for(int j=0; j<k; j++){
       if(x[j]==i || abs(k-j)==abs(i-x[j])) return false;
    }
    return true;
}

void NQueen(int k, int n, vector<int> &x, bool done){
    if(k==n){
        return;
    }
    for(int i=0; i<n; i++){
        if(done) break;
        cout << "k: " << k << endl;
        if(Place(k, i, x)){
            x[k] = i;
            cout << "i: "<<i<< endl;
            if(k==n-1){
                print(x);
                done = true;
            }else{
                NQueen(k+1, n, x,done);
            }
        }
    }
    cout << "B" << endl;
}

int main(){
    int n;
    cout<<"Enter number of queens"<<endl;
    cin>>n;
    vector<int> x(n);
    NQueen(0, n, x, false);
    return 0;
}
```

--- 

## 19. Floor Colorings

### Problem:-
### Solution:- 

--- 

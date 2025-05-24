# ADA

Analysis and Design of Algorithms

## What is Alogorithm?
Algorithm is a finite sequence of steps used to solve a particular problem.

### Characterstics of an Algorithm
- Terminates in finite number of steps
- Language independent.
- Each step is non ambigous- Definiteness
- Each step contribute something towards final solution.
- Minimum inputs: 0
- Minimum outputs: 1

### How to validate algorithm?
1. **Correctness** - Whether the analyze give correct output on the input given.
2. **Edge Case** - Handles boundary inputs safely

### How to analyze algorithm?
- **Time Complexity** - Time required by an Algorithm to run to its completion.
- **Space Complexity** - Space required by an Algorithm to run to its completion.

### How to test algorithm?
- **Debugging** - Detect and resolve errors.
- **Profiling** - Analyze on basis of complexities.

## Asymptotic Analysis
It's a method of describing the efficiency of an algorithm as the input size n grows very large. We use it to measure Time complexity and Space complexity

### Three main types of Asymptotic Notation
1. **Big-O (O)** - It describes the maximum time (or space) an algorithm takes - the **worst case** upper bound.
   - A function f(n) = O(g(n)) iff there exist constants c > 0 and n₀ ≥ 0 such that *f(n) ≤ c.g(n) for all n ≥ n₀*
2. **Big-omega (Ω)** - It describes the minimum time (or space) an algorithm takes - the **best case** lower bound.
   - A function f(n) = Ω(g(n)) iff there exist constants c > 0 and n₀ ≥ 0 such that *f(n) ≥ c.g(n) for all n ≥ n₀*
3. **Big-theta (Θ)** - It describes the exact time (or space) an algorithm takes - the best and worst case are the same order.
   - A function f(n) = Θ(g(n)) iff there exist constants c₁, c₂ > 0 and n₀ ≥ 0 such that *c₁.g(n) ≤ f(n) ≤ c₂.g(n) for all n ≥ n₀*

## Recurrence relation
It is a function defined in terms of itself, with smaller arguements.
<br>
Example: T(n) = 2T(n/2) + n for n>1 and 1 for n=1 
<br>This is the recurrence relation for merge sort , quick sort etc

### Methods to solve recurrence relation
- Substitution Method
   - Guess the Solution
   - Use Induction to find the constants and show that the solution is true.
- Iterative method
   - Resubstitute recurrence relation again and again to get generalised form
   - But this is not useful for the ones for which we wre not able to get generalised term.
- Recursion Trees
     - It is used to generate guess for substitution method.
     - Recurrence relation has two parts- one indicates recursion and other indicates the time taken to do each recursion.
- Master's Theorem
     - Comapre f(n) with n^(logb(a))
     - If f(n) is polynomially smaller then T(n) = O(n^(logb(a))
     - If f(n) is polynomially larger then T(n) = 0(f(n)) + it should also hold regularity condition (which is a

<!-- ## Find Maximum element using recursion -->

## Minimize number of multiplications in horner's rule.

### Problem:- 
f(x) = a + bx + cx^2 + dx^3.... is a function and to calculate this a lot of multiplications has to be done, so we need to minimize the number of multiplications to calculate this function.

### Solution:- 
We solve this using **Horner's Rule**.
- It says you can efficiently write this function as f(x) = a + x(b + x(c + dx)
- This reduces a lot of multiplications and now we have result in n multiplications only, where n+1 are the number of terms. 

```cpp
#include <iostream>
using namespace std;
int horner(int* a, int i, int n, int &x){
    if(i==n-1){
        return a[i];
    }else{
        return a[i]+ x* horner(a, i+1, n, x);
    }
}
int main(){
    int a[]= {1, 2, 2, 1};
    int x=2;
    int result = horner(a, 0, 4, x);
    cout<<"result: "<<result<<endl;
    return 0;
}
```
## 1. Find peak elements in a 1D array

### Problem :-

Find the index [i] of any peak element (an element that is greater than or equal to its neighbors- left and right) present in a 1D array
**Note: No duplicates are allowed**

### Solution :-

To find this, we use **Divide and Conquer Approach** implemented via **binary search**.

-   At Each Step, we find middle element of the array.
-   Then it is compared with its neighbours.
-   If its left neighbour is greater than middle, then peak element must be in left and right part is discarded.
-   If its right neighbour is greater than middle, then peak element must be in right and left part is discarded.
-   If the middle element is greater than both neighbors (or at a boundary), it is a peak element, and we return its index.

**TIME COMPLEXITY** : O(logn)<br>
**SPACE COMPLEXITY** : O(1), or O(logn) due to call Stack for recusrsion

```cpp
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

-   First, We find middle column and in this column we find the maximum element.
-   Then it is compared with its neighbours.
-   If its left neighbour is greater than middle, then peak element must be in left and right part is discarded.
-   If its right neighbour is greater than middle, then peak element must be in right and left part is discarded.
-   If the middle element is greater than both neighbors (or at a boundary), it is a peak element, and we return its index.

**TIME COMPLEXITY**: O(logn)<br>
**SPACE COMPLEXITY**: O(1), or O(logn) due to call Stack for recusrsion

```cpp
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

Generate a magic square of size n x n (only for odd n), where the sum of all rows, columns, and diagonals is the same.

### Solution :-

-   Start with placing 1 in the **middle column of the first row**.
-   For every next number:
    -   Move one cell **up and to the right** (i.e., row--, col++).
    -   If the move is **out of the top boundary**, wrap around to the **last row**.
    -   If the move is **out of the right boundary**, wrap around to the **first column**.
    -   If the cell is already filled then Move **one cell down** from the last filled cell,and stay in the **same column**.
    -   If the move is **out of both top row and rightmost column** (i.e., top-right corner):
        -   Move **one cell down** from the last position.
-   Repeat the above steps till all numbers from `1` to `n²` are placed.

**TIME COMPLEXITY**: O(n\*n)
<br>
**SPACE COMPLEXITY**: O(1)

```cpp
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

The Fractional Knapsack Problem is a variant of the classic 0/1 Knapsack problem where:
n items are given, each with a weight and a profit.
The goal is to maximize total profit while ensuring the total weight of selected items does not exceed the given capacity of the knapsack.
Unlike 0/1 Knapsack, here we can break items and take fractions of them.

### Solution :-

1. Generate items with:
    - arr[i][0] → weight
    - arr[i][1] → profit
    - arr[i][2] → profit per weight (profit/weight)
2. Sort the items in **descending order of profit per weight**.
3. Initialize total weight = 0, total profit = 0.
4. For each item in sorted order:
    - If adding the entire item keeps total weight ≤ capacity:
        - Add the whole item.
        - Increase profit accordingly.
    - Else:
        - Take the **fraction** of the item that fits.
        - Add fractional profit.
        - Stop once capacity is full.
5. Track the fraction of each item added using an array.

6. Output:
    - Maximum profit
    - Number of items (including fractional)
    - Execution time (for performance analysis)
  
**TIME COMPLEXITY: O(n*logn)**

```cpp
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
Quick Sort is a recursive, divide-and-conquer sorting algorithm. Your task is to track and find the maximum stack space (i.e., the maximum recursion depth) used during its execution on a given array.

### Solution :-
Why track stack space?
Every recursive call in Quick Sort consumes stack space. In the worst case, this space can grow to O(n) (e.g., when the array is already sorted), and in the average case, it is O(log n).

How to track?
- Use a global or reference variable currDepth to track current recursion depth.
- Maintain another variable maxDepth to store the maximum value reached by currDepth during recursion.
- Increment currDepth before making recursive calls and decrement it after returning.

```cpp
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

Traditionally, Quick Sort is implemented recursively, which may lead to stack overflow for large input sizes due to deep recursion.
Implement QuickSort iteratively using a stack, to avoid recursion and manually manage the call stack.
The core idea is to replace the function call stack with an explicit stack.

### Solution :-

-   Select the first element as the pivot in the partition() function.
-   Rearrange elements so that smaller ones are left of pivot and larger ones are right.
-   Use an explicit stack instead of recursion to manage low and high indices.
-   Push initial low and high values onto the stack.
-   Pop low and high, then perform partitioning to find the correct pivot index.
-   Push the subarrays’ indices back onto the stack for further sorting.
-   Always push the larger subarray later to minimize stack size.
-   Repeat the process until the stack is empty.
-   Finally, the array gets sorted in-place without recursion.

```cpp
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
    }
}

int main()
{
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

Multiply two square matrices using the Divide and Conquer approach.
Input: Two 2D square matrices of equal dimensions (power of 2 preferred).
Output: A single matrix that is the product of the two given matrices.
Objective: Implement recursive matrix multiplication by breaking the matrices into quadrants.
Constraints: Matrix sizes must be powers of 2 and both matrices must be square.

### Solution :-

-   Check if the matrix size is 1 (base case), directly multiply and return result.
-   Divide both matrices into four equal-sized submatrices (quadrants).
-   Recursively multiply relevant submatrices to form each quadrant of the result matrix.
-   Combine the four resulting quadrants into the final result matrix.
-   Use a helper function to add two matrices during intermediate steps.
-   The solution mimics Strassen’s idea without reducing multiplication count.
-   Works recursively and combines results back efficiently for larger matrices.

```cpp
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

Given a set of points in 2D space, compute the smallest convex polygon enclosing all of them.
A point is part of the convex hull if it lies on the outermost boundary.
Used in image processing, robotics, computer graphics, and geospatial applications.

### Solution :-

-   Iterate through every pair of points in the set.
-   For each line formed by a pair, check the orientation of all other points.
-   If all other points lie on the same side of the line (or on the line), mark both endpoints as hull points.
-   Use cross-product or slope comparison to determine side/orientation.
-   Store unique points that satisfy the convex hull condition.
-   Sort final hull points (optional) to connect and visualize the polygon.

**TIME COMPLEXITY** O(n³) time complexity due to triple nested loops.

```cpp
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

Given a set of points in a 2D plane, find the minimum boundary polygon enclosing all the points.
Output the Convex Hull, i.e., the outermost points forming a convex polygon.
Application: Shape recognition, collision detection, pattern analysis, GIS mapping.

### Solution :-

-   Find leftmost and rightmost points (min and max x-coordinates).
-   These two points form a line dividing the set into upper and lower subsets.
-   For each side, find the farthest point from the line to form a triangle.
-   Recursively apply the same process on the remaining outer points (outside the triangle).
-   Skip all interior points; only outermost ones are considered.
-   Combine all recursive results to get the final Convex Hull.
-   Works in expected O(n log n) time, similar to Quick Sort strategy.
-   Efficient for sparse hulls (when few points lie on the boundary).

```cpp
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
The problem is to find the shortest path from a given source vertex to all other vertices in a weighted, directed graph using **Dijkstra's algorithm**. The graph is represented by an adjacency matrix where each element represents the weight of the edge between two vertices, and INT_MAX signifies no direct edge between them. The goal is to compute the minimum distance and the corresponding path from the source to all other vertices.


### Solution :-
- Initialize distances to all vertices and set the path from the source.
- Use a greedy approach to select the unvisited vertex with the smallest distance.
- Update the distances and paths of neighboring vertices if a shorter path is found.
- Repeat until all vertices are visited, yielding the shortest paths and distances from the source.


```cpp
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
Given a connected, undirected, weighted graph, the task is to find a **Minimum Spanning Tree (MST)** — a subset of edges that connects all the vertices with minimum total edge weight and no cycles.

### Solution :-
- Prim’s Algorithm grows the MST one vertex at a time starting from any node.
- It selects the edge with the minimum weight that connects a visited node to an unvisited node.
- Uses a priority queue or min-heap (or simple arrays in basic implementations) to always pick the next minimum weight edge.
- Continue until all nodes are included in the MST.

```cpp
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
    vector<vector<int>> adj = {
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

Multistage graph is a directed, weighted graph divided into several stages.
Each node belongs to a specific stage, and edges go only from one stage to the next.
The task is to find the number of stages in the given multistage graph.
This helps in solving problems like shortest path or dynamic programming on such graphs.

### Solution :-

-   Initialize stage count to 1 (starting from source).
-   Start from the first node and scan forward to find the next reachable node.
-   If a forward edge exists (cost ≠ INT_MAX), move to that node and increment the stage count.
-   Continue this till the destination is reached.
-   Return the total number of stage transitions counted.
-   The logic simulates linear traversal from source to destination across valid paths.
-   Ensures that only connected paths influence the stage count.

```cpp
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

Multistage graph is a directed, weighted graph divided into several stages.
Each node belongs to a specific stage, and edges go only from one stage to the next.
The task is to find the number of stages in the given multistage graph.
This helps in solving problems like shortest path or dynamic programming on such graphs.

### Solution :-

-   Initialize stage count to 1 (starting from source).
-   Start from the first node and scan forward to find the next reachable node.
-   If a forward edge exists (cost ≠ INT_MAX), move to that node and increment the stage count.
-   Continue this till the destination is reached.
-   Return the total number of stage transitions counted.
-   The logic simulates linear traversal from source to destination across valid paths.
-   Ensures that only connected paths influence the stage count.

```cpp
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
    cout << "The number of stages are: " << stages;
    return 0;
}
```

---

## 17. All Pair Shortest Path

### Problem :-

### Solution :-

---

---

## 18. SORTINGS

### Problem:-
Selection Sort

### Solution:-

```cpp
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
        (arr, n);
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
```


### Problem:-
Quick Sort

### Solution:-

```cpp
#include <iostream>
#include "../headers/array1D.h"
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

```

### Problem:-
Merge Sort

### Solution:-

```cpp
#include <iostream>
using namespace std;
#include "../headers/array1D.h"
#include <chrono>

void merge(int *arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int* b = new int[high-low+1];
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            b[k++] = arr[i++];
        }
        else
        {
            b[k++] = arr[j++];
        }
    }

    while(i<=mid){
        b[k++] = arr[i++];
    }
    while(j<=high){
        b[k++] = arr[j++];
    }

    for(int i = low; i<=high; i++){
        arr[i] = b[i-low];
    }
      delete[] b;
}

void mergeSort(int *arr, int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    cout << "Enter size of array: " << endl;
    int n;
    cin >> n;
    int arr[n];
    int totalDuration = 0;

    for (int i = 0; i < 10; i++)
    {
        generateArray(arr, n);
        // printArray(arr, n);

        auto start = chrono::high_resolution_clock::now();
        mergeSort(arr, 0, n - 1);
        auto end = chrono::high_resolution_clock::now();
        // printArray(arr, n);
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        totalDuration+= duration.count();
        cout << "The duration is " << duration.count() << " milliseconds" << endl;
    }
    cout << "THE AVERAGE TIME TAKEN FOR THE PROGRAM FOR INPUT SIZE " << n << " IS " << totalDuration / 10 << " MILISECONDS" << endl;

    return 0;
}
```

--- 

# DYNAMIC PROGRAMMING

Dynamic Prgramming is a method for solving pprblem by breaking them down into overlapping subproblems and storing results to avoid redundance computations.
It works when: 
<br>
**Optimal substructure**: Problem can be broken into subproblems.
**Overlapping subproblems** : Same subproblems multiple times.

## 19. N Queen Problem

### Problem :-

In n dimensional space , we need to adjust queens such that, no two queens are in the same row, same column or diagnal to each other.

### Solution :-

1. Going from 1 to n, check if current queen can be placed in the ith column ---> Then move to next queen and check where it can be placed---> if no place is found, then backtracking happens and again the queens are replaces

```cpp
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

## 20. Floor Colorings

### Problem:-

We are given a building with multiple floors, where some are directly connected (adjacent).
The goal is to assign colors to each floor using at most m colors.
No two adjacent floors can be assigned the same color.
The adjacency of floors is represented using an adjacency matrix.

### Solution:-

-   Represent floors and their connections using a graph (adjacency matrix).
-   Use backtracking to try assigning colors to each floor.
-   Use a helper function to check if a color is safe for the current floor.
-   Recursively assign colors floor by floor, backtracking when conflicts arise.
-   If a valid coloring is found for all floors, print the configuration.
-   Explores all valid combinations — brute-force with pruning via backtracking.
-   Solves the m-coloring problem, a classic constraint satisfaction problem.

```cpp
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> x)
{
    for (int val : x)
    {
        cout << val << " ";
    }
    cout << endl;
}

bool Color(int k, int i, vector<int> x, vector<vector<int>> rooms)
{
    for (int j = 0; j < k; j++)
    {
        if (x[j] == i && rooms[k][j])
            return false;
    }
    return true;
}

void FC(int k, vector<vector<int>> rooms, int m, vector<int> &x)
{
    int n = rooms.size();
    if (k == n)
    {
        return;
    }
    for (int i = 0; i < m; i++)
    {
        cout << "k: " << k << endl;
        if (Color(k, i, x, rooms))
        {
            x[k] = i;
            cout << "i: " << i << endl;
            if (k == n - 1)
            {
                print(x);
            }
            FC(k + 1, rooms, m, x);
        }
    }
    cout << "B" << endl;
}

int main()
{
    int m;
    cout << "Enter number of colors" << endl;
    cin >> m;
    vector<vector<int>> rooms = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0},
    };
    vector<int> x(rooms.size());
    FC(0, rooms, m, x);
}
```

---

## 21. Matrix Chain Multiplication

### Problem:-
Given n matrices, find the minimum number of scalar multiplications needed to multiply them.

### Solution:-
We are given with chains of Matrices. We need to find an order in which matrices must be multiplied to get minimum number of scalor multipliation. We can do this by puttng parenthesis. We don't need to actually multiply matrices, we just need to find order of thrir multiplication.
<br>
Given order array as p(1), p(2), p(3), .... p(n), such that Order of A(i) has p(i) * p(i+1) <br>
Number of Scalor MUltiplications for two matrices of order p  * q and q * r respectively, is **p * q * r**<br>
m[i,j] is the minimum number of scalor multuplication matrices from i to jth index like A(i), A(i+1)...A(j)<br>
m[i,j] = { 0 if i=j, min{m[i,k] + m[k,j] + p(i) * p(k+1) * p(j+1), m[i,j]} if i<=k<j}<br>  
So we would be returning, order of matrices for matrix multiplications, and minumum scalor multiplications!!!

## 22. Longest Common Subsequence

### Problem:-
Given with 2 string, X and Y , We need to find longest common subsequence of X and Y .

### Solution:-
A subsequence is the part of the string, and we are to find the common parts.
Mathematically, X(i) is the string from 1 to ith index and z1, z2, z3....zk are the subsequences of X (say) such that X(i1) = z1, X(i2) = z2 ...X(in) = zk
Now, c[i,j] give the length of longest subsequence when X(i) and Y(j) is considered.
c[i,j] = {1+ c[i-1,j-1] if x(i) = y(j) , max{c[i-1,j], c[i, j-1] if x(i) not equl to y(j) , and 0 if i=0 or j=0}

## 23. Sum of Subsets
### Problem:- 





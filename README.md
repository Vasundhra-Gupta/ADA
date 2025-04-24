# ADA

Analysis and Design of Algorithms

--

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

**Time Complexity** : O(logn)
**Space Complexity** : O(1), or O(logn) due to call Stack for recusrsion

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

**Time Complexity** : O(logn)
**Space Complexity** : O(1), or O(logn) due to call Stack for recusrsion

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

--- 

## 4. Fractional KnapSack Problem

### Problem :-

### Solution :-

--- 

## 5. Maximum Stack Space used in Quick Sort in Recursion

### Problem :-

### Solution :-

--- 

## 6. Activity Selection Problem

### Problem :-

### Solution :-

--- 

## 7. Iterative Quick Sort

### Problem :-

### Solution :-

---

## 8. Matrix Multiplication (Divide and Conquer)

### Problem :-

### Solution :-

--- 

## 9. Stressens Multiplication

### Problem :-

### Solution :-

--- 

## 10. Convex Hull Problem

### Problem :-

### Solution :-

---

## 11. Quick Hull

### Problem :-

### Solution :-

--- 

## 12. Single Source Shortest Path

### Problem :-

### Solution :-

---

## 13. Prims Algorithm

### Problem :-

### Solution :-

---

## 14. Kruskal Algorithm

### Problem :-

### Solution :-

---

## 15. MultiStage Graph Problem

### Problem :-

### Solution :-

---


## 16. Number of Stages in Graph

### Problem :-

### Solution :-

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

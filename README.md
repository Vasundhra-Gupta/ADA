# ADA

Analysis and Design of Algorithms

## 1. Find peak elements in a 1D array

### Problem :-

### Solution :-

----------
## 2. Find peak elements in a 2D array

### Problem :-

### Solution :-

----------

## 3. Magic Square Problem

### Problem :-

### Solution :-

## 4. Fractional KnapSack Problem

### Problem :-

### Solution :-

## 5. Maximum Stack Space used in Quick Sort in Recursion

### Problem :-

### Solution :-

## 6. Activity Selection Problem

### Problem :-

### Solution :-

## 7. Iterative Quick Sort

### Problem :-

### Solution :-

## 8. Matrix Multiplication (Divide and Conquer)

### Problem :-

### Solution :-

## 8. Stressens Multiplication

### Problem :-

### Solution :-

## 9. Convex Hull Problem

### Problem :-

### Solution :-

## 10. Quick Hull

### Problem :-

### Solution :-

## 11. Single Source Shortest Path

### Problem :-

### Solution :-

## 12. Prims Algorithm

### Problem :-

### Solution :-

## 13. Kruskal Algorithm

### Problem :-

### Solution :-

## 14. MultiStage Graph Problem

### Problem :-

### Solution :-

## 15. Number of Stages in Graph

### Problem :-

### Solution :-

## 16. All Pair Shortest Path

### Problem :-

### Solution :-


## 17. N Queen Problem

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

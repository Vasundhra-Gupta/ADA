#include <iostream>
using namespace std;

void generateMagicSquare(int** arr, int n){
    int mid = n/2;
    arr[0][mid] = 1;
    int i=0;
    int j=mid;
    int k=2;
    //row nahi hai;
    //column nahi hai;
    //hai but filled hai;
    //row column dono nahi hai;
    while(i>0 && j>0){
        i--;
        j--;
        if(!arr[i][j] && !i){
            arr[n][j] = k;
            k++;
        }else if(!arr[i][j] && !j){
            arr[i][n] = k;
            k++;
        }else if(!arr[i][j] && !j && !i){
            i+=2;
            j++;
            arr[i][n] = k;
            k++;
        }else if(arr[i][j]){
            i+=2;
            j++;
            arr[i][n] = k;
            k++;
        }
    }
}

int main(){
    int n;
    cout<<"Enter size of matrix "<<endl;
    cin>>n;
    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        int* arr = new int[n];
    }
    generateMagicSquare(arr,n-1);
    return 0;
}
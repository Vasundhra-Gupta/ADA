#include <iostream>
#include <vector>
#include "../headers/array2D.h"
using namespace std;

void multiply(vector<vector<int>> matrix1, vector<vector<int>> matrix2, vector<vector<int>> &result){
    int row1 = matrix1.size();
    int col1 = matrix1[0].size();
    int row2 = matrix2.size();
    int col2 = matrix2[0].size();
    if(col1!=row2) {
        cout<<"Not valid matrix to multiply\n";
        return;
    };
    result.assign(row1, vector<int>(col2, 0));

    for(int i=0; i<row1; i++){
        for(int j=0; j<col2; j++){
            for(int k=0; k<col1; k++){
                result[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }
}

int main(){
    int  row1, col1, row2, col2;
    cout<<"Enter row of matrix 1"<<endl;
    cin>>row1;
    cout<<"Enter col of matrix 1"<<endl;
    cin>>col1;
    cout<<"Enter row of matrix 2"<<endl;
    cin>>row2;
    cout<<"Enter col of matrix 2"<<endl;
    cin>>col2;
    vector<vector<int>> matrix1(row1, vector<int>(col1, 0)), matrix2(row2, vector<int>(col2, 0)), result;

    // matrix1 ={
    //     {2, 3, 1},
    //     {4, 9, 1},
    // };
    // matrix2 ={
    //     {1, 2},
    //     {2, 1},
    //     {1, 1}
    // };
    
    if (row1 <= 0 || col1 <= 0 || row2 <= 0 || col2 <= 0) {
        cout << "Matrix dimensions must be positive integers.\n";
        return 0;
    }

    if (col1 != row2) {
        cout << "Matrix multiplication is not possible with these dimensions.\n";
        return 0;
    }
    input2DArray(matrix1, row1, col1);
    input2DArray(matrix2, row2, col2);
    multiply(matrix1, matrix2, result);
    printArray(result);
    
    return 0;
}
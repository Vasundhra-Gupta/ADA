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
    vector<vector<int>> matrix1, matrix2, result(matrix1.size(), vector<int>(matrix2.size(), 0));

    // matrix1 ={
    //     {2, 3, 1},
    //     {4, 9, 1},
    // };
    // matrix2 ={
    //     {1, 2},
    //     {2, 1},
    //     {1, 1}
    // };
    
    inputSquaredArray(matrix1);
    inputSquaredArray(matrix2);
    multiply(matrix1, matrix2, result);
    printArray(result);
    
    return 0;
}
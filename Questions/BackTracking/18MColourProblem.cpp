#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isColourSame(vector<vector<int>> arr, vector<int> colour, int j, vector<int> x, int& k){ 
    if(k<colour.size()){
        cout<<"color of "<<j<<" is"<<x[j]<<endl;
        cout<<"color to assign"<<colour[k]<<endl;
        if(x[j]==colour[k]){
            k++;
            return true;
        }else{
            return false;
        }
    }
    return false;
}
void MColourProblem(vector<vector<int>> arr, vector<int> colour, vector<int> &x)
{
    int n= arr.size();
    for(int i=0; i<n; i++){
        bool isSame = false;
        int k=0;//colour to assign
        for(int j=0; j<n; j++){//j are neighbours
            if(arr[i][j]!=INT_MAX && arr[i][j]!=0){
                cout<<"entered neighbours of"<<i<<" is "<<j<<endl;
                isSame = isColourSame(arr, colour, j, x, k);
            }
        }
        cout<<"status of same "<<isSame<<endl;
        if(!isSame){
            x[i] = colour[k];
        }
    }
}
int main()
{
    vector<vector<int>> arr = {
        {0, 4, 1, INT_MAX, INT_MAX},
        {4, 0, 2, 5, INT_MAX},
        {1, 2, 0, 8, 10},
        {INT_MAX, 5, 8, 0, 3},
        {INT_MAX, INT_MAX, 10, 3, 0}
    };
    vector<int> colour = {4, 5, 7};
    vector<int> x(arr.size());
    MColourProblem(arr, colour, x);
    for(auto val: x){
        cout<<val<<"\t";
    }
    return 0;
}
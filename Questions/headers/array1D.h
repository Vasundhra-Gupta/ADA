#define ARRAY_H
#ifdef ARRAY_H
#include <iostream>
using namespace std;

void inputArray(int* arr, int n){
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}

void printArray(int* arr,int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

#endif
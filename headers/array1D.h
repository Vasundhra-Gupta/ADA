#define ARRAY_H
#ifdef ARRAY_H
#include <iostream>
#include <time.h>
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


void generateArray(int* arr, int n){
    srand(time(0));//seeding time means to change the seed i.e to make it generate diffrent set of numbers each time program runs, by default it is one, 
    for (int i=0; i<n; i++){
        arr[i] = 0 + rand()%n;
    }
}


#endif
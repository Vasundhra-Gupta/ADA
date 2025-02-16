#define ARRAY_H
#ifdef ARRAY_H
#include <iostream>
#include <vector>
#include <algorithm>
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
void printArray(vector<int> arr,int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}


void generateArray(vector<int> &arr, int n){
    // srand(time(0));//seeding time means to change the seed i.e to make it generate diffrent set of numbers each time program runs, by default it is one, 
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        numbers[i] = i;
    }
    random_shuffle(numbers.begin(), numbers.end());
    for (int i=0; i<n; i++){
        arr[i] = numbers[i];
    }
}

void generateArray(int* arr, int n){
    // srand(time(0));//seeding time means to change the seed i.e to make it generate diffrent set of numbers each time program runs, by default it is one, 
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        numbers[i] = i;
    }
    random_shuffle(numbers.begin(), numbers.end());
    for (int i=0; i<n; i++){
        arr[i] = numbers[i];
    }
}


#endif
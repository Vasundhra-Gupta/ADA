#include <iostream>
using namespace std;
int horner(int* &a, int i, int n, int &x){
    if(i==n-1){
        return a[i];
    }else{
        return a[i]+ x* horner(a, i+1, n, x);
    }
}
int main(){
    // int a[]= {1, 2, 2, 1};
    int* a = new int[4]{1, 2, 2, 1};
    int x=2;
    int result = horner(a, 0, 4, x);
    cout<<"result: "<<result<<endl;
    return 0;
}
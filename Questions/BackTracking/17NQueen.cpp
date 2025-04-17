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
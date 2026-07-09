#include<iostream>
using namespace std;

// ifstream cin("euclid2.in");
// ofstream cout("euclid2.out");

int euclid(int a, int b){
    if(b == 0){
        return a;
    }
    int c = a%b;
    return euclid(b, c);
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int a,b;
        cin>>a>>b;
        if(a<b){
            swap(a, b);
        }
        cout<<euclid(a, b);
    }
    return 0;
}

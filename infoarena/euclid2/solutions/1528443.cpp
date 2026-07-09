#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");
int euclid(int a, int b){
    int r;
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main(){
    int n,a,b;
    f>>n;
    for(int i=0;i<n;i++){
        f>>a>>b;
        o<<euclid(a,b)<<endl;
    }
    return 0;
}

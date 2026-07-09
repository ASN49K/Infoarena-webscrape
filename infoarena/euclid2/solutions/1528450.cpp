#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");
int euclid(int a, int b){
    if (!b) return a;
    return euclid(b,a%b);
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

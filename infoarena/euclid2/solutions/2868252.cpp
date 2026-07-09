#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a,int b){
    while(b){
        int r = a%b;
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
        g<<cmmdc(a,b)<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int lcm(int a, int b){
    int r;
    while(b>0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main(){
    int n, a, b;
    fin>>n;
    for(int i=0; i<n; i++){
        fin>>a>>b;
        fout<<lcm(a, b)<<'\n';
    }
    return 0;
}
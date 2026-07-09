#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b;

int cmmdc(int a, int b){
    int r;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>a>>b;
        fout<<cmmdc(a, b)<<endl;
    }
    return 0;
}

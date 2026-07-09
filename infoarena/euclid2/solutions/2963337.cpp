#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("	euclid2.out");

int cmmdc(int a, int b){
    
    return b == 0 ? a : cmmdc(b, a%b);
}

int main(){ 
    
    //freopen ("file.in", "r", stdin);
    
    int n, x, y;

    fin>>n;
    while(n){
        fin>>x>>y;
        fout<<cmmdc(x, y)<<'\n';
        n--;
    }
   
    return 0;
}
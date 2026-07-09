#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long gcd(long a,long b){
    if(b != 0){
        return gcd(b,a%b);
    }
    return a;
}

int main(){
    long n,a,b,i,c;
    fin>>n;
    for(i = 1; i <= n; i++){
        fin>>a>>b;
        fout<<gcd(a,b)<<endl;
    }
    return 0;
}

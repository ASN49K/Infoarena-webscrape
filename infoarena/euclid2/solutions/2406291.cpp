#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
    unsigned long long n,a,b,i,c;
    cin>>n;
    for(i = 1; i <= n; i++){
        cin>>a>>b;
        cout<<__gcd(a,b)<<endl;
    }
    return 0;
}

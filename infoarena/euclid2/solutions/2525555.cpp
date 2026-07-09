#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    long long  a, b, rest, t, i;
    cin>>t;
    for(i=1;i<=t;i++)
    {cin >> a >> b;
    while(b)
    {
        rest=a%b;
        a=b;
        b=rest;
    }
    cout<<a<<"\n";}
    return 0;
}

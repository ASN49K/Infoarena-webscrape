#include <bits/stdc++.h>
using namespace std;
int main()
{
    int b,a,t;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    for(int i=1;i<=t;i++)
        in>>a>>b,out<<__gcd(a,b)<<"\n";
    return 0;
}

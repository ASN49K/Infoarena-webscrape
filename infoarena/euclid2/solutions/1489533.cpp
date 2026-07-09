#include<bits/stdc++.h>

using namespace std;
int t()
{
    ifstream i("euclid2.in");
    ofstream o("euclid2.out");
    int t,x,y;
    i>>t;
    while (t--)
    {
        i>>x>>y;
        o<<__gcd(x,y)<<"\n";
    }
    return 0;
}

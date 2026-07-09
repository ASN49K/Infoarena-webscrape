#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n,i,a,b;
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<__gcd(a,b)<<endl;
    }
    return 0;
}

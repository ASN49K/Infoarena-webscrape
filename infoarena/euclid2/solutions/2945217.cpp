#include <bits/stdc++.h>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main()
{
    int a,b;
    cin>>a>>b;
    while(b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    cout<<a;
    return 0;
}
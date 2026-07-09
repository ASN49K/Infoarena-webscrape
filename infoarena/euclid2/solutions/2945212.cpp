#include <bits/stdc++.h>

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

using namespace std;

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
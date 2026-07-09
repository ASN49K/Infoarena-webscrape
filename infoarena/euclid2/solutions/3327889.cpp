#include <bits/stdc++.h>
#define cin fin
#define cout fout
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int n, x, y;

int cmmdc(int a, int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}


int main()
{
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        cout<<cmmdc(x,y)<<'\n';
    }
}

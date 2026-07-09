#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a,int b)
{
    while(a!=b)
        if(a>b)a-=b;
    else b-=a;
    return a;
}

int main()
{
    int n;
    in>>n;

    for(int i=1;i<=n;i++)
    {
        int a,b;
        in>>a>>b;
        out<<euclid(a,b)<<'\n';
    }
    return 0;
}

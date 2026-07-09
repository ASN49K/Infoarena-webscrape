#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a,int b)
{
    if(b==0)
        return a;
    else
        return euclid(b,a%b);
}
int main()
{
    int t;
    fin>>t;
    while(t--)
    {
        int x,y;
        fin>>x>>y;
        fout<<euclid(x,y)<<'\n';
    }
}

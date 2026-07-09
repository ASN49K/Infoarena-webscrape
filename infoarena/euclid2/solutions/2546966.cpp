#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

const int lim=100001;
int n;
long long x,y;


int main()
{
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>x>>y;
        long long r=x%y;
        while(r)
        {
            x=y;
            y=r;
            r=x%y;
        }
        out<<y;
        out<<'\n';
    }
}

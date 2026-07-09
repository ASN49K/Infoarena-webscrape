#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int x ,y ,i ,r ;

int main()
{
    int t;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>x>>y;
        while(y)
        {
            r=x%y;
            x=y;
            y=r;
        }
        fout<<x<<'\n';
    }
    return 0;
}

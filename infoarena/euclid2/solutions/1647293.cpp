#include <fstream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t,x,y;

int cmmdc(int x, int y)
{
    int z=1;
    while( z != 0 )
    {
        z = x % y;
        x = y;
        y = z;
    }
    return x;
}

int main()
{
    fin>>t;
    while(t--)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<'\n';
    }

return 0;
}

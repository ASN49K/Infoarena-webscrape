#include <bits/stdc++.h>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n,i,j,t,x,y;
int main()
{
    fin>>t;
    while(t--)
    {
        fin>>n;
        for(i=1;i<=n;i++)
        {
            fin>>x;
            y=(y^x);
        }
        if(y==0)
            fout<<"NU\n";
        else fout<<"DA\n";
        y=0;
    }
    return 0;
}

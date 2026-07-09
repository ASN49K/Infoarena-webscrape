#include <bits/stdc++.h>
using namespace std;
ifstream fin ("nim.in");
ofstream fout ("nim.out");
int viz[100001], b, c, i, k, n, j, maxi, x, y, t, s;



int main()
{
    fin>>t;
    for(j=1; j<=t; j++)
    {
        fin>>n;
        for(i=1; i<=n; i++)
            {
                fin>>x;
                s=s^x;
            }
        if(s == 0)
            fout<<"NU"<<endl;
        else fout<<"DA"<<endl;
        s=0;
    }

}

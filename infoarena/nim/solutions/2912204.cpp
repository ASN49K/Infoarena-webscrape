#include <bits/stdc++.h>
using namespace std;
int t,n,x,i,r,A[10001];
ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    fin >> t ;
    while (t--)
    {
        fin >> n ;
        for (i=1;i<=n;i++)
        {
            fin >> A[i];
        }
        r=0;
        for (i=1;i<=n;i++)
        {
            r=r^A[i];
        }
        if (r==0)
        {
            fout<<"NU\n";
        }
        else fout<<"DA\n";
    }
    return 0;
}
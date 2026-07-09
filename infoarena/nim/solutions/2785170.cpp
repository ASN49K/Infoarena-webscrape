#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    int t,n,x,s=0,i,j,nrnn;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>n;
        nrnn=0;
        s=0;
        for(j=1;j<=n;j++)
        {
            fin>>x;
            if(x==0)
                nrnn++;
            s=s^x;
        }
        if(n==1)
        {
            if(x==0)
            {
                fout<<"NU";
            }
            else fout<<"DA";
        }
        else if(nrnn==n-1)
        {
            fout<<"DA";
        }
        else
        {
            if(s)
            {
                fout<<"DA";
            }
            else
            {
                fout<<"NU";
            }
        }

        fout<<'\n';
    }

    return 0;
}

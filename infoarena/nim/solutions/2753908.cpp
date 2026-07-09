#include<bits/stdc++.h>
using namespace std;
ifstream fin ("nim.in");
ofstream fout("nim.out");


int main ()
{
    int n,i,x,t;
    fin>>t;
    while (t--)
    {
        fin>>n;
        int s=0;
        for (i=1;i<=n;i++)
        {
            fin>>x;
            s=s^x;
        }
        if (s!=0)
            fout<<"DA";
        else    fout<<"NU";
        fout<<'\n';
    }
    return 0;
}

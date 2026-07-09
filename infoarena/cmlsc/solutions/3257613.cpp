#include <bits/stdc++.h>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int a[1026],b[1026],n,m,fr[258],nr;
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>a[i];
        fr[a[i]]++;
    }
    for(int i=1;i<=m;i++)
    {
        fin>>b[i];
        fr[b[i]]++;
    }
    for(int i=1;i<=256;i++)
    {
        if(fr[i]==2)
            nr++;
    }
    fout<<nr<<"\n";
    for(int i=1;i<=256;i++)
    {
        if(fr[i]==2)
            fout<<i<<" ";
    }
    return 0;
}

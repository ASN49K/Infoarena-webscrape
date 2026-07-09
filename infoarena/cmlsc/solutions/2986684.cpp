#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream fin("fisier.in");
ofstream fout("fisier.out");

int m,n,maxx;
int a[1025],b[1025],vf[257];

void recursie(int i, int maxx) {
    if(i==-1)
        fout<<maxx<<"\n";
    else if(vf[i]==2)
    {
        recursie(i-1,maxx+1);
        fout<<i<<" ";
    }
    else
    {
        recursie(i-1,maxx);
    }
}

int main()
{
    int i;
    fin>>m>>n;
    for(i=0;i<m;i++)
        fin>>a[i];
    for(i=0;i<n;i++)
        fin>>b[i];
    if(m<=n)
    {
        for(i=0;i<m;i++)
        {
            vf[a[i]]++;
            vf[b[i]]++;
        }
        for(i=m;i<n;i++)
            vf[b[i]]++;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            vf[a[i]]++;
            vf[b[i]]++;
        }
        for(i=n;i<m;i++)
            vf[a[i]]++;
    }
    recursie(256,0);
    fin.close();
    fout.close();
    return 0;
}

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,a[1025][1025];
vector<int>v,w;

void citire()
{
    in>>n>>m;
    v=vector<int>(n);
    for(int i=1;i<=n;i++)
    {
        int x;
        in>>x;
        v[i]=x;
    }
    w=vector<int>(m);
    for(int i=1;i<=m;i++)
    {
        int x;
        in>>x;
        w[i]=x;
    }
}

void rezolva()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i]==w[j]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    }
}

void afisare()
{
    vector<int> sir;
    int i=n,j=m;
    while(i and j)
    {
        if(v[i]==w[j])
        {
            sir.push_back(v[i]);
            i--;
            j--;
        }
        else if(a[i-1][j]<a[i][j-1]) j--;
        else i--;
    }
    out<<sir.size()<<'\n';
    for(int i=sir.size()-1;i>=0;i--)
        out<<sir[i]<<" ";
}

int main()
{
    citire();
    rezolva();
    afisare();
    return 0;
}

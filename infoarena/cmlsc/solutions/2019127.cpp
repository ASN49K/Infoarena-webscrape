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
    for(int i=1;i<=n;i++)
    {
        int x;
        in>>x;
        v.push_back(x);
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        in>>x;
        w.push_back(x);
    }
}

void rezolva()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i]==w[j]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    }
}

void afisare()
{
    vector<int> sir;
    int i=n-1,j=m-1;
    for(i=n , j=m;i;)
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

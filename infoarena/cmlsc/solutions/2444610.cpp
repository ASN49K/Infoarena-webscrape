#include<bits/stdc++.h>
#define maxn 1030
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,v1[maxn],v2[maxn],d[maxn][maxn];
vector < int > sir;

void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>v1[i];
    for(int i=1;i<=m;i++)
        fin>>v2[i];
}

void dinamica()
{
    int maxim=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            if(d[i][j]>maxim)
                maxim=d[i][j];
        }
    }
    fout<<maxim<<"\n";
    int i=n,j=m;
    while(i>=1 && j>=1)
    {
        if(v1[i]==v2[j])
        {
            sir.push_back(v1[i]);
            i--,j--;
        }
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;
    }
    for(int i=sir.size()-1;i>=0;i--)
        fout<<sir[i]<<" ";

}

int main()
{
    citire();
    dinamica();
    return 0;
}

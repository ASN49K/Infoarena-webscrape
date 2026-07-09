#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;
#define DIM 1025
int nr_n,nr_m,numar,n_nou,m_nou,consecutive=0,maxim;
vector<int> v1,v2,v3;
unordered_map<int,pair<int,int>> exista;
int matriceSir[DIM][DIM];
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>nr_n>>nr_m;
    for(int i=0;i<nr_n;i++)
    {
        fin>>numar;
        v1.push_back(numar);
        exista[v1[i]].first=1;
    }
    for(int i=0;i<nr_m;i++)
    {
        fin>>numar;
        v2.push_back(numar);
        exista[v2[i]].second=1;
    }
    for(int i=0;i<max(nr_n,nr_m);i++)
    {
        if(i<nr_n)
        {
            if(exista[v1[i]].first==1 && exista[v1[i]].second==1)
            {
                v1[n_nou++]=v1[i];
            }
        }
        if(i<nr_m)
        {
            if(exista[v2[i]].first==1 && exista[v2[i]].second==1)
            {
                v2[m_nou++]=v2[i];
            }
        }
    }
    for(int i=0;i<=n_nou;i++)
    {
        for(int j=0;j<=m_nou;j++)
        {
            if(i==0 || j==0)
            {
                matriceSir[i][j]=0;
            }
            else if(v1[i-1]==v2[j-1])
            {
                matriceSir[i][j]=matriceSir[i-1][j-1]+1;
                v3.push_back(v1[i-1]);
                maxim=max(maxim,matriceSir[i][j]);
            }
            else
            {
                matriceSir[i][j]=0;
            }
        }
    }
    fout<<maxim<<'\n';
    for(int i=0;i<maxim;i++)
    {
        fout<<v3[i]<<" ";
    }
}
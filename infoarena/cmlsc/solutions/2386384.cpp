#include <bits/stdc++.h>
int n,m;
int s[1024],t[1024];
int mat[1024][2];
int na;
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
void P(int);
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++) fin>>s[i];
    for(int j=1;j<=m;j++) fin>>t[j];
    P(m);
    for(int i=1;i<=n;i++)
    {
        if(mat[i][0]==na)
        {
            int j=i;
            fout<<na<<'\n';
            while(j!=0)
            {
                fout<<s[j]<<' ';
                j=mat[j][1];
            }
            i=n+1;
            return 0;
        }
    }
    return 0;
}
void P(int k)
{
    for(int i=1;i<=n;i++)
    {
        if(t[k]==s[i])
        {
            int nax=0,l=0;
            for(int j=i+1;j<=n;j++)
            {
                if(mat[j][0]>=nax) nax=mat[j][0],l=j;
            }
            if(mat[i][0]<=nax) mat[i][0]=nax+1,mat[i][1]=l;
            if(na<mat[i][0]) na=mat[i][0];
        }
    }
    if(k>1) P(k-1);
}

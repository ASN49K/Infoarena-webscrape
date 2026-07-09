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
    if(n<m) {swap(n,m);
    for(int i=1;i<=m;i++) fin>>t[i];
    for(int j=1;j<=n;j++) fin>>s[j];}
    else
    {for(int i=1;i<=n;i++) fin>>s[i];
    for(int i=1;i<=m;i++) fin>>t[i];}
    P(m);
    //for(int i=1;i<=n;i++) fout<<mat[i][0]<<' '<<mat[i][1]<<'\n';
    fout<<na<<'\n';
    for(int i=1;i<=n && na;i++)
    {
        if(mat[i][0]==na)
        {
            int j=i;
            int x=0;
            fout<<s[i]<<' ';
            na--;
            /*while(j!=0)
            {
                x++;
                fout<<s[j]<<' '<<j<<'\n';
                j=mat[j][1];
            }
            i=n+1;
            return 0;*/
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
            if(nax==0) mat[i][0]=1;
            else if(mat[i][0]<=nax) mat[i][0]=nax+1,mat[i][1]=l;
            if(na<mat[i][0]) na=mat[i][0];
        }
    }
    if(k>1) P(k-1);
}

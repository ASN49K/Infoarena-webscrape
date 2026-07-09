#include <iostream>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
ifstream fin("muzeu.in");
ofstream fout("muzeu.out");
int i,j,n,mat[251][251],dx[]= {-1,0,1,0},dy[]= {0,1,0,-1},viz[251][251],a=0,b=0;
char ch;
struct punct
{
    int l,c;
}v[251];
queue <punct> q;
int lee(int k)
{
    while(!q.empty())
    {
        int l=q.front().l;
        int c=q.front().c;
        for(i=0; i<4; i++)
        {
            int lv=l+dx[i];
            int cv=c+dy[i];
            if(lv>=1&&lv<=n&&cv>=1&&cv<=n&&mat[lv][cv]==0&&viz[lv][cv]==0)
            {
                q.push({lv,cv});
                viz[lv][cv]=1;
                mat[lv][cv]=mat[l][c]+1;
            }
        }
        q.pop();
    }
}
int main()
{
    fin>>n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            fin>>ch;
            if(ch=='#')
                mat[i][j]=-2;
            else if(ch=='P')
            {
                a++;
                v[a].l=i;
                v[a].c=j;
                q.push({i,j});
                mat[i][j]=0;
            }
            else
            {
                mat[i][j]=0;
            }
        }
    }
    /*for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<endl;*/
    lee(2);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(mat[i][j]==0)
                mat[i][j]=-1;
        }
    }
    for(i=1; i<=a; i++)
    {
        mat[v[i].l][v[i].c]=0;
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            fout<<mat[i][j]<<" ";
        }
        fout<<"\n";
    }
    return 0;
}

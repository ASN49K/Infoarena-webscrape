#include <bits/stdc++.h>

using namespace std;

int a[1025][1025];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int i,j,n,m,x[1025],y[1025];
    stack<int> s;
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>x[i];
    }
    for(i=1;i<=m;i++)
    {
        fin>>y[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(x[i]==y[j])
            {
                a[i][j]=a[i-1][j-1]+1;
            }else
            {
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    i=n;
    j=m;
    fout<<a[i][j]<<endl;
    while(i>0&&j>0)
    {
        if(x[i]==y[j])
        {
            s.push(x[i]);
            i--;
            j--;
        }else if(a[i-1][j]<a[i][j-1])
        {
            j--;
        }else
        {
            i--;
        }
    }
    while(!s.empty())
    {
        fout<<s.top()<<" ";
        s.pop();
    }
}
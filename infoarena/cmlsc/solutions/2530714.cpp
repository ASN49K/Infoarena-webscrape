#include <bits/stdc++.h>

using namespace std;

ifstream in;
ofstream out;

int v[1030],v1[1030];

void dynamic(int a[][1030],int i,int j)
{
    if(v[j]==v1[i])
        a[i][j]=a[i-1][j-1]+1;
    else
        a[i][j]=max(a[i][j-1], a[i-1][j]);
}


int n,m;
int a[1030][1030];
int main()
{
    in.open("cmlsc.in");
    out.open("cmlsc.out");
    
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>v[i];
    for(int i=1;i<=m;i++)
        in>>v1[i];
    /*if(n<m)
    {
        int max1=max(n, m);
        swap(n, m);
        for(int i=1;i<=max1;i++)
            swap(v[i], v1[i]);
    }*/
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dynamic(a, i, j);
        }
    }
    /*for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            out<<a[i][j]<<" ";
        }
        out<<endl;
    }*/
    out<<a[m][n]<<endl;
    int i=m,j=n;
    stack<int> z;
    while(i and j)
    {
        if(a[i][j]!=a[i-1][j] and a[i][j]!=a[i][j-1])
        {
            //out<<v[j]<<" ";
            z.push(v[j]);
            i--;
            j--;
            
            
        }
        else
        {
            if(a[i][j]==a[i-1][j])
                i--;
            else
                j--;
        }
    }
    //out<<z.size()<<endl;
    while(!z.empty())
    {
        out<<z.top()<<" ";
        z.pop();
    }
}

#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int max(int a,int b)
{
    if(a>b) return a;
        else return b;
}

int a[1026],b[1026],m,n,d[1026][1026],v[1026];

int main()
{
    int k,i,j,nr=0,c=0;
    in>>m>>n;
    for(i=1;i<=m;i++)
        in>>a[i];
    for(j=1;j<=n;j++)
        in>>b[j];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            in>>d[i][j];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);

    i=m;
    j=n;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            v[++nr]=a[i];
            i--;
            j--;
        }
        else
            if(d[i-1][j]>=d[i][j-1])
                i--;
            else
                j--;
    }
    for(i=1;i<=nr;i++)
        c++;
    out<<c;
    out<<endl;
    for(i=nr;i>=1;i--)
        out<<v[i]<<" ";
    return 0;
}

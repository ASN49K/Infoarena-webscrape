#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,a[1024],b[1024],c[1024];

int max(int x,int y)
{
    if(x>y)
        return x;
    return y;
}

int LCS(int i,int j)
{
    if(i<0||j<0)
        return 0;
    if(a[i]==b[j])
    {
        int x;
        x=LCS(i-1,j-1)+1;
        c[i]=x;
        return x;
    }
    if(a[i]!=b[j])
    {
        return max(LCS(i-1,j),LCS(i,j-1));
    }
}
void print(int x,int j)
{
    if(j<m)
    {
        if(c[j]==x)
        {
            out<<a[j]<<' ';
            print(x+1,j+1);
        }
        else
        print(x,j+1);
    }
}

int main()
{

    in>>m>>n;
    for(int i=0; i<m; i++)
    {
        in>>a[i];
    }
    for(int j=0; j<n; j++)
    {
        in>>b[j];
    }
    int x=LCS(m-1,n-1);
    out<<x<<'\n';
    for(int i=0;i<m;i++)
        cout<<c[i]<<' ';
    print(1,0);
    return 0;
}

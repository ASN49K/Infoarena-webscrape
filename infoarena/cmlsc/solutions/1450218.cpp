#include <fstream>
#include <iostream>
using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int maxim(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

int main()
{
    int m,n,a[1024],b[1024],i,j,d[1024][1024],bst,sir[1024];
    in>>m>>n;
    for(i=1;i<=m;i++)
        in>>a[i];
    for(j=1;j<=n;j++)
        in>>b[j];
    
    
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);
    for(i=m,j=n;i;)
        if(a[i]==b[j])
            sir[++bst]=a[i],--i,--j;
        else if (d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;
    
    
    out<<bst<<endl;
    for(i=bst;i;--i)
        out<<sir[i]<<" ";
    
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
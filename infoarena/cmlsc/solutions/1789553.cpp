#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,i,j,y,a[1025],k,ok=0,m,x,b[1025],ma=0,v[1025][1025],c[1025];
int main()
{
    in>>n>>m;
    for(i=1;i<=n;i++)in>>a[i];
    for(i=1;i<=m;i++)in>>b[i];
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(b[i]==a[j])
                v[i][j]=v[i-1][j-1]+1;
            else
            {
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
            if(v[i][j]>ma)ma=v[i][j];
        }
    }
    i=m;j=n;ok=1;
    while(i!=0)
    {
        if(b[i]==a[j])
        {
            k++;
            c[k]=b[i];
            i--; j--;
        }
        else if(v[i][j-1]>v[i-1][j])
        {
            j--;
        }
        else i--;
    }
    out<<ma<<endl;
    for(i=k;i>=1;i--)out<<c[i]<<" ";
    return 0;
}

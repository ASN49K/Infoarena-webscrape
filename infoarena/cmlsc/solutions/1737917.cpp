#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int a[1025],b[1025],r,i,t,m[1026][1026],x[1026],n,j;
int main()
{
    f>>t>>n;
    for(i=1; i<=t; i++)
        f>>a[i];
    for(i=1; i<=n; i++)
        f>>b[i];
    for(i=1; i<=t; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i]==b[j])
                m[i][j]=m[i-1][j-1]+1;
            else if( m[i-1][j] > m[i][j-1])
                m[i][j]=m[i-1][j];
            else
                m[i][j]=m[i][j-1];
        }
    }
    i=t;
    j=n;
    while(i!=0)
        if(a[i]==b[j])
        {
            x[r++]=a[i];
            i--;
            j--;
        }
        else if(m[i-1][j]<m[i][j-1])
            j--;
        else i--;
    g<<r<<'\n';
    for(i=r-1; i>=0; i--)
        g<<x[i]<<" ";
    return 0;
}

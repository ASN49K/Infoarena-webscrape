#include <iostream>
#include <fstream>
using namespace std;
unsigned short m,n,a[1025],b[1025],x[1025][1025];
int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    register unsigned short i,j;
    in>>m>>n;
    for(i=0;i<=m;i++) x[0][i]=0;
    for(i=1;i<=m;i++) in >> a[i];
    for(i=1;i<=n;i++) in >> b[i];
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            if(a[i]==b[j]) x[i][j]=x[i-1][j-1]+1;
            else x[i][j]=max(x[i-1][j],x[i][j-1]);
    }
    i=m;j=n;
    out << x[i][j] << '\n';
    while(i>0 && j>0)
    {
        if(a[i]==b[j]) {out<<a[i]<<' ';i--;j--;}
        while(x[i][j]==x[i][j-1]) j--;
        if(a[i]==b[j]) {out<<a[i]<<' ';i--;j--;}
        else i--;
    }
    return 0;
}

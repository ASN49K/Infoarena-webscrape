#include <bits/stdc++.h>
#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int m,n,x,i,j,d[1025][1025],a[1025],b[1025],cnt=0,c[1025];
int main()
{
    fin>>m>>n;
    for(i=1;i<=m;i++)

    fin>>a[i];


    for(i=1;i<=n;i++)

    fin>>b[i];



    for(i=1;i<m;i++)

    for(j=1;j<n;j++)


if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
else    d[i][j]=max(d[i-1][j],d[i][j-1]);

    i=m;j=n;
    while(i!=0)
    {
    if(a[i]==b[j]) {
    c[cnt++]=a[i];
    i--;j--;

    }
    else if(d[i-1][j]<d[i][j-1]) j--;
    else i--;

    }

    fout<<cnt<<endl;
    for(i=cnt-1;i>=0;i--) fout<<c[i]<<' ';





    return 0;
}

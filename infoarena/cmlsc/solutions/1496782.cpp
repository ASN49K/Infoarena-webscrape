#include <iostream>
#include <fstream>
#define nmax 1025
using namespace std;
int n,m,a[nmax],b[nmax],c[nmax][nmax];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{int i,j;
    fin>>n>>m;
    for(i=0;i<n;i++)
        fin>>a[i];
    for(j=0;j<m;j++)
        fin>>b[j];


    for(i=n-1;i>=0;i--)
        for(j=m-1;j>=0;j--)
        if(a[i]==b[j])c[i][j]=1+c[i+1][j+1];
            else c[i][j]=max(c[i+1][j],c[i][j+1]);

    fout<<c[0][0]<<endl;
    i=j=0;
    for(int k=c[0][0];k>0;k--)
    {
        while(c[i+1][j]==k)i++;
        while(c[i][j+1]==k)j++;
        fout<<a[i]<<' ';
       if(c[i+1][j]>c[i][j+1])i++;else j++;
    }
}

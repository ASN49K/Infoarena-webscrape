#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
    int a[1025],b[1025],c[1025][1025],n,m,r[1025],ct;


int main()
{
    vector<int>G;
    fin>>m>>n;
    for(int i=1;i<=m;i++)fin>>a[i];
    for(int j=1;j<=n;j++)fin>>b[j];

    for(int i=0;i<=m;i++)c[i][0]=0;
    for(int j=0;j<=n;j++)c[0][j]=0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j]){c[i][j]=c[i-1][j-1]+1;}
            else c[i][j]=max(c[i-1][j],c[j][i-1]);
        }
    }
    fout<<c[m][n]<<'\n';
    int i=m,j=n;
    while(i>=1&&j>=1)
    {if(a[i]==b[j]){ct++;r[ct]=a[i];i--;j--;}
         else if(c[i][j-1]>c[i-1][j])j--;
         else i--;
    }
    for(int i=ct;i>=1;i--)
        fout<<r[i]<<' ';
}

#include <iostream>
#include<fstream>
#define NMAX 1025
using namespace std;ifstream fin("cmlsc.in");ofstream fout("cmlsc.out");
int n,m,A[NMAX],B[NMAX],i,j,v[NMAX][NMAX],rez[NMAX],cnt;
int main()
{fin>>n>>m;for(i=1;i<=n;i++)fin>>A[i];for(i=1;i<=m;i++)fin>>B[i];
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)
    {
        if(A[i]==B[j])v[i][j]=v[i-1][j-1]+1;
        else v[i][j]=max(v[i-1][j],v[i][j-1]);
    }while(n&&m){
    if(A[n]==B[m]){rez[++cnt]=A[n];n--;m--;}
    else if(v[n-1][m]<v[n][m-1])m--;
    else n--;
    }fout<<cnt<<'\n';for(i=cnt;i>0;i--)fout<<rez[i]<<' ';
    return 0;
}

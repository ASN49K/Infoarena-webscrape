#include <iostream>
#include <fstream>
using namespace std;

ifstream inf("cmlsc.in");
ofstream oinf("cmlsc.out");

int main()
{
    int n,m;
    inf>>n>>m;
    int a[n+1],b[m+1],x[n+1],sol=0,c[n+1][m+1];
    for(int i=1;i<=n; i++) {inf>>a[i];c[i][0]=0;}
    for(int i=1;i<=m; i++) {inf>>b[i];c[0][i]=0;}
    c[0][0]=0;
    for(int i=1;i<=n; i++)
        for(int j=1;j<=m; j++){
            if(a[i]==b[j])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]= max(c[i-1][j],c[i][j-1]);
        }
    for(int i=n;i;)
        for(int j=m;j;){
            if(a[i]==b[j])
                x[++sol]=a[i];
            else if(c[i-1][j]>c[i][j-1])
                i--;
            else
                j--;
        }
    oinf<<c[n][m]<<"\n";
    for(int i=1;i<=c[n][m];i++)
        oinf<<x[i]<<" ";
    return 0;
}

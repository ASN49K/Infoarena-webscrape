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
    for(int i=1;i<=n; i++) {inf>>a[i];c[0][i]=0;}
    for(int i=1;i<=m; i++) {inf>>b[i];c[i][0]=0;}
    c[0][0]=0;
    for(int i=1;i<=n; i++)
        for(int j=1;j<=m; j++){
            if(a[i]==b[j])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]= max(c[i-1][j],c[i][j-1]);
        }
   for(int i=n;i>0;)
        for(int j=m;j>0;){
            if(a[i]==b[j])
                {x[++sol]=a[i];--j; --i;}
            else if(c[i-1][j]>c[i][j-1])
                --i;
            else
                --j;
       }
    oinf<<sol<<"\n";
    for(int i=sol;i>=1;i--)
        oinf<<x[i]<<" ";
    return 0;
}

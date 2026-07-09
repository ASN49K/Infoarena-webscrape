#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
ifstream be("cmlsc.in");
ofstream ki("cmlsc.out");
int a[1024][1024];

int main()
{
   int n,m;
    be>>n>>m;
    vector<int>a1(n+1);
    vector<int>b(m+1);
    vector<int>c(n+m);
    for(int i=0;i<n;i++)
        be>>a1[i];
    for(int j=0;j<m;j++)
        be>>b[j];
    int k=0;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;j++)
            if(a1[j-1]==b[i-1]){
                    a[i][j]=a[i-1][j-1]+1;
                    k++;
                    c[k]=a1[j-1];
            }
            else if(a[i-1][j]>a[i][j-1])a[i][j]=a[i-1][j];
            else a[i][j]=a[i][j-1];
    }
   ki<<a[m][n]<<'\n';
   for(int i=1;i<=k;++i)
    ki<<c[i]<<" ";

    return 0;
}

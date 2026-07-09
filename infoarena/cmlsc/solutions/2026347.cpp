#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n,m,i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i]==b[j])
          x[i][j]=x[i-1][j-1]+1;
        else
            x[i][j]=max(x[i-1][j],x[i][j-1]);
    fout<<
    return 0;
}

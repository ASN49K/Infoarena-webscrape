#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

long long r[1030][1030],c;
int n,m,a[1030],b[1030],sol[1030];

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j])
                r[i][j]=1+r[i-1][j-1];
            else r[i][j]=(r[i-1][j]>r[i][j-1]?r[i-1][j]:r[i][j-1]);
        }
    }
    c=r[n][m];
    g<<c<<"\n";
    int i=n,j=m;
    while(c){
        if(a[i]==b[j]){
            sol[c--]=a[i];
            i--;j--;
        }
        else{
            if(r[i-1][j]>=r[i][j-1]) i--;
            else j--;
        }
    }
    for(int i=1;i<=r[n][m];i++)
        g<<sol[i]<<" ";

}

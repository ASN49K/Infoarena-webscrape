#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

short int v1[1025],v2[1025],n,m,slc[1025][1025],i,j,d[1025],k;

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++){
        f>>v1[i];
    }
    for(j=1;j<=m;j++)
        f>>v2[j];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(v1[i]==v2[j])
                slc[i][j]=1+slc[i-1][j-1];
            else{
                slc[i][j]=max(slc[i][j-1],slc[i-1][j]);
            }
        }
    }
    g<<slc[n][m]<<'\n';
    for(k=0, i=n, j=m;slc[i][j];){
        if(v1[i]==v2[j]){
            d[k++]=v1[i];
            i--;j--;
        }
        else{
            if(slc[i][j]==slc[i-1][j])
                i--;
            else
                j--;
        }
    }
    for(j=k-1;j>=0;j--) g<<d[j]<<" ";
    return 0;
}

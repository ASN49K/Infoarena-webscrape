#include <iostream>
#include <fstream>

using namespace std;

int main()
{   ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");
    int i, j, m, n, k=0;
    fin>>m>>n;
    int lmax[m+1][n+1], A[m+1], B[n+1]; k=m; if(n<m) k=n; int C[k+1];
    k=0;
    for(i=1; i<=m; i++){ fin>>A[i]; lmax[i][0]=0;}
    for(i=1; i<=n; i++){ fin>>B[i]; lmax[0][i]=0;}
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++){
            if(A[i]==B[j]){ lmax[i][j]=lmax[i-1][j-1]+1; C[++k]=A[i];}
            else lmax[i][j]=max(lmax[i-1][j], lmax[i][j-1]);}
    fout<<lmax[m][n]<<"\n";
    for(i=1; i<=k; i++) fout<<C[i]<<" ";
    fin.close(); fout.close();
    return 0;}



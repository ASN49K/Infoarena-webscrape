#include <iostream>
#include <fstream>
using namespace std;

#define nmax 1025
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,i,j,nr=0;
int A[nmax],B[nmax],C[nmax];
int DP[nmax][nmax];

void cmlsc(){
    
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (A[i]==B[j])
                DP[i][j]=DP[i-1][j-1]+1;
            else
                DP[i][j]=max(DP[i-1][j], DP[i][j-1]);
    
    out << DP[n][m] << "\n";
    
    i=n;
    j=m;
    
    while (DP[i][j]!=0)
        if (DP[i][j-1]==DP[i][j]) j--;
        else if (DP[i-1][j]==DP[i][j]) i--;
        else {
            nr++;
            C[nr]=A[i];
            i--, j--;
        }
    
    for (i=nr; i>0; i--)
        out << C[i] << " ";
    
}

int main(){

    in >> n >> m;
    for (i=1; i<=n; i++)
        in >> A[i];
    for (i=1; i<=m; i++)
        in >> B[i];
    
    cmlsc();
    
}
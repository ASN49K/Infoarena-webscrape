#include <fstream>
#include <iostream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int mat[1025][1025],m,n,Final[1025],v1[1025],v2[1025],i,j;

int Max(int a,int b) {
    if(a>b)
        return a;
    return b;
}

int main() {

    fin>>n>>m;
    for(i=1; i<=n; i++) {
        fin>>v1[i];
    }
    for(i=1; i<=m; i++) {
        fin>>v2[i];
    }
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            if(v1[i]==v2[j]) {
                mat[i][j]=mat[i-1][j-1]+1;
            } else {
                mat[i][j]=Max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    int aux=0;
    i=n;
    j=m;

    while(mat[i][j]>0) {
        while(mat[i][j-1]==mat[i][j]) {
            j--;
        }
        while(mat[i-1][j]==mat[i][j]) {
            i--;
        }
        Final[++aux]=v1[i];
		i--;
    }
    fout<<mat[n][m]<<'\n';
    for(i=aux; i>=1; i--) {
        fout<<Final[i]<<' ';
    }
    return 0;
}

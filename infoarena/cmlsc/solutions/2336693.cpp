#include <iostream>
#include <fstream>
using namespace std;

#define NMAX 1026

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

short matrix[NMAX][NMAX];
short sir1[NMAX],n;
short sir2[NMAX],m;
short result[NMAX],k=0;

short maximum(short a, short b){
   return a>b?a:b;
}

void citire(short sir1[],short sir2[],short& n,short& m){
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>sir1[i];
    for(int i=1;i<=m;i++)
        f>>sir2[i];
}

short longest_common_subsequence(short matrix[NMAX][NMAX],short result[],short sir1[],
                                short sir2[],short n, short m, short& k){
    sir1[0]=sir2[0]=0;
    for(int i=1; i<=n; i++)
      for(int j=1;j<=m;j++){
        if( sir1[i] == sir2[j] ){
            matrix[i][j] = matrix[i-1][j-1] + 1;
            result[++k]  = sir1[i];
            }
        else
            matrix[i][j]=maximum(matrix[i][j-1],matrix[i-1][j]);
    }
    return matrix[m][n];
}

int main()
{
   citire(sir1,sir2,n,m);
   longest_common_subsequence(matrix,result,sir1,sir2,n,m,k);
   g<<k<<"\n";
   for(int i=1;i<=k;i++)
    g<<result[i]<<" ";

}

#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int maximum(int a, int b){
   return a>b?a:b;
}

void citire(int sir1[],int sir2[],int& n,int& m){
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>sir1[i];
    for(int i=1;i<=m;i++)
        f>>sir2[i];
}

int longest_common_subsequence(int matrix[100][100],int result[],int sir1[],
                                int sir2[],int n, int m, int& k){
    sir1[0]=sir2[0]=0;
    for(int i=1; i<=n; i++)
      for(int j=1;j<=m;j++){
        if( sir1[i] == sir2[j] ){
            matrix[i][j]=matrix[i-1][j-1]+1;
            result[++k]=sir1[i];
            }
        else
            matrix[i][j]=maximum(matrix[i][j-1],matrix[i-1][j]);
    }
    return matrix[n][m];
}

int main()
{
   int sir1[102],n;
   int sir2[1025],m;
   int matrix[100][100];
   int result[102],k=0;
   int lcs;

   citire(sir1,sir2,n,m);
   lcs=longest_common_subsequence(matrix,result,sir1,sir2,n,m,k);

   g<<lcs<<"\n";
   for(int i=1;i<=k;i++)
    g<<result[i]<<" ";





}

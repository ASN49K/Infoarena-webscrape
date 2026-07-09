#include <iostream>
#include <stdio.h>

using namespace std;
#define maxim(a, b) ((a > b) ? a : b)
#define N 1024

int A[N],B[N],X[N][N],s[N],n,m,i,j,best=0;
int main()
{
    FILE *fin = fopen("cmlsc.in","r");
    FILE *fout = fopen("cmlsc.out","w");
    
    fscanf(fin,"%d %d",&m,&n);
    for(i=1;i<=m;i++) fscanf(fin,"%d",&A[i]);
    for(i=1;i<=n;i++) fscanf(fin,"%d",&B[i]);
    
    // crearea matricei cu lungimile subsirurilor
    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
          {
             if(A[i]==B[j]) X[i][j]=1+X[i-1][j-1];
             else X[i][j]=max(X[i-1][j],X[i][j-1]);
          }
    
    //tracking de la sfarsit la inceput in matrice
    for(i=m,j=n;i;)
    {
        if(A[i]==B[j]) { s[++best]=A[i]; i--; j--; }     
        else if(X[i-1][j]<X[i][j-1]) j--;   
        else i--;            
    }
    
    fprintf(fout,"%d\n", best);
    for(i=best;i;i--) fprintf(fout,"%d ",s[i]);
    
    return 0;
}

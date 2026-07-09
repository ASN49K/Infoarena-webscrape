#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))

unsigned short M,N,PD[1025][1025],
               A[1025],
               B[1025];

FILE *f,
     *g;

void getSubstr(unsigned short l,unsigned short c) {
     
     if(l == 0 || c == 0) return;
          else {
                if(A[l] == B[c]) {
                        
                        getSubstr(l - 1,c - 1);
                        fprintf(g,"%hu ",A[l]);
                }
                else PD[l][c] == PD[l - 1][c] ? getSubstr(l - 1,c) : getSubstr(l,c - 1);
          }                
}

int main() {
    
    f = fopen("cmlsc.in","rt"),
    g = fopen("cmlsc.out","wt");
    
    fscanf(f,"%hu%hu",&M,&N);
    
    unsigned short i,j;
    for(i=1;i<=M;++i) fscanf(f,"%hu",&A[i]);
    for(i=1;i<=N;++i) fscanf(f,"%hu",&B[i]);
    
    for(i=1;i<=M;++i)
      for(j=1;j<=N;++j) {
      
        PD[i][j] = A[i] == B[j] ? PD[i - 1][j - 1] + 1 : max(PD[i - 1][j],PD[i][j - 1]);
        
      }
      
    fprintf(g,"%hu\n",PD[M][N]);
    
    getSubstr(M,N);
      
    fclose(f);
    fclose(g);
    
    return 0;
}

#include<stdio.h>
#define Nmax 1026

int A[Nmax], B[Nmax], C[Nmax][Nmax];
int sol[Nmax];

int MAX(int x,int y){
  if(x>y)
    return x;
   return y; 
}

int main(){

  FILE *fin = fopen("cmlsc.in","r"),
       *fout = fopen("cmlsc.out","w");
       
  int N,M;
  fscanf(fin,"%d%d",&N,&M);
  
  for(int i=1;i<=N;i++)
    fscanf(fin,"%d",&A[i]);
  for(int i=1;i<=M;i++)
    fscanf(fin,"%d%",&B[i]);
    
  for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++){
      C[i][j] = MAX(C[i-1][j], C[i][j-1]);
      if(A[i] == B[j]) 
        C[i][j] = MAX(C[i][j], C[i-1][j-1] + 1);
    }
      
  int L = C[N][M];
  for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
      if(C[i][j] == C[i-1][j-1] + 1 && A[i] == B[j])
        sol[C[i][j]] = A[i];
  
  fprintf(fout,"%d\n",L);
  for(int i=1;i<=L;i++)
    fprintf(fout,"%d ",sol[i]);
    
  fclose(fin);
  fclose(fout);
  return 0;
  
}

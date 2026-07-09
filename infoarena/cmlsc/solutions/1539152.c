#include <stdio.h>

#define L_MAX 1024

int a[L_MAX+1],b[L_MAX+1],comun[L_MAX];
int mat[L_MAX+1][L_MAX+1];

int max(int a,int b){
  if(a>b)
    return a;
  else
    return b;
}

int main(){
  int n,m,i,j,x,nC;
  FILE *fin=fopen("cmlsc.in","r");
  fscanf(fin,"%d%d",&n,&m);
  for(i=1;i<=n;i++)
    fscanf(fin,"%d",&a[i]);
  for(i=1;i<=m;i++)
    fscanf(fin,"%d",&b[i]);
  fclose(fin);

  x = 0;
  //aplicam recurenta
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
      if(a[i]==b[j]){
        comun[x]=a[i];
        mat[i][j]=mat[i-1][j-1]+1;
      }else
        mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    }

  FILE *fout=fopen("cmlsc.out","w");
  fprintf( fout , "%d\n" , mat[n][m]);
  //ne creem sirul comun
  nC=mat[n][m]-1;
  i=n;
  j=m;
  while(mat[i][j]>0){
    //m[i][j] este max dintre vecini pe linie/coloana
    if(mat[i][j-1]==mat[i][j])
      j--;
    else if(mat[i-1][j]==mat[i][j])
      i--;
    //a[i][j] sunt egale
    else {
      comun[nC]=a[i];
      nC--;
      i--;
      j--;
    }
  }
  for(i=0;i<mat[n][m];i++)
    fprintf(fout,"%d ",comun[i]);
  fclose(fout);
  return 0;
}
//recurenta:daca a[i]=b[j] =>m[i][j]=m[i-1][j-1]+1
//          astfel m[i][j]=max(m[i-1][j],m[i][j-1])

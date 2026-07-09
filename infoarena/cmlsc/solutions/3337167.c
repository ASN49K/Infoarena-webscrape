#include <stdio.h>
#include <stdlib.h>

#define MAXMN 1024

struct ura{
  short val;
  char dir;//1 => stanga; 2 => diagonala; 3 => sus
}mat[MAXMN+1][MAXMN+1];
int nr1[MAXMN+1],nr2[MAXMN+1];

char dirl[]={0,0,-1,-1};
char dirc[]={0,-1,-1,0};

int rez[MAXMN];

static inline int max(int a,int b){
  return a>b?a:b;
}

int main(){
  FILE *fin,*fout;
  int m,n,l,c,dir,i;

  fin=fopen("cmlsc.in","r");
  fscanf(fin,"%d%d",&m,&n);
  for(l=1;l<=m;l++){
    fscanf(fin,"%d",&nr1[l]);
  }
  fgetc(fin);//'\n'
  for(c=1;c<=n;c++){
     fscanf(fin,"%d",&nr2[c]);
  }
  fclose(fin);

//  printf("%3c",' ');
//  for(c=1;c<=n;c++){
//    printf("%3d",nr2[c]);
//  }
//  printf("\n");

  for(l=1;l<=m;l++){
//    printf("%3d",nr1[l]);
    for(c=1;c<=n;c++){
      mat[l][c].val=mat[l-1][c-1].val+1;
      mat[l][c].dir=2;
      if(nr1[l]!=nr2[c]){
        if(mat[l-1][c].val>=mat[l][c-1].val){
          mat[l][c].val=mat[l-1][c].val;
          mat[l][c].dir=3;
        }else{
          mat[l][c].val=mat[l][c-1].val;
          mat[l][c].dir=1;
        }
      }
//      printf("%3d",mat[l][c].val);
    }
//    printf("\n");
  }

  fout=fopen("cmlsc.out","w");
  fprintf(fout,"%d\n",mat[m][n].val);
  l=m;
  c=n;
  i=0;
  while((l>=1&&c>=1)&&i<mat[m][n].val){
    dir=mat[l][c].dir;
    if(dir==2){
      rez[i++]=nr1[l];
    }

    l+=dirl[dir];
    c+=dirc[dir];
  }

  for(i=mat[m][n].val-1;i>=0;i--){
    fprintf(fout,"%d ",rez[i]);
  }
  fclose(fout);

  return 0;
}

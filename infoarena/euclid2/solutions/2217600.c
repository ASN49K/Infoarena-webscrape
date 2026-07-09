#include<stdio.h>

int main(){

  int nr;
  FILE *f = fopen("euclid2.in","r");
  FILE *g = fopen("euclid2.out","w");
  
  fscanf(f,"%d\n",&nr);
  int i,x,y,t;
  
  for(i=0;i<nr;i++){
    fscanf(f,"%d %d\n",&x,&y);
    while(y){
      t = x;
      x = y;
      y = t % y;
    }
    fprintf(g,"%d\n",x);
  }
  return 0;
}

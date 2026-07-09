#include<stdio.h>

int main(){

  int nr;
  FILE *f = fopen("euclid.in","r");
  FILE *g = fopen("euclid.out","w");
  
  fscanf(f,"%d\n",&nr);
  int i,x,y,t;
  
  for(i=0;i++<nr;){
    fscanf(f,"%d %d\n",&x,&y);
    while(y){
      t = x;
      x = y;
      y = t % y;
    }
    fprintf(g,"%d\n",x);
  }
  fclose(f);
  fclose(g);
  return 0;
}

#include<stdio.h>
#include<stdlib.h>

int euclid(int x,int y){
  int t;
  while(y){
    t = x;
    x = y;
    y = t % y;
  }
  return x;
}

int main(){

  int nr;
  FILE *f = fopen("euclid.in","r");
  FILE *g = fopen("euclid.out","w");
  
  fscanf(f,"%d\n",&nr);
  int i,x,y;
  
  for(i=0;i++<nr;){
    fscanf(f,"%d %d\n",&x,&y);
    
    fprintf(g,"%d\n",euclid(x,y));
  }
  fclose(f);
  fclose(g);
  return 0;
}

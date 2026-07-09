#include<stdio.h>

int gcd(int a,int b){

  if(b==0)  
    return a;
  return gcd(b,a%b);
  
}


int main(){

  FILE *fin = fopen("euclid2.in","r"),
       *fout = fopen("euclid2.out","w");

  int T;
  fscanf(fin,"%d",&T);
       
  while(T--){
    int a,b;
    fscanf(fin,"%d%d",&a,&b);
  
    fprintf(fout,"%d\n",gcd(a,b));
  }
  fclose(fin);
  fclose(fout);
  return 0;
  
}

#include<stdio.h>

int cmmdc(int a,int b){
if(b==0) return a; else return cmmdc(b,a%b);
}
int main(){
  int a,b,i,n;
  FILE* f=fopen("euclid2.in","r");
  fscanf(f,"%d",&n);
  FILE* h=fopen("euclid2.out","w");
for(i=0;i<n;i++){
          fscanf(f,"%d%d",&a,&b);
          fprintf(h,"%d\n",cmmdc(a,b));
}
  fclose(f); fclose(h);
  return 0;
}

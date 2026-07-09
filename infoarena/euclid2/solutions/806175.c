#include<stdio.h>

int cmmdc(int a,int b){
if(b==0) return a; else return cmmdc(b,a%b);
}
int main(){
  int a[100001][2],i,n;
  FILE* f=fopen("euclid2.in","r");
  fscanf(f,"%d",&n);
  for(i=0;i<n;i++)fscanf(f,"%d%d",&a[i][0],&a[i][1]);
  FILE* h=fopen("euclid2.out","w");
  for(i=0;i<n;i++) fprintf(h,"%d\n",cmmdc(a[i][0],a[i][1]));
  fclose(f); fclose(h);
  return 0;
}

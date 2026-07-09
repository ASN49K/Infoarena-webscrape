#include<stdio.h>
FILE*fin,*fout;
long int i,t,a,b,d,r;
int main(){
fin=fopen("euclid2.in","r");
fout=fopen("euclid2.out","w");
fscanf(fin ,"%ld",&t);
for(i=1;i<=t;i++){

fscanf(fin,"%ld %ld",&a,&b);
r=a%b;
while(r!=0){
a=b; b=r;
r=a%b;
}
fprintf(fout,"%ld\n",b);
}





return 0;}
#include<stdio.h>

int cmmdc(int a,int b)
{
    if(b==0) return a;
    return cmmdc(b,a%b);
    }

int main(){

    FILE *fin=fopen("euclid2.in","r");
    FILE *fout=fopen("euclid2.out","w");

    int a,b,T;
    fscanf(fin,"%d%",&T);


    for(int i=1;i<=T;i++){
    fscanf(fin,"%d %d",&a,&b);
    fprintf(fout,"%d\n",cmmdc(a,b));
    }

    return 0;
    }

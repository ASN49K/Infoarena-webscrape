#include<stdio.h>
using namespace std;
FILE *f1=fopen("euclid2.in","r");
FILE *f2=fopen("euclid2.out","w");
int n,i,a,b;
int cmmdc(int a,int b){
    int c;
    c=a%b;
    while(c!=0){
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}
int main(){
    fscanf(f1,"%d",&n);
    for (i=1;i<=n;i++){
        fscanf(f1,"%d%d",&a,&b);
        fprintf(f2,"%d\n",cmmdc(a,b));
    }
    fclose(f1);
    fclose(f2);
    return 0;
}

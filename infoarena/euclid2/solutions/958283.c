#include <stdio.h>
int cmmdc(int a,int b){
    if(a==0){
        return b;
    }
    return cmmdc(b%a,a);
}
int main(){
    int i,n,a,b;
    FILE *fin,*fout;
    fin=fopen("euclid2.in","r");
    fout=fopen("euclid2.out","w");
    fscanf(fin,"%d",&n);
    for(i=0;i<n;i++){
        fscanf(fin,"%d%d",&a,&b);
        fprintf(fout,"%d\n",cmmdc(a,b));
    }
    return 0;
}

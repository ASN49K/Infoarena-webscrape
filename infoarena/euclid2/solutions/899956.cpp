#include<stdio.h>
long long a,b;
int main(){
    int n,i,r=0;
    FILE *fin=fopen("euclid2.in","r"),*fout=fopen("euclid2.out","w");
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;i++){
        fscanf(fin,"%lld%lld",&a,&b);
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        fprintf(fout,"%lld\n",a);
    }
    return 0;
}

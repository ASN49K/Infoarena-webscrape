#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE*fi,*fout;
    int a,b,r,t,i;
    fi=fopen("euclid2.in" ,"r");
    fout=fopen("euclid2.out" ,"w");
    fscanf(fi,"%d" ,&t);
    for(i=0;i<t;i++){
        fscanf(fi,"%d%d" ,&a,&b);
        while(b>0){
            r=a%b;
            a=b;
            b=r;
        }
        fprintf(fout,"%d\n" ,a);
    }
    fclose(fi);
    fclose(fout);
    return 0;
}

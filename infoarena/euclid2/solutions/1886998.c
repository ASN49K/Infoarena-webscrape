#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE*fin,*fout;
    int n,a,b,aux,i;
    fin = fopen("euclid2.in" ,"r");
    fout = fopen("euclid2.out" ,"w");
    fscanf(fin, "%d" ,&n);
    for(i=0;i<n;i++){
        fscanf(fin, "%d%d" ,&a,&b);
        if(a<b){
            aux=a;
            a=b;
            b=aux;
        }
        while(b!=0){
            aux=b;
            b=a%b;
            a=aux;
        }
        fprintf(fout, "%d\n" ,a);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

#include<stdio.h>

int euclid(int a, int b){
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    FILE *fptr = fopen("euclid2.in","r");
    FILE *fptr2 = fopen("euclid2.out","w");
    int n,a,b;
    
    fscanf(fptr,"%d",&n);

    for(int i = 0; i < n; i++){
        fscanf(fptr,"%d %d",&a,&b);
        fprintf(fptr2,"%d\n", euclid(a,b));

    }
    fclose(fptr);
    fclose(fptr2);
    return 0;
}
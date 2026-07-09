#include<stdio.h>
unsigned long hcf(unsigned long a,unsigned long b){
    unsigned long r = a % b;
    while(r){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int main(int argc, char **argv){
    unsigned long a,b,c;
    unsigned long t;
    FILE *f,*g;
    f = fopen("euclid2.in","r");
    g = fopen("euclid2.out","w");
    fscanf(f,"%lu",&t);
    while(t--){
        fscanf(f,"%lu%lu",&a,&b);
        c = hcf(a,b);
        fprintf(g,"%lu\n",c);
    }





    fclose(f);
    fclose(g);
    return 0;
}

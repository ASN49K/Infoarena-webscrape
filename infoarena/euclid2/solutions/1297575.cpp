#include <cstdio>

//2<=a,b deci nu ma ocup de cazuri speciale
unsigned gcd(unsigned a, unsigned b){
    unsigned temp;

    while(b!=0){
        temp=a;
        a=b;
        b=temp%b;
    }

    return a;
}


int main(){
    FILE *fin = fopen("euclid2.in","r");
    FILE *fout = fopen("euclid2.out","w");

    unsigned T;
    fscanf(fin,"%d",&T);

    for(;T>0;--T){
        unsigned a,b;
        fscanf(fin,"%d %d",&a,&b);
        fprintf(fout,"%d\n",gcd(a,b));
    }

    fclose(fout);
    fclose(fin);
}

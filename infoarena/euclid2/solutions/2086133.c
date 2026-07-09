#include<stdio.h>
long long hcf(long long a,long long b){
    long  long r = a % b;
    while(r){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
//recursive version
long long fme(long long g,long long x,long long p){
    long long a;
    if(x == 1)
        return g;
    if(x % 2 == 0)
        a=( fme(g, x / 2, p) % p * fme(g, x / 2, p) % p ) % p;
    else
        a=( fme(g, x / 2, p) % p * fme(g, x / 2, p) % p * g ) % p;
    return a;
}
int main(int argc, char **argv){
    long long a,b,c;
    long long t;
    FILE *f,*g;
    //Part 1 testing
    f = fopen("euclid2.in","r");
    g = fopen("euclid2.out","w");
    fscanf(f,"%lld",&t);
    while(t--){
        fscanf(f,"%lld%lld",&a,&b);
        c = hcf(a,b);
        fprintf(g,"%lld\n",c);
    }
    fclose(f);
    fclose(g);

    //Note, for this part, I will implement both an iterative and a
    //recursive version of the algorithm
    //Part 2 testing
    /*f = fopen("lgput.in","r");
    g = fopen("lgput.out","w");
    long long MOD = 1999999973;
    fscanf(f,"%lld%lld",&a,&b);
    c = fme(a,b,MOD);
    fprintf(g,"%lld",c);
    fclose(f);
    fclose(g);*/
    return 0;
}

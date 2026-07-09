#include<cstdio>
#define FOR(i, a, b) for(i = a ; i <= b ; ++i)
#define Nmax 1025
using namespace std;

inline int maxim (int a, int b){
    return a>b?a:b;
}
int sir[Nmax],D[Nmax][Nmax],A[Nmax],B[Nmax],nrs;

int main (){
    FILE *in=fopen("cmlsc.in","r");
    int n,m,i,j;
    fscanf(in,"%d%d",&n,&m);
    FOR(i,1,n)  fscanf(in,"%d",&A[i]);
    FOR(i,1,m)  fscanf(in,"%d",&B[i]);

    FOR(i,1,n)
        FOR(j,1,m)
            if(A[i]==B[j])
                D[i][j]=D[i-1][j-1]+1;
            else
                D[i][j]=maxim(D[i-1][j],D[i][j-1]);
    for(i = n , j = m ; i ;)
        if(A[i]==B[j])
            sir[++nrs]=A[i], --i, --j;
        else if(D[i-1][j]<D[i][j-1])
            --j;
        else
            --i;
    FILE *out=fopen("cmlsc.out","w");
    fprintf(out,"%d\n",nrs);
    for(i = nrs ; i ; --i)
        fprintf(out,"%d ",sir[i]);
    fclose(out);
    return 0;
}

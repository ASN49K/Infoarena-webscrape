#include <stdio.h>
#include<algorithm>
using namespace std;
FILE *f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");
long int n,m,v[1033],t[1033],c[1033][1033],sol[1033];


void citire(){
long int i;
    fscanf(f,"%ld %ld\n",&n,&m);
    for(i=1; i<=n; i++){
        fscanf(f,"%ld ",&v[i]);
    }
    for(i=1; i<=m; i++){
        fscanf(f,"%ld ",&t[i]);
    }
}

void  dinamica(){
long int i,j,poz;
    for(i=1; i<=n; i++){
        for(j=1;j<=m; j++){
            if(v[i]==t[j]){
                c[i][j]=c[i-1][j-1]+1;
            }
            else{
                c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    i=n; j=m;
    poz=0;
    while(i!=0){
        if(v[i]==t[j]){
            poz++;
            sol[poz]=v[i]; i--; j--;
        }
        else{
            if(c[i][j-1]>c[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    fprintf(g,"%ld\n",poz);
    for(i=poz; i>=1; i--){
        fprintf(g,"%ld ",sol[i]);
    }
}
int main()
{
    citire();
    dinamica();
    return 0;
}

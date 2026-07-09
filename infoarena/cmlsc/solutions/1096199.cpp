#include<stdio.h>
#define DIM 1026
FILE *f=fopen("cmlsc.in","r"), *g=fopen("cmlsc.out","w");

long int n, m, a[DIM], b[DIM], mat[DIM][DIM], sol[DIM], l, ll;

long int maximul(long int P, long int Q){if(P>Q){return P;}return Q;}

void citire(){
long int i;

    fscanf(f,"%ld %ld\n",&n,&m);
    for(i=1;i<=n;i++)fscanf(f,"%ld ",&a[i]);
    for(i=1;i<=m;i++)fscanf(f,"%ld ",&b[i]);

}

void rezolvare(){
long int i, j;

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){

            if( a[i] == b[j] ){ mat[i][j]= mat[i-1][j-1]+1; }
            else{ mat[i][j] = maximul( mat[i-1][j], mat[i][j-1] ); }

        }
    }   l= mat[n][m];

    fprintf(g,"%ld\n",l);

    //for(i=1;i<=n;i++){for(j=1;j<=m;j++){fprintf(g,"%ld ",mat[i][j]);}fprintf(g,"\n");}

    i=n; j=m; ll=l+1;
    while( i>0 && j>0 ){

        if(a[i]==b[j]){ sol[--ll]=a[i]; i--; j--;}
        else{
            if(mat[i][j]==mat[i-1][j]){i--;}
            else{j--;}
        }
    }
    for(i=1;i<=l;i++){fprintf(g,"%ld ",sol[i]);}

}

int main(){

    citire();
    rezolvare();

return 0;
}

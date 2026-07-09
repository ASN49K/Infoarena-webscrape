#include<stdio.h>
FILE *fin=fopen("cmlsc.in","r");
FILE *fout=fopen("cmlsc.out","w");

int v[1030][1030],n,m,i,j,a[1030],b[1030];

int maxim(int a, int b){
return a<b?b:a;
}

void afisare(int i , int j){

    if(v[i][j]==0) return;

    if( a[i]==b[j] ){
        afisare(i-1,j-1);
        fprintf(fout,"%d ",a[i]);
    }
    else
    if(v[i-1][j]>v[i][j-1]){
        afisare(i-1,j);
    }
    else{
        afisare(i,j-1);
    }
}

int main(){

    fscanf(fin,"%d %d",&n,&m);

    for(i=1;i<=n;i++){
        fscanf(fin,"%d",&a[i]);
    }
    for(j=1;j<=m;j++){
        fscanf(fin,"%d",&b[j]);
    }


    for(i=1;i<=n;i++){
        for(j=1;j<=m; j++){
            if(a[i]==b[j]){
                v[i][j]=v[i-1][j-1]+1;
            }
            else{
                v[i][j]=maxim( v[i][j-1] , v[i-1][j] );
            }
        }
    }

    fprintf(fout,"%d\n",v[n][m]);

    afisare(n,m);

return 0;
}

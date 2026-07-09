#include<cstdio>
int n,m,a[2000],b[2000],d[1050][1050],sol[2000],nr,i,j;
FILE *f,*g;
int maxim(int a,int b){
    if(a>b)
        return a;
    return b;
}
int main(){
    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");
    fscanf(f,"%d%d",&n,&m);
    for(i=1;i<=n;i++){
        fscanf(f,"%d",&a[i]);
    }
    for(j=1;j<=m;j++){
        fscanf(f,"%d",&b[j]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j]){
                d[i][j]=d[i-1][j-1]+1;
            }
            else
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);
        }
    }
    fprintf(g,"%d\n",d[n][m]);
    i=n;
    j=m;
    while(i>=1&&j>=1){
        if(a[i]==b[j]){
            sol[++nr]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]>d[i][j-1])
            i--;
        else
            j--;
    }
    for(i=nr;i>=1;i--){
        fprintf(g,"%d ",sol[i]);
    }

    fclose(f);
    fclose(g);
    return 0;
}

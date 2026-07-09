#include<cstdio>
int n,m,i,j,a[1050],b[1050],d[1050][1050],nmax,nr,x,sol[1040];
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
    for(i=1;i<=m;i++){
        fscanf(f,"%d",&b[i]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);
        }
    }
    fprintf(g,"%d\n",d[n][m]);
    i=n;
    j=m;
    x=d[n][m];
    while(x!=0){
        if(a[i]==b[j]){
            sol[++nr]=a[i];
            i--;
            j--;
            x=d[i][j];
        }
        else if(d[i-1][j]>d[i][j-1]){
            i--;
        }
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

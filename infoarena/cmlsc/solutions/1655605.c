#include <stdio.h>
#define lim 1025
int a[lim],b[lim],d[lim][lim],best[lim];
int max(int x,int y){
    if(x>y)
        return x;
    return y;
}
int main(){
    FILE *fin,*fout;
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");
    int i,j,n,m,lmax=0,x,y;
    fscanf(fin,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(fin,"%d",&a[i]);
    for(i=1;i<=m;i++)
        fscanf(fin,"%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            if(d[i][j]>lmax){
                lmax=d[i][j];
                x=i;
                y=j;
            }
        }
    i=0;
    while(d[x][y]!=0){
        if(a[x]==b[y]){
            i++;
            best[i]=a[x];
            x--;
            y--;
        }
        else
            if(d[x-1][y]<d[x][y-1])
                y--;
            else
                x--;
    }
    fprintf(fout,"%d\n",lmax);
    for(i=lmax;i>=1;i--)
        fprintf(fout,"%d ",best[i]);
    fclose(fin);
    fclose(fout);
    return 0;
}

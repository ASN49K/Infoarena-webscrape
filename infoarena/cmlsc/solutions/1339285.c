#include <stdio.h>
#include <stdlib.h>
int x[1025],y[1025],a[1026][1026],v[1025];
int maxim(int a,int b)
{
    if(a>b) return a;
    return b;
}
int main()
{
    int n,m,i,j,l,c,z,max;
    FILE *fin,*fout;
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");
    fscanf(fin,"%d%d",&n,&m);
    for(i=1; i<=n; i++)
        fscanf(fin,"%d",&x[i]);
    for(j=1; j<=m; j++)
        fscanf(fin,"%d",&y[j]);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=maxim(a[i-1][j],a[i][j-1]);
    max=0;
    l=0;
    c=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i][j]>max){
                max=a[i][j];
                l=i;
                c=j;
            }
    fprintf(fout,"%d\n",max);
    z=max;
    while(a[l][c]!=0 && l!=0 && c!=0)
    {
        if(x[l]==y[c]){
            v[max]=x[l];
            max--;
            l--;
            c--;
        }
        else{
            if(a[l-1][c]>a[l][c-1])
                l--;
            else
                c--;
        }
    }
    for(i=1; i<=z; i++)
        fprintf(fout,"%d ",v[i]);
    fclose(fin);
    fclose(fout);

    return 0;
}

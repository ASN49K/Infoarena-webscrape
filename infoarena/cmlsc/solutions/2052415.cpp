#include <iostream>
#include <cstdio>

using namespace std;
int d[1025][1025];
int a[1025],b[1025];
int sir[1025];

int max(int a, int b, int c){
    if(a>b && a>c)
        return a;
    if(b>a && b>c)
        return b;
    return c;
}

int main()
{
    FILE *fin, *fout;
    int m,n,i,j,best;
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");
    fscanf(fin,"%d %d\n",&m,&n);
    for(i=1;i<=m;i++)
        fscanf(fin,"%d",&a[i]);
    for(i=1;i<=n;i++)
        fscanf(fin,"%d",&b[i]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++){
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i-1][j-1],d[i][j-1]);
        }
    fprintf(fout,"%d\n",d[m][n]);
    best=1;
    for(i=m,j=n;i>0;)
        if(a[i]==b[j]){
            sir[best++]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;
    for(best--;best>0;best--)
        fprintf(fout,"%d ",sir[best]);
    fclose(fin);
    fclose(fout);
    return 0;
}

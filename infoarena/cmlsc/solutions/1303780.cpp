#include <stdio.h>
int a[1025][1025];
int n,m;
int x[1025],y[1025],z[1025];
int maxim(int a,int b)
{
    if(a>b) return a;
    return b;
}
int main()
{
    FILE *fin,*fout;
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");
    fscanf(fin,"%d%d",&n,&m);
    for(int i=1;i<=n;i++) fscanf(fin,"%d",&x[i]);
    for(int i=1;i<=m;i++) fscanf(fin,"%d",&y[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i]==y[j]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=maxim(a[i-1][j],a[i][j-1]);
        }
    }
    int p1=n,p2=m;
    int val=a[n][m];
    while(z[1024]<val)
    {
        if(x[p1]==y[p2])
        {
            z[z[1024]]=x[p1];
            z[1024]++;
            p1--;
            p2--;
        }
        else if(a[p1-1][p2]>a[p1][p2-1]) --p1;
        else --p2;
    }
    fprintf(fout,"%d\n",val);
    for(int i=z[1024]-1;i>=0;i--) fprintf(fout,"%d ",z[i]);
}

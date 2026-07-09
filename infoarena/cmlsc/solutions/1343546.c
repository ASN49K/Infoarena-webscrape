#include<stdio.h>
int max(int a , int b)
{
    if (a>b) return a;
    else return b;
}
int main()
{   int i,n,m,a[100],b[100],c[100][100]={0},j,k=0,d[100];
    FILE *f,*g;
    f=fopen("cmlsc.in","rt");
    g=fopen("cmlsc.out","wt");
    fscanf(f,"%d %d",&n,&m);
    for(i=1;i<=n;i++) fscanf(f,"%d",&a[i]);
    for(i=1;i<=m;i++) fscanf(f,"%d",&b[i]);
   // printf("%d \n",max(2,3));
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i]==b[j]) c[i][j]=1+c[i-1][j-1];
        else c[i][j]=max(c[i-1][j],c[i][j-1]);



while(i>0 && j>0)
if(a[i]==b[j]) {d[++k]=a[i];
                i--;j--;}
else if(c[i-1][j]>c[i][j-1]) i--;
else j--;

fprintf(g,"%d \n",k);
for(i=1;i<=k;i++)
    fprintf(g,"%d ",d[i]);
}

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
FILE *f=fopen("cmlsc.in","r");
int a[1030],b[1030],n,m,s[3030][3030];
void citire( )
{
    fscanf(f,"%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        fscanf(f,"%d",&a[i]);
    for(int i=1;i<=m;i++)
        fscanf(f,"%d",&b[i]);

}
FILE *f1=fopen("cmlsc.out","w");
void numarare( )
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
         if(a[i]==b[j])
           s[i][j]=s[i-1][j-1]+1;
        else
           s[i][j]=max(s[i-1][j],s[i][j-1]);
     fprintf(f1,"%d\n",s[n][m]);

}
void refacere( )
{
    int i=n;
    int j=m;
    int x[1030],k=0;
    while(i!=0&&j!=0)
    {
        if(a[i]!=b[j])
        {
            if(s[i-1][j]<s[i][j-1])
                j--;
          else
            i--;
        }
        else
        {
            x[++k]=a[i];
            i--;
            j--;
        }
    }
    for(int i=k;i>=1;i--)
        fprintf(f1,"%d ",x[i]);
}
int main()
{
    citire();
    numarare();
    refacere();
    return 0;
}

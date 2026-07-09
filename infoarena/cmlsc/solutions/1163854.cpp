//determinati cel mai lung subsir comun a doi vectori a, b
#define creator "Harbinger"
#define infile "cmlsc.in"
#define outfile "cmlsc.out"
#include<iostream>
#include<cstdio>

using namespace std;
int m,n,c[1025][1025];
int a[1025],b[1025];
void backtrack(int,int);

int main()
{
    freopen(infile,"r",stdin);
    freopen(outfile,"w",stdout);
    scanf("%d %d",&m,&n);
    int i,j;
    for(i=1;i<=m;i++) scanf("%d",&a[i]);
    for(i=1;i<=n;i++) scanf("%d",&b[i]);
    for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
                else c[i][j] = max(c[i-1][j],c[i][j-1]);
    printf("%d\n",c[m][n]);
    backtrack(m,n);
}
 void backtrack(int i,int j)
 {
     if(i*j==0) return;
     if(a[i]==b[j])
     {
         backtrack(i-1,j-1);
         printf("%d ",a[i]);
         return;
    }
    if(c[i-1][j]>c[i][j-1]) backtrack(i-1,j);
    else backtrack(i,j-1);
 }

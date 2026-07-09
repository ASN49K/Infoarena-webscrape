//determinati cel mai lung subsir comun a doi vectori a, b
#define creator "Harbinger"
#define infile "cmlsc.in"
#define outfile "cmlcs.out"
#include<iostream>
#include<cstdio>

using namespace std;
short m,n;
unsigned char a[1024],b[1024];
bool ok[1024];


int main()
{
    freopen(infile,"r",stdin);
    freopen(outfile,"w",stdout);
    scanf("%d %d",&m,&n);
    int i,j,ct=0;
    for(i=1;i<=m;i++) scanf("%d",&a[i]);
    for(i=1;i<=n;i++) scanf("%d",&b[i]);
    for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                if(a[i]==b[j]) ok[i]=1,ct++;
    printf("%d\n",ct);
    for(i=1;i<=m;i++)
            if(ok[i]) printf("%d ",a[i]);
}


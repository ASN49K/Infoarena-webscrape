#include <iostream>
#include <fstream>
using namespace std;
int n,m,a[1035],b[1035],i,j,d[1035][1035],sol[1035],k;
int main()
{freopen("cmlsc.in", "r", stdin);
freopen("cmlsc.out", "w", stdout);
scanf("%d%d", &n, &m);
for(i=1; i<=n; i++)
    scanf("%d", &a[i]);
for(i=1; i<=m; i++)
    scanf("%d", &b[i]);
for(i=1; i<=n; i++)
    for(j=1; j<=m; j++)
        if(a[i]==b[j])
            d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
 i=n;
 j=m;
 while(i!=0 && j!=0)
    if(a[i]==b[j])
        {sol[++k]=a[i];
        i--;
        j--;}
        else
            if(d[i-1][j]<d[i][j-1])
                j--;
                else
                    i--;
printf("%d\n", k);
for(i=k; i>=1; i--)
    printf("%d ", sol[i]);




    return 0;
}

#include<stdio.h>
unsigned d[1030][1030],a[1030],b[1030],m,n,i,j,sir[1030],k;
void citire();
void matrice();
unsigned max(unsigned ii, unsigned jj);
void cauta();
void afisare();
int main()
{   freopen("cmlsc.in","r",stdin); freopen("cmlsc.out","w",stdout);
    citire();
    matrice();
    cauta();
    afisare();
    return 0;
}
void citire()
{     scanf("%u%u",&m,&n);
    for(i=1;i<=m;i++) scanf("%u",&a[i]);
    for(i=1;i<=n;i++) scanf("%u",&b[i]);
}
void matrice()
{     for(i=1;i<=m;i++)
      for(j=1;j<=n;j++)
       if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
       else d[i][j]=max(d[i-1][j],d[i][j-1]);
}
unsigned max(unsigned ii, unsigned jj)
{        if(ii>jj) return ii;
         return jj;
}
void cauta()
{    i=m; j=n;
     for(k=d[m][n];k;k--)
     {   while(d[i][j]==d[i-1][j-1]){ i--; j--;}
         while(d[i][j]==d[i-1][j]) i--;
         while(d[i][j]==d[i][j-1]) j--;
         sir[k]=a[i];
         i--; j--;
     }
}
void afisare()
{    printf("%u\n",d[m][n]);
     for(i=1;i<=d[m][n];i++) printf("%u ",sir[i]);
}
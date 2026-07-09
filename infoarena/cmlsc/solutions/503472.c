#include <stdio.h>
#include <stdlib.h>
#define N 1025
int i,j,l1,l2;
int Arr1[N],Arr2[N];
int Res[N][N];

int max(int m1, int m2, int m3) {
    if (m1 >= m2 && m1 >= m3) return m1;
    if (m2 >= m1 && m2 >= m3) return m2;
    return m3;
}
int tipareste(int l1, int l2) {
    if (Res[l1][l2] == 0) return 0;
    if (Arr1[l1] == Arr2[l2]) {
        tipareste(l1-1, l2-1);
        printf("%d ",Arr1[l1]);
    }
    else
     if (Res[l1][l2] == Res[l1-1][l2]) {
         tipareste(l1-1,l2);
     }
     else
      tipareste(l1,l2-1);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&l1,&l2);
    for(i = 1; i <= l1; i++)
     scanf("%d",&Arr1[i]);
    for(i = 1; i <= l2; i++)
     scanf("%d",&Arr2[i]);
    for(i = 1; i <= l1; i++)
     for(j = 1; j <= l1; j++)
      if (Arr1[i] == Arr2[j])
          Res[i][j] = max(Res[i-1][j],Res[i][j-1],Res[i-1][j-1] + 1);
      else
          Res[i][j] = max(Res[i-1][j],Res[i][j-1],Res[i-1][j-1]);
    printf("%d\n",Res[l1][l2]);
    tipareste(l1,l2);
    return 0;
}

#include <cstdio>

using namespace std;
int n , m;
int v1[1025] , v2[1025];
int mat[1025][1025];
int max2(int x , int y)
{
    if(x>y) return x;
    return y;
}
void citire()
{
    freopen("cmlsc.in","r",stdin);
    scanf("%d %d",&m,&n);
    for(int i = 1 ; i<=m ; ++i)
    {
        scanf("%d" , &v1[i]);
    }
    for(int j = 1 ; j <= n ; ++j)
    {
        scanf("%d" , &v2[j]);
    }
}
///
void afisare()
{
   for(int i = 0 ; i <= m ;++i)
   {
       for(int j = 0 ; j <= n ;++j)
       {
           printf("%3d",mat[i][j]);
       }

       printf("\n");
   }
}
void af(int i , int j)
{
    if(i == 0 )
        return;
    if(j == 0)
        return;
    if(v1[i] == v2[j]){
        af(i-1,j-1);
        printf("%d ",v1[i]);
        return;
    }
    if(mat[i][j-1] > mat[i-1][j])
        af(i,j-1);
    else
        af(i-1,j);

}
///
void chestie()
{
    freopen("cmlsc.out" , "w" , stdout);
    for(int i = 1; i<=m ;++i)
    {
        for(int j = 1; j<=n ; ++j)
        {
            if(v1[i] == v2[j])
            {
                mat[i][j] = 1 + mat[i-1][j-1];
            }
            else
                mat[i][j] = max2(mat[i][j-1] , mat[i-1][j]);
        }
    }
    printf("%d\n" , mat[m][n]);
    af(m,n);
    //printf("\n");
    //afisare();

}

int main()
{
    citire();
    chestie();
    return 0;
}

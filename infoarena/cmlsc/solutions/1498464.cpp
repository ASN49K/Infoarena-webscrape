#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int mat[1025][1025] , k = 0 , m , n , a[1025] , b[1025] , v[1025];
void construire_mat()
{
    int i , j;
    for(i=1 ; i<=m ; i++)
        for(j=1 ; j<=n ; j++)
    {
        if( a[i] == b[j] )
            mat[i][j] = 1 + mat[i-1][j-1];
        else
            mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
    }

}
void vectorul_nou()
{
    int i , j ;
    for( i = m ; i>0 ;)
        for( j = n; j>0 ;)
    {
        if(a[i]==b[j])
        {
            v[++k]=a[i];
            i--;
            j--;

        }
        else
        {
            if(max(mat[i][j-1],mat[i-1][j])==mat[i-1][j])
                i--;
            else
                j--;
        }
    }
}
int main()
{
    int i , j ;
    f>> m >> n;
    for( i = 1 ; i <= m ; i ++)
        f >> a[i] ;
    for(i=1;i<=n;i++)
        f >> b[i] ;
    construire_mat();
    vectorul_nou();
   /* for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        g<<mat[i][j]<<" ";
    g<<"\n";
    }*/
    g<<mat[m][n]<<'\n';
    for(i=k;i!=0;i--)
        g<<v[i]<<" ";
    return 0;
}

#include <fstream>
#include <iostream>

using namespace std ;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n;
int a[1024], b[1024], ans[1024];

int main()
{
    fin >> m >> n ;
    for(int i = 0; i< m  ;i++)
        fin >> a[i];
    for(int i = 0 ; i < n ; i++)
        fin >> b[i];
    int mat[m+1][n+1];
    for(int i =0  ;i <= m ; i++) mat[i][0] = 0 ;
    for(int j = 0 ;j<=n ;j++)mat[0][j] = 0;
    for(int i = 1 ; i <=m ; i++)
        for(int j = 1 ; j <= n ; j++)
        {
            if(a[i-1] == b[j-1]){mat[i][j] = mat[i-1][j-1]+1;continue;}
            else if(mat[i][j-1] >= mat[i-1][j])mat[i][j] = mat[i][j-1];
             else if(mat[i][j-1] < mat[i-1][j])mat[i][j] = mat[i-1][j];
        }
    fout << mat[m][n] << "\n";



    int x = m ;
    int y = n ;
    int cnt = m ;
    while(x != 0 && y != 0)
        {
            if(a[x-1] == b[y-1])
                {
                    x-=1;y-=1;ans[cnt] = a[x]; cnt--;
                    continue;
                }
            if(mat[x][y-1] >= mat[x-1][y])
                {
                    y-=1;
                    continue;
                }
            if(mat[x][y-1]<mat[x-1][y])
                {
                    x-=1;
                    continue;
                }


        }

        for(int i = cnt+1 ; i <= m  ;i++)
            fout << ans[i] << ' ' ;
    return 0 ;
}

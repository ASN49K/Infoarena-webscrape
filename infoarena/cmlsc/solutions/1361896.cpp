#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025], n, m, mat[1025][1025];

void recursiv(int i , int j);

int main(){
    fin>> n >> m;
    for(int  i = 1; i <=n ; i ++)
        fin>>a[i];
    for(int  i = 1; i <= m; i++)
        fin>>b[i];
    cout<<n<<" "<<m<<'\n';
    for(int  i = 1; i <=n ; i ++)
        cout<<a[i]<<" ";
    cout<<'\n';
    for(int  i = 1; i <= m; i++)
        cout<<b[i]<<" ";
    cout<<'\n';
    for(int  i  = 1; i <= n ; i++)
        for(int  j = 1; j <=m ; j++)
        {
            if(a[i] == b[j])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                {
                    if(mat[i-1][j] > mat[i][j-1])
                        mat[i][j] = mat[i-1][j];
                    else
                        mat[i][j] = mat[i][j-1];
                }
        }
    fout<<mat[n][m]<<'\n';

    recursiv(n, m);

return 0;
}
void recursiv(int i , int j)
    {
        if( i == 0 || j == 0)
            return;
        if(a[i] == b[j])
            {
                recursiv(i-1, j-1);
                fout<<a[i]<<" ";
                return;
            }
        if(mat[i-1][j] > mat[i][j-1])
            recursiv(i-1, j);
        else
            recursiv(i, j-1);
    }

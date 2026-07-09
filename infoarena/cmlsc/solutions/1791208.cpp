#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[1025] , b[1025] , n , m , c[1025][1025] , comun[1025] , k = 0;

int main()
{
    fin >> n >> m;
    for(int i = 1 ; i <= n ; ++i)
    {
        fin >> a[i];
        c[i][0] = 0;
    }
    for(int i = 1 ; i <= m ; ++i){
        fin >> b[i];
        c[0][i] = 0;
    }
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
        {
            if(a[i] = b[j]) {
                    c[i][j] = c[i-1][j-1] + 1;
                    comun[k] = a[i];
            }
            else c[i][j] = c[i-1][j-1];
        }
    fout << c[n][m];
    //for(int i = 0 ; i < k ; i++) fout << comun[i];
    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[1040] , b[1040] , n , m , c[1040][1040] , comun[1025] , sol = 0;

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
            if(a[i] == b[j])
                    c[i][j] = c[i-1][j-1] + 1;
            else c[i][j] = c[i-1][j-1];
            c[i][j] = max (max (c[i][j] , c[i-1][j]) , c[i][j-1]);
        }
    fout << c[n][m] << endl;

    int i = n , j = m;
    while(i > 0 && j  > 0){
        if(a[i] == b[j]){
            sol++;
            comun[sol] = a[i];
            i--; j--;
        }
        else if(c[i-1][j] < c[i][j-1]) j--;
        else i--;
    }
    for (int i = sol; i >= 1 ; i--) fout << comun[i] << " ";
    return 0;
}

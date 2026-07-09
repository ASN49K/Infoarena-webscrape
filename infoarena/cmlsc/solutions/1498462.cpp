#include <bits/stdc++.h>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int mat[1030][1030], m , n , a[1030], b[1030], c[1030], poz;

void citire_a()
{
    int i;
    for(i = 1; i <= m; i++){
        f>>a[i];
    }
}

void citire_b()
{
    int i;
    for(i = 1; i <= n; i++) {
        f>>b[i];
    }
}

void completare()
{
    int i , j;
    for(j = 1; j <= n; j++){
        for(i = 1; i <= m; i++){
            if(a[i] == b[j]){
                mat[i][j] = mat[i-1][j-1] + 1;
            }else{
            mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
        }
    }
}

void afisare(int i, int j)
{
    while(i != 0 && j != 0){
        if(a[i] == b[j]){
            c[poz] = a[i];
            poz++;
            i--;
            j--;
        }else
        {
            if(mat[i][j-1] > mat[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
}

int main()
{
    int i, j;
    f>>m>>n;
    citire_a();
    citire_b();
    completare();
    g << mat[m][n] << '\n';
    afisare(m, n);
    for(poz = poz - 1 ; poz >=0 ; poz--)
    {
        g<<c[poz]<< " ";
    }
    return 0;
}

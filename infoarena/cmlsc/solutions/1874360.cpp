#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, v1[1025], v2[1025], a[1025][1025];
void f(int i, int j) {
    if(i > 0 && j > 0) {
        if (v1[i] == v2[j]) {
            f(i-1, j-1);
            fout<<v1[i]<<' ';
        } else if (a[i][j-1] > a[i-1][j]) {
            f(i, j-1);
        } else {
            f(i-1, j);
        }
    }
}
int main()
{
    fin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        fin >> v1[i];
    }
    for (int j = 1; j <= m; j++)
    {
        fin >> v2[j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v1[i] == v2[j]) {
                a[i][j] = a[i-1][j-1] + 1;
            }
            else {
                a[i][j] = max(a[i][j-1], a[i-1][j]);
            }
        }
    }
    f(n, m);
    /*
    for (int i = n, j = m; j != 0 && i != 0;;) {
        if (v1[i] == v2[j]) {
            i--;
            j--;
        } else if (a[i][j-1] > a[i-1][j]) {
            j--;
        } else {
            i--;
        }
    }
    */
    fin.close();
    fout.close();
    return 0;
}

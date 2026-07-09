#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int main()
{
    int i, j, n, m, sir1[1024], sir2[1024], sirFinal[1024];
    fin >> n >> m;

    for (i = 1; i <= n; i++)
        fin >> sir1[i];

    for (j = 1; j <= m; j++)
        fin >> sir2[j];

    int l = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m ; j++)
            if (sir1[i] == sir2[j])
                sirFinal[++l] = sir1[i];

    fout << l << '\n';
    for (i = 1; i <= l; i++)
        fout << sirFinal[i] << " ";
    return 0;
}

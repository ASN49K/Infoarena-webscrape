#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int main()
{
    int i, j, n, m, sir1[1024], sir2[1024], sirFinal[1024];
    fin >> m >> n;

    for (i = 1; i <= m; i++)
        fin >> sir1[i];

    for (j = 1; j <= n; j++)
        fin >> sir2[j];

    int l = 0;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n ; j++)
            if (sir1[i] == sir2[j])
                sirFinal[++l] = sir1[i];

    fout << l << '\n';
    for (i = 1; i <= l; i++)
        fout << sirFinal[i] << " ";
    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dist[1026][1026], a[1026], b[1026], n, m;

void Afisare(int i, int j)
{
    if(i < 1 || j < 1)
        return;
    if(a[i] == b[j])
    {
        Afisare(i - 1, j - 1);
        fout << a[i] << " ";
    }
    else
    {
        if(dist[i - 1][j] > dist[i][j - 1])
            Afisare(i - 1, j);
        else Afisare(i, j - 1);
    }
}

int main()
{
    int i, j, v;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(i = 1; i <= m; i++)
        fin >> b[i];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                dist[i][j] = dist[i - 1][j - 1] + 1;
            else dist[i][j] = max(dist[i - 1][j], dist[i][j - 1]);

    fout << dist[n][m] << "\n";
    Afisare(n, m);
    fin.close();
    fout.close();
    return 0;
}

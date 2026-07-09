#include <bits/stdc++.h>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int a[1025];
int b[1025];
int v[1025];
int com[1025][1025];
int L, l;
int k;
void sol1 ()
{
    for (int i = 1; i <= L; i++)
        for (int j = 1; j <= l; j++)
        {
            if (a[i] == b[j])
                com[i][j] += com[i - 1][j - 1] + 1;
            else
                com[i][j] = max (com[i][j - 1], com[i -1][j]);
        }
}
void sol2 (int i, int j)
{
    if (com[i][j] == 0)
        return;
    if (com[i][j] != com[i - 1][j] && com[i][j - 1] != com[i][j])
        v[k--] = a[i], i--, j--;
    else
    {
        if (com[i][j] == com[i - 1][j] && com[i][j - 1] != com[i][j])
            while (com[i][j] == com[i - 1][j])
                i--;
        else
            while (com[i][j] == com[i][j - 1])
                j--;
    }
    sol2 (i, j);
}
int main ()
{
    fin >> L >> l;
    for (int i = 1; i <= L; i++)
        fin >> a[i];
    for (int i = 1; i <= l; i++)
        fin >> b[i];
    sol1 ();
    k = com[L][l];
    sol2 (L, l);
    fout << com[L][l] << "\n";
    for (int i = 1; i <= com[L][l]; i++)
        fout << v[i] << " ";
}

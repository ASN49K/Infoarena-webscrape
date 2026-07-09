#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX_M_N = 1025;

int a[MAX_M_N], b[MAX_M_N];

int aparitii;
int numere[MAX_M_N];

int main()
{
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; i ++)
        fin >> a[i];
    for(int i = 1; i <= m; i ++)
        fin >> b[i];

    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= n; j ++)
            if(b[i] == a[j])
            {
                aparitii ++;
                numere[aparitii] = b[i];
            }
    fout << aparitii << "\n";
    for(int i = 1; i <= aparitii; i ++)
        fout << numere[i] << " ";
    return 0;
}

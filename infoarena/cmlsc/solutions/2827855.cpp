#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX_M_N = 1025;

int Sir_1[MAX_M_N], Sir_2[MAX_M_N];

int numere[MAX_M_N][MAX_M_N];
int afisare[MAX_M_N], k;

int CMLSC(int Sir_1[],int Sir_2[], int m, int n)
{
    for(int j = 1; j <= n; j++)
        if(Sir_1[1] == Sir_2[j])
        {
            numere[1][j] = 1;
            afisare[++ k] = Sir_1[1];
        }

    for(int i = 1; i <= m; i++)
        if(Sir_1[i] == Sir_2[1])
        {
            numere[i][1] = 1;
            afisare[++ k] = Sir_1[i];
        }

    for(int i = 2; i <= m; i ++)
        for(int j = 2; j <= n; j ++)
        {
            if(Sir_1[i] == Sir_2[j])
            {
                numere[i][j] = numere[i - 1][j - 1] + 1;
                afisare[++ k] = Sir_1[i];
            }
            else
                numere[i][j] = max(numere[i - 1][j], numere[i][j - 1]);
        }
    return numere[m][n];
}

int main()
{
    int n, m;
    fin >> m >> n;
    for(int i = 1; i <= m; i ++)
        fin >> Sir_1[i];
    for(int i = 1; i <= n; i ++)
        fin >> Sir_2[i];

    fout << CMLSC(Sir_1, Sir_2, m, n) << "\n";
    for(int i = 1; i <= k; i ++)
        fout << afisare[i] << " ";
    return 0;
}

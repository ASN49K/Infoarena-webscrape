#include <fstream>

using namespace std;

int a[1030], b[1030], lcs[1030][1030], na, nb;

void Citire()
{
    int i;
    ifstream fin("cmlsc.in");
    fin >> na >> nb;
    for (i = 1; i <= na; i++)
        fin >> a[i];
    for (i = 1; i <= nb; i++)
        fin >> b[i];
    fin.close();
}

void LCS()
{
    int i, j;
    a[0] = -1; b[0] = -2;
    for (i = 1; i <= na; i++)
        for (j = 1; j <= nb; j++)
            if (a[i] == b[j])
                lcs[i][j] = 1 + lcs[i-1][j-1];
            else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);

}

void Afisare()
{
    int i, j, t[1030], k;
    ofstream fout ("cmlsc.out");
    fout << lcs[na][nb] << "\n";
    k = 0;
    i = na; j = nb;
    while(i > 0 && j > 0)
    {
        if (a[i] == b[j])
            { t[++k] = a[i]; i--; j--;}
        else if (lcs[i][j-1] > lcs[i - 1][j]) j--;
                else i--;
    }
    for (i = k; i >= 1; i--)
        fout << t[i] << " ";
    fout << "\n";
    fout.close();
}

int main()
{
    Citire();
    LCS();
    Afisare();
    return 0;
}

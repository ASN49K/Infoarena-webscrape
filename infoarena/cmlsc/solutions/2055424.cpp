#include <bits/stdc++.h>

using namespace std;

int n, a[1030], b[1030], m;
int lcs[1030][1030];
int lung[1030], top;

void Citire()
{
    int i;
    ifstream fin ("cmlsc.in");
    fin >> n >> m;
    for (i=1; i<=n; i++)
        fin >> a[i];
    for (i=1; i<=m; i++)
        fin >> b[i];
    fin.close();
}

void Rezolvare()
{
    int i, j;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (a[i]==b[j])
                lcs[i][j]= 1 + lcs[i-1][j-1];
            else /// a[i] != b[j]
                lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);

    i=n; j=m;
    while (i>0 && j>0)
    {
        if (a[i]==b[j])
        {
            lung[++top]=a[j];
            i--;
            j--;
        }
        else
        {
            if (lcs[i-1][j] > lcs[i][j-1]) i--;
            else j--;
        }
    }

    ofstream fout ("cmlsc.out");
    fout << lcs[n][m] << "\n";
    for (i=top; i>=1; i--)
        fout << lung[i] << " ";
    fout << "\n";
    fout.close();
}

int main()
{
    Citire();
    Rezolvare();
    return 0;
}

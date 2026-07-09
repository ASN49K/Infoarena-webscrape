#include <iostream>
#include <fstream>

using namespace std;
int A[1050], B[1050], m, n, arr[1050][1050] = {0};

int lcs(int i, int j)
{
    int rez;
    if (i == m || j == n)
        rez = 0;
    else if (A[i] == B[j]) {
        rez = 1 + (lcs(i+1, j+1));
        arr[i][j] = 1;
    }
    else
        rez = max(lcs(i+1, j),lcs(i, j+1));
        return rez;
}
int subsir(int nr)
{
    nr = lcs(0,0);
    return nr;
}
int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin >> m >> n;
    for (int i = 0; i < m; ++i)
        fin >> A[i];
    for (int j = 0; j < n; ++j)
        fin >> B[j];

    int nr = subsir(0);
    fout << nr << "\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        if (arr[i][j])
        fout << A[i] << " ";
    return 0;
}

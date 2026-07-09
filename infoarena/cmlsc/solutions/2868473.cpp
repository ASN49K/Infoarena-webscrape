#include <cstdio>
//explicatie:
//https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
#define max(a, b) (a > b ? a : b);

using namespace std;


int n, m, a[1030], b[1030], subsirNou[1030];

int lcs[1030][1030];

void Citire() //citim sirurile
{
    scanf("%i", &n);
    scanf("%i", &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%i", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%i", &b[i]);
    }
}

int CelMaiLungSubsirComun(int a[], int b[], int n, int m)
{   //mereu va creste pe diagonala
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            }
            else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
    return lcs[n][m]; //returneaza lungimea maxima
}

void Reconstituire()
{
    int i = n, j = m, k = 0;
    while (i && j)
    {   //daca sunt egale, inseamna ca face parte din subsir (ps: pot exista mai multe longestCommonSubsequences)
        if (a[i] == b[j])
        {
            k++;
            subsirNou[k] = a[i];
            i--;
            j--;
        }
        else if (lcs[i][j - 1] < lcs[i - 1][j])
        {
            i --;
        }
        else
        {
            j--;
        }
    }
    for (int i = k; i >= 1; i--) //vrem sa le afisam in ordine
    {
        printf("%i ", subsirNou[i]);
    }
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    Citire();

    printf("%i\n", CelMaiLungSubsirComun(a, b, n, m));
    Reconstituire();
    return 0;
}

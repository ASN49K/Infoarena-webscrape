#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025][1025];

int s1[1025], s2[1025], afis[1025];

int m, n;

int main()
{
    fin >> m >> n;
    for(int i = 1; i <= m; i++)
        fin >> s1[i];
    for(int i = 1; i <= n; i++)
        fin >> s2[i];
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            if(s1[i] == s2[j])
                a[i][j] = a[i - 1][j - 1] + 1;
            else
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
        }
    int len = 0;
    while(a[m][n] != 0)
    {
        if(s1[m] == s2[n])
        {
            afis[len++] = s1[m];
            n--;
            m--;
        }
        else if(a[m - 1][n] < a[m][n - 1])
            n--;
        else
            m--;
    }
    fout << len <<'\n';
    for(int i = len - 1; i >= 0; i--)
        fout << afis[i] <<' ';
    return 0;
}

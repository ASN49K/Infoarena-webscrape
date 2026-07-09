#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1024][1024];

vector <int> afis;

char s1[1024], s2[1024];

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
    fout << a[m][n] << '\n';
    int len = a[m][n];
    char afis[len];
    int cpy = len;
    while(a[m][n] != 0)
    {
        if(a[m][n] == a[m - 1][n - 1] + 1)
        {
            n--;
            m--;
            afis[--len] = s1[m + 1];
        }
        else
            m --;
    }
    for(int i = 0; i < cpy; i++)
        fout << afis[i] <<' ';
    return 0;
}

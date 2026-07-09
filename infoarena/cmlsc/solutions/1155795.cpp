#include <fstream>

#define NMAX 1035

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short n, m;
short a[NMAX], b[NMAX], d[NMAX];
short s[NMAX][NMAX];

int main()
{
    fin>>n>>m;
    for (int i = 1; i <= n; ++i)
      fin>>a[i];
    for (int i = 1; i <= m; ++i)
      fin>>b[i];

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (a[i] == b[j]) s[i][j] = s[i-1][j-1]+1;
        else s[i][j] = max(s[i-1][j], s[i][j-1]);

    int i = n;
    int j = m;
    int k = 0;
    while (i>0)
    {
      if (a[i] == b[j]) { d[++k] = a[i]; --i; --j;  }
      else if (s[i-1][j] > s[i][j-1]) --i;
        else --j;
    }
    fout<<k<<'\n';
    for (i = k; i > 0; --i)
    {
      fout<<d[i]<<" ";
    }
    return 0;
}

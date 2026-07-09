#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
    int t[1025][1025], a[1025], b[1025];
int main()
{
     int n, m, v[1025];
      fin >> n >> m;
      for(int i = 1; i <= n; ++i) fin >> a[i];
      for(int i = 1; i <= m; ++i) fin >> b[i];
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
            if(a[i] == b[j]) t[i][j] = t[i - 1][j - 1] + 1;else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        fout << t[n][m] << "\n";
            int i = n, j = m, nr = 0;
            while(i && j)
            {
                if(a[i] == b[j])
                    v[++nr] = a[i], i--, j--;else
                    if(t[i - 1][j] == t[i][j]) i--;else j--;
            }
        for(int i = nr; i >= 1; --i) fout << v[i] << " ";
    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, i, j, nr, r1, a[1100], b[1100], rez[1100], best[1100][1100];
short trace[1100][1100];

int main () {
    
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (j = 1; j <= m; j++)
        fin >> b[j];
    
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                best[i][j] = best[i-1][j-1]+1;
                trace[i][j] = 1;
            }
            else
                best[i][j] = max(best[i-1][j], best[i][j-1]);
            
            if (best[i-1][j] > best[i][j-1])    trace[i][j] = 2;
            else trace[i][j] = 3;
        }
    
    i = n;  j = m;
    while (i != 0 && j != 0)
    {
        if (a[i] == b[j])   {   nr++;   rez[nr] = a[i];     }
        
        if (trace[i][j] == 1)   {   i--;    j--;    }
        else if (trace[i][j] == 2)  {   i--;    }
        else if (trace[i][j] == 3)  {   j--;    }
    }
    
    fout << nr << "\n";
    for (i = nr; i >= 1; i--)
        fout << rez[i] << " ";
}

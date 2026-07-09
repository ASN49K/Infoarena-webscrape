#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int main()
{
    int m, n;
    int a[1025], b[1025], h[125][125], sol[1003];
    in >> m >> n;
    for(int i = 1; i <= m; i++) in >> a[i];
    for(int i = 1; i <= n; i++) in >> b[i];
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++) h[i][j] = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            if(a[i] == b[j]) h[i][j] = h[i-1][j-1] + 1;
            else h[i][j] = max(h[i-1][j], h[i][j-1]);
        }
    out << h[m][n] << "\n";
    int k = 0;
    int i, j;
    i  = m;
    j = n;
    while(h[i][j])
    {
        while(h[i][j] == h[i-1][j]) i--;
        while(h[i][j] == h[i][j-1]) j--;
        k++;
        sol[k] = a[i];
        i--;
        j--;
    }
    for(int s = k; s >= 1; s--) out << sol[s] << " ";
    return 0;
}

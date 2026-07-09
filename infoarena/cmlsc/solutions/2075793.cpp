#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#define NMax 1027
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int A, B;
int a[NMax], b[NMax], sir[NMax], ans, c[NMax][NMax];

int main()
{
    f >> A >> B;
    for(int i = 1; i <= A; ++i)
        f >> a[i];
    for(int i = 1; i <= B; ++i)
        f >> b[i];
    for(int i = 1; i <= A; ++i)
        for(int j = 1; j <= B; ++j)
            if(a[i] == b[j]) c[i][j] = c[i - 1][j - 1] + 1;
            else c[i][j] = max(c[i][j - 1], c[i - 1][j]);

    int i_curent = A, j_curent = B;
    while(i_curent)
    {
        if(a[i_curent] == b[j_curent])
        {
            sir[++ans] = a[i_curent];
            --i_curent, --j_curent;
        }
        else if(c[i_curent - 1][j_curent] < c[i_curent][j_curent - 1]) --j_curent;
        else --i_curent;
    }

    g << ans << '\n';

    for(int i = ans; i >= 1; --i)
        g << sir[i] << " ";
    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, D[1030][1030], v1[1030], v2[1030], sir[1030];
int main()
{
    in >> n >> m;
    short i, j;
    for(i = 1; i <= n; i++)
        in >> v1[i];
    for(i = 1; i <= m; i++)
        in >> v2[i];
    in.close();
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(v1[i] == v2[j])
                D[i][j] = 1 + D[i- 1][j - 1];
            else
                D[i][j] = max(D[i][j - 1], D[i - 1][j]);
    short s = 0;
    for(i = n, j = m; i;)
        if(v1[i] == v2[j])
            sir[++s] = v1[i], i--, j--;
        else if (D[i - 1][j] < D[i][j - 1]) j--;
        else i--;
    out << s << "\n";
    for(i = s; i; i--)
       out << sir[i] << " ";
    return 0;
}

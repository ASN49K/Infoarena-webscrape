#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, A[1030], B[1030], D[1030][1030], Sol[1030], s;

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
        fin >> A[i];
    for(int i = 1; i <= m; ++i)
        fin >> B[i];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(A[i] == B[j])
                D[i][j] = 1 + D[i - 1][j - 1];
            else
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);

    for(int i = n, j = m; i;)
        if(A[i] == B[j]) {
            Sol[++s] = A[i];
            --i;
            --j;
        } else if(D[i - 1][j] < D[i][j - 1])
            --j;
        else
            --i;

    fout << s << '\n';
    for(int i = s; i; --i)
        fout << Sol[i] <<' ';

    fin.close();
    fout.close();
    return 0;
}

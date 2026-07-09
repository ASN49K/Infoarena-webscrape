#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int D[1024][1024];
int main()
{
    int m, n, A[1024], B[1024], i, j, sir[1024], nr = 0;
    fin >> m >> n;
    for(i = 1; i <= m; i++)
        fin >> A[i];
    for(i = 1; i <= n; i++)
        fin >> B[i];
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            if(A[i] == B[j])
                D[i][j] = 1 + D[i - 1][j - 1];
            else D[i][j] = max(D[i - 1][j], D[i][j - 1]);
    while(i > 0 && j > 0)
        if(A[i] == B[j])
        {
            sir[++nr] = A[i];
            --i;
            --j;
        }
        else if(D[i - 1][j] < D[i][j - 1])
            --j;
        else --i;
    fout << nr << endl;
    for(i = nr; i >= 1; --i)
        fout << sir[i] << " ";
}

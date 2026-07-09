#include <bits/stdc++.h>

using namespace std;
short A[1026], B[1026], AB[1026][1026], M, N, i, j, nr = 0, v[1026];
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int main()
{
    in >> M >> N;
    for (i = 1; i <= M; i ++)
        in >> A[i];
    for (i = 1; i <= N; i ++)
        in >> B[i];
    for (i = 1; i <= M; i ++)
        for(j = 1; j <= N; j ++)
            {
                if(A[i] == B[j])
                    AB[i][j] = AB[i - 1][j - 1] + 1;
                else AB[i][j] = max(AB[i - 1][j], AB[i][j - 1]);
            }
    i = M; j = N;
    while (i > 0 and j > 0)
    {
        if(A[i] == B[j])
        {
            nr ++;
            v[nr] = A[i];
            j --; i --;
        }
        else if (AB[i - 1][j] < AB[i][j - 1]) j --;
                else i --;
    }
    int MAX = AB[M][N];
    out << MAX << "\n";
    for (i = nr; i > 0; i --)
        out << v[i] << " ";
    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int A[1030], B[1030], DP[1030][1030], N, M;
int lcs[1030], length;

int main()
{
    fin >>M >>N;

    for (int i = 1; i <= M; ++i)
        fin >>A[i];

    for (int i = 1; i <= N; ++i)
        fin >>B[i];

    for (int i = 1; i<= M; ++i)
        for (int j = 1; j <= N; ++j)
            if (A[i]==B[j])
                DP[i][j] = DP[i-1][j-1]+1;
            else
                DP[i][j] = (DP[i-1][j] > DP[i][j-1]) ? DP[i-1][j] : DP[i][j-1];

    for (int i = M, j = N; i; )
        if (A[i]==B[j])
        {
           lcs[++length]=A[i];
           --i; --j;
        }
        else
            if (DP[i-1][j] < DP[i][j-1])
                --j;
            else
                --i;

    fout <<length <<'\n' ;

    for (int i = length; i > 0; --i)
        fout <<lcs[i] <<' ';

    fout <<'\n';

    return 0;
}

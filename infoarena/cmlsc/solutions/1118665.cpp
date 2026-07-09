#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int NMAX = 1030;

int N, M, A[NMAX], B[NMAX], Best[NMAX][NMAX];
vector<int> Ans;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%i %i", &N, &M);
    for(int i = 1; i <= N; ++ i) scanf("%i", &A[i]);
    for(int i = 1; i <= M; ++ i) scanf("%i", &B[i]);

    for(int i = 1; i <= N; ++ i)
        for(int j = 1; j <= M; ++ j)
            if(A[i] == B[j])
                Best[i][j] = Best[i - 1][j - 1] + 1;
            else
                Best[i][j] = max(Best[i - 1][j], Best[i][j - 1]);

    printf("%i\n", Best[N][M]);
    int Lin = N, Col = M;
    while(Lin && Col)
    {
        if(A[Lin] == B[Col])
        {
            Ans.push_back(A[Lin]);
            Lin --;
            Col --;
        }else if(Best[Lin - 1][Col] > Best[Lin][Col - 1]) Lin --;
        else Col --;
    }

    reverse(Ans.begin(), Ans.end());
    for(int i = 0; i < Ans.size(); ++ i) printf("%i ", Ans[i]);
}

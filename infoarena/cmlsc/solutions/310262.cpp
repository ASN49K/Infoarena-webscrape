#include <fstream>
#include <iterator>
#include <vector>
using namespace std;

#define NUME "cmlsc"
ifstream fi(NUME".in");
ofstream fo(NUME".out");
#define MAXN 1030

int N, M;
int A[MAXN], B[MAXN], C[MAXN][MAXN];
vector<int> output;

int main()
{
    fi >> N >> M;
    int i, j;
    for (i = 1; i <= N; ++i)
        fi >> A[i];
    for (i = 1; i <= M; ++i)
        fi >> B[i];
    for (i = 1; i <= N; ++i)
        for (j = 1; j <= M; ++j)
            C[i][j] = (A[i] == B[j]) ? C[i-1][j-1]+1 :
                max(C[i-1][j], C[i][j-1]);
    fo << C[N][M] << "\n";
    /*
    for (i = 1; i <= N; ++i) {
        for (j = 1; j <= M; ++j)
            fo << C[i][j] << " ";
        fo << "\n";
    }
    */
    i = N, j = M;
    while (i && j) {
        if (A[i] == B[j]) {
            output.push_back(B[j]);
            --j; --i;
        } else if (C[i-1][j] < C[i][j-1])
            --j;
        else
            --i;
    }
    copy(output.rbegin(), output.rend(),
            ostream_iterator<int>(fo, " "));
    return 0;
}

#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int A[1025], B[1025], D[1025][1025], sir[1025];
int main()
{
    int M, N, i, j, bst;
    cin >> M >> N;
    for(i = 1; i <= M; i++)
    {
        cin >> A[i];
    }
    for(i = 1; i <= N; i++)
    {
        cin  >> B[i];
    }
    for(i = 1; i <= M; i++)
    {
        for(j = 1; j <= N; j++)
        {
            if(A[i] == B[j])
            {
                D[i][j] = 1 + D[i - 1][j - 1];
            }
            else
            {
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
            }
        }
    }
    for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

    cout << bst;
    for (i = bst; i; --i)
        cout << sir[i];

    return 0;
}

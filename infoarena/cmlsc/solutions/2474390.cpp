#include <fstream>

#define Maxim(a, b) ((a > b) ? a : b)
#define ARR_MAX 1024

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[ARR_MAX], B[ARR_MAX], C[ARR_MAX][ARR_MAX], sir[ARR_MAX], m, n, bst;

/*inline int Maxim(int a, int b)
{
    return (a > b) ? a : b;
}*/

int main()
{
    fin >> m >> n;

    for(int i = 1; i <= m; ++i)
        fin >> A[i];

    for(int i = 1; i <= n; ++i)
        fin >> B[i];

    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            if(A[i] == B[j])
                C[i][j] = 1 + C[i-1][j-1];
            else
                C[i][j] = Maxim(C[i-1][j], C[i][j-1]);

    int i, j;
    for(i = m, j = n; i;)
        if(A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if(C[i-1][j] < C[i][j-1])
            --j;
        else
            --i;

    fout << bst << "\n";

    for(i = bst; i; --i)
        fout << sir[i] << " ";

}

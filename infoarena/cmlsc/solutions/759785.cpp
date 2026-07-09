#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    //CITIRE DATE
    int m, n; scanf("%d %d", &m, &n);
    int matrix[m + 2][n + 2]; matrix[1][1] = matrix[0][0] = matrix[1][0] = matrix[0][1] = 0;
    for (int i = 2; i <= m + 1; i++) { scanf("%d", &matrix[i][0]); matrix[i][1] = 0; }
    for (int i = 2; i <= n + 1; i++) { scanf("%d", &matrix[0][i]); matrix[m + 1][i] = matrix[1][i] = 0; }
    //CREARE TABLOU
    for (int i = 2; i <= m + 1; i++)
        for (int j = 2; j <= n + 1; j++)
            if (matrix[i][0] == matrix[0][j])
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            else
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j-1]);

    //RECUPERARE SUBSIR
    vector<int> subsir;

    //SCRIERE REZULTATE
    printf("%d \n", matrix[m + 1][n + 1]);
    for (int i = 0; i < subsir.size(); i++)
        printf ("%d ", subsir[i]);

    return 0;
}

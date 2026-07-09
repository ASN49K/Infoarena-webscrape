#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    //CITIRE DATE
    int m, n; scanf("%d %d", &m, &n);
    int matrix[m + 2][n + 1];
    vector<int> subsir;
    for (int i = 1; i <= m; i++)
        scanf("%d", &matrix[i][0]);
    for (int i = 1; i <= n; i++)
        {
            scanf("%d", &matrix[0][i]);
            matrix[m + 1][i] = 0;
        }

    //CREARE TABLOU
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            matrix[i][j] = matrix[m + 1][j];
            if (matrix[i][0] == matrix[0][j])
                for(j; j <= n; j++)
                   {
                       matrix[m + 1][j]++;
                       matrix[i][j] = matrix[m + 1][j];
                   }
        }
    //RECUPERARE SUBSIR
    int pos = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (matrix[i][j] > subsir.size())
                if  (j > pos)
                {
                    subsir.push_back(matrix[i][0]);
                    pos = j;
                }
                else if (j < pos && subsir.size() == matrix[i][j])
                {
                    subsir.pop_back();
                    subsir.push_back(matrix[i][0]);
                }
    //SCRIERE REZULTATE
    printf("%d \n", matrix[m][n]);
    for (int i = 0; i < subsir.size(); i++)
        printf ("%d ", subsir[i]);
    return 0;
}

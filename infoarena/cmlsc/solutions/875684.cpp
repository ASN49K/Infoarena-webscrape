#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void readVector(vector<int> &v, int size)
{
    v.resize(size);
    for(int i = 0; i < size; ++i)
    {
        scanf("%d", &v[i]);
    }
}

void printVector(vector<int> &v, int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void printMatrix(int **matrix, int m, int n)
{
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void redirectInput(const char *in, const char *out)
{
    freopen(in, "r", stdin);
    freopen(out, "w", stdout);
}

int** allocEfficientMatrix(int m, int n)
{
    int **matrix = new int*[m];
    int *v = new int[m*n];
    for(int i = 0; i < m; ++i)
    {
        matrix[i] = &v[i*n];
    }
    return matrix;
}

void deleteEfficientMatrix(int **matrix, int m, int n)
{
    delete[] matrix[0];
    delete[] matrix;
}

void solve(vector<int> &x, vector<int> &y, int m, int n)
{
    int **lcs = allocEfficientMatrix(m + 1, n + 1);
    for(int i = 0; i < m; ++i)
    {
        lcs[i][0] = 0;
    }
    for(int j = 0; j < n; ++j)
    {
        lcs[0][j] = 0;
    }
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
        {
            if(x[i-1] == y[j-1])
            {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    vector<int> solution;
    for(int i = m, j = n; i != 0 && j != 0;)
    {
        if(x[i-1] == y[j-1])
        {
            solution.push_back(x[i-1]);
            --i, --j;
        }
        else if(lcs[i-1][j] < lcs[i][j-1])
            --j;
        else
            --i;
    }
    for(int i = solution.size() - 1; i >= 0; --i)
    {
        printf("%d ", solution[i]);
    }
    printf("\n");
    deleteEfficientMatrix(lcs, m + 1, n + 1);
}

int main()
{
    redirectInput("cmlsc.in", "cmlsc.out");
    int m, n;
    vector<int> x, y;
    scanf("%d %d", &m, &n);
    readVector(x, m);
    readVector(y, n);
    solve(x, y, m, n);

    return 0;
}
#include <cstdio>
#include <vector>

using namespace std;

int mat[1024][1024];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int x1[1024];
    int x2[1024];
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x1[i]);
    }

    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &x2[i]);
    }

    int nrx = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(x1[i] == x2[j])
            {
                mat[i][j] = mat[i - 1][j - 1] + 1;

                if(mat[i][j] > nrx)
                {
                    nrx = mat[i][j];
                }
            }
            else
            {
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
            }
        }
    }

    vector<int> solutii;

    for(int i = n; i > 0; i--)
    {
        for(int j = m; j > 0; j--)
        {
            if(x1[i] == x2[j])
            {
                if(nrx == mat[i][j])
                {
                    nrx--;
                    solutii.push_back(x1[i]);
                }
            }
        }
    }

    printf("%d\n", solutii.size());

    for(int i = solutii.size() - 1; i >= 0; i--)
    {
        printf("%d ", solutii[i]);
    }

    return 0;
}

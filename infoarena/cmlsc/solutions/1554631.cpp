#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int n, m;
    int x1[1030], x2[1030];
    vector<int> solutie;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x1[i]);
    }

    for(int j = 0; j < m; j++)
    {
        scanf("%d", &x2[j]);
    }

    int l = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(x1[i] == x2[j])
            {
                solutie.push_back(x1[i]);
                l++;
            }
        }
    }

    int lungime = solutie.size();

    printf("%d\n", l);

    for(int i = 0; i < l; i++)
    {
        printf("%d ", solutie[i]);
    }


    return 0;
}

#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int m, n;
    int i,j;
    int aux;

    vector<int> a, b, res;

    scanf("%d %d", &m, &n);//cin >> m >> n;

    for ( i = 1; i <= m; i++ )
    {
        scanf("%d", &aux);//cin >> aux;
        a.push_back(aux);
    }

    for ( i = 1; i <= n; i++ )
    {
        scanf("%d", &aux);//cin >> aux;
        b.push_back(aux);
    }

    //dp[i][j] = cel mai lung subsir comun intre primele i elemente din a si primele j elemente din b
    int dp[1025][1025];

    //cazul de baza: prima linie si prima coloana
    dp[0][0] = 0;
    if ( a[0] == b[0] )
    {
        dp[0][0] = 1;
    }
    for ( j = 1; j < b.size(); j++ )
    {
        if ( a[0] == b[j] || dp[0][j - 1] == 1 )
        {
            dp[0][j] = 1;
        }
    }
    for ( i = 1; i < a.size(); i++ )
    {
        if ( a[i] == b[0] || dp[i - 1][0] == 1 )
        {
            dp[i][0] = 1;
        }
    }

    //construirea matricii
    for ( i = 1; i < a.size(); i++ )
    {
        for ( j = 1; j < b.size(); j++ )
        {
            if ( a[i] == b[j] )
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = (dp[i][j - 1] > dp[i - 1][j]) ? dp[i][j - 1] : dp[i - 1][j];
            }
        }
    }

    printf("%d\n",dp[m - 1][n - 1]);//cout << dp[m - 1][n - 1] << "\n";

    //refacerea solutiei
    i = a.size() - 1;
    j = b.size() - 1;

    while ( i >= 0 && j >= 0 )
    {
        if ( dp[i - 1][j] == dp[i][j] )
        {
            i--;
        }
        else
        {
            if ( dp[i][j - 1] == dp[i][j] )
            {
                j--;
            }
            else
            {
                res.insert(res.begin(), b[j]);
                i--;
                j--;
            }
        }
    }

    for ( i = 0; i < res.size(); i++ )
    {
        printf("%d ",res[i]);//cout << res[i] << " ";
    }
    printf("\n");//cout << "\n";

    return 0;
}

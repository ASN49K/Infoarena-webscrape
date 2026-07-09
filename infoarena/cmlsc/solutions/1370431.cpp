#include <cstdio>
#include <vector>
#define NMAX  1030

using namespace std;

int n,m;
int a[NMAX],b[NMAX];
int s[NMAX][NMAX],drum[NMAX][NMAX];
vector<int>sol;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
    for(int i = 1; i <= m; ++i) scanf("%d",&b[i]);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if (a[i] == b[j])
            {
                s[i][j] = s[i-1][j-1] + 1;
                drum [i][j] = 1;
            }
            else if (s[i-1][j] > s[i][j-1])
                {
                    s[i][j] = s[i-1][j];
                    drum[i][j] = 2;
                }
                else
                {
                    s[i][j] = s[i][j-1];
                    drum[i][j] = 3;
                }
        }
    printf("%d\n", s[n][m]);
    int i=n,j=m;
    while( i > 0 && j > 0)
    {
        if (drum[i][j] == 1) {sol.push_back(a[i]);--i;--j;}
            else
            {
                if (drum[i][j] == 2) --i;
                    else --j;
            }
    }

    for(int i = sol.size() - 1; i >= 0 ; --i) printf("%d ",sol[i]);
    return 0;
}

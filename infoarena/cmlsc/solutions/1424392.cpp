#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,a[1025],b[1025],D[1025][1025];
vector <int> sol;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (a[i]==b[j]) D[i][j]=D[i-1][j-1]+1;
            else D[i][j]=max(D[i-1][j],D[i][j-1]);
        }
    }
    printf("%d\n",D[n][m]);
    int i=n,j=m;
    while (i>0 && j>0)
    {
        if (a[i]==b[j])
        {
            sol.push_back(a[i]);
            i--,j--;
        }
        else if (D[i-1][j]>D[i][j-1]) i--;
        else j--;
    }
    for (vector<int>::reverse_iterator rit=sol.rbegin();rit!=sol.rend();rit++)
        printf("%d ",*rit);
    return 0;
}

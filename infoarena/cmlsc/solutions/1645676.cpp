#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>

#define NMax 1030
using namespace std;
int n,m;
int a[NMax],b[NMax];
int M[NMax][NMax];
vector<int> sol;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; ++i){
        scanf("%d",&a[i]);
    }
    for(int i = 1; i <= m; ++i){
        scanf("%d",&b[i]);
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i] == b[j])
                M[i][j] = M[i - 1][j - 1] + 1;
            else
                M[i][j] = max(M[i][j - 1],M[i - 1][j]);
        }
    }
    printf("%d\n",M[n][m]);
    int i = n,j = m;
    while(i >= 1 && j >= 1){
        if(M[i][j] == M[i][j - 1])
            j--;
        else
        if(M[i][j] == M[i - 1][j])
            i--;
        else
        if(M[i][j] == M[i - 1][j - 1] + 1){
            sol.push_back(a[i]);
            i--;
            j--;
        }
    }
    for(int i = sol.size() - 1; i >= 0; --i){
        printf("%d ",sol[i]);
    }
    return 0;
}

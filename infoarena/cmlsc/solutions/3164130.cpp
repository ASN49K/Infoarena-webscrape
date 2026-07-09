#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
const int NMAX=1025;
int v1[NMAX],v2[NMAX],mat[NMAX][NMAX],dir[NMAX][NMAX];
int main()
{

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&v1[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&v2[i]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(v1[i]==v2[j]){
                mat[i][j]=mat[i-1][j-1]+1;
                dir[i][j]=2;
            }else{
                if(mat[i-1][j]>mat[i][j-1]){
                    mat[i][j]=mat[i-1][j];
                    dir[i][j]=1;
                }else{
                    mat[i][j]=mat[i][j-1];
                    dir[i][j]=-1;
                }
            }
        }
        vector<int> ans;
        int nr=0;
        int i=n,j=m;
        while(i&&j){
            if(dir[i][j]==2){
                ans.push_back(v1[i]);
                nr++;
                i--;
                j--;
            }else{
                if(dir[i][j]==1)
                    i--;
                else
                    j--;
            }
        }
        printf("%d\n",nr);

        reverse(ans.begin(),ans.end());
        for(int number:ans)
            printf("%d ",number);

    return 0;
}

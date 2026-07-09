#include<cstdio>
#include<vector>
using namespace std;
vector <unsigned char> d[1025][1025];
unsigned char a[1025],b[1025];
int main(){
    int m,n,i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j]){
                d[i][j]=d[i-1][j-1];
                d[i][j].push_back(a[i]);
            }else{
                if(d[i-1][j].size()>d[i][j-1].size())
                    d[i][j]=d[i-1][j];
                else
                    d[i][j]=d[i][j-1];
            }
    printf("%d\n",d[m][n].size());
    for(i=0;i<d[m][n].size();i++)
        printf("%d ",d[m][n][i]);
    return 0;
}

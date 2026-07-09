#include<cstdio>
#include<vector>
using namespace std;
vector <unsigned char> d[3][1025];
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
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++)
            if(a[i]==b[j]){
                d[2][j]=d[1][j-1];
                d[2][j].push_back(a[i]);
            }else{
                if(d[1][j].size()>d[2][j-1].size())
                    d[2][j]=d[1][j];
                else
                    d[2][j]=d[2][j-1];
            }
        for(j=1;j<=n;j++)
            d[1][j]=d[2][j];
    }
    printf("%d\n",d[1][n].size());
    for(i=0;i<d[1][n].size();i++)
        printf("%d ",d[1][n][i]);
    return 0;
}

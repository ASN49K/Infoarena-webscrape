#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX=1030;
int a[NMAX],b[NMAX],matrix[NMAX][NMAX],n,m;
void f(int ind1, int ind2){
    if(!ind1 || !ind2)
        return ;
    if(a[ind1]==b[ind2]){
        printf("%d ", a[ind1]);
        f(ind1-1, ind2-1);
    }
    else{
        if(matrix[ind1-1][ind2]>matrix[ind1][ind2-1])
            f(ind1-1, ind2);
        else
            f(ind1, ind2-1);
    }
}
int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d", &b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i]==b[j])
                matrix[i][j]=matrix[i-1][j-1]+1;
            else
                matrix[i][j]=max(matrix[i][j-1], matrix[i-1][j]);
        }
    printf("%d\n", matrix[n][m]);
    f(n, m);
    return 0;
}

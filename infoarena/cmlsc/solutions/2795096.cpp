#include <bits/stdc++.h>

using namespace std;
int n,m,A[1025],B[1025],C[1025][1025];
stack <int> v;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&A[i]);
    for(int j=1;j<=m;j++)
        scanf("%d",&B[j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            if(A[i]==B[j])
                C[i][j]=C[i-1][j-1]+1;
            else C[i][j]=max(C[i-1][j],C[i][j-1]);
    }
    printf("%d\n",C[n][m]);
    for(int i=n,j=m;i; ){
        if(A[i]==B[j]){
            v.push(A[i]);
            --i;
            --j;
        }else if(C[i][j]==C[i-1][j])
                --i;
            else --j;
    }
    while(!v.empty()){
        printf("%d ",v.top());
        v.pop();
    }
}

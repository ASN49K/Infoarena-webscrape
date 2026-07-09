//cmlsc
#include<bits/stdc++.h>
#define debug cerr<<"ok";
#define MAXN 1024
using namespace std;

int n,i,j,a[MAXN],b[MAXN],D[MAXN][MAXN],m;
int parent[MAXN][MAXN];

void drum(int i, int j){


int x= parent[i][j];
if(i==0 || j==0 || x==-1)
    return;

if(x){
    if(x == 1){
        drum(i-1,j-1);
        cout<<a[i]<<" ";
    }
    if(x == 2)
        drum(i-1,j);
    if(x == 3)
        drum(i,j-1);
}

}

int main ()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    int x,y;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
     for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    D[0][0]=0;
    memset(parent,-1,sizeof(parent));
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j]){
                D[i][j]=D[i-1][j-1]+1;
                parent[i][j]=1; // stanga sus -diagonala-
            }
            else{
                x= D[i-1][j];
                y= D[i][j-1];
                D[i][j]=max(x,y);
                if(D[i][j] == x)
                    parent[i][j] = 2; // sus
                else if(D[i][j] == y)
                    parent[i][j] = 3; //stanga
            }

        printf("%d\n",D[n][m]);
    drum(n,m);
    return 0;
}

#include<cstdio>
using namespace std;
int a[1030],b[1030],d[1030][1030],sol[1030];
int maxim(int a,int b){
    if(a<b)
        return b;
    return a;
}
int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);
    for(i=n,j=m;i>0;)
        if(a[i]==b[j]){
            sol[0]++;
            sol[sol[0]]=a[i];
            i--;
            j--;
        }
        else
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
    printf("%d\n",sol[0]);
    for(i=sol[0];i>=1;i--)
        printf("%d ",sol[i]);
    return 0;
}

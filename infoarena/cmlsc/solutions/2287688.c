#include<stdio.h>
short int v[1025],s[1025][1025],i,j,n,m,x[1025],y[1025],k;
int main() {
    freopen("cmlsc.in","r",stdin),freopen("cmlsc.out","w",stdout),scanf("%hd%hd",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%hd",x+i);
    for(i=1;i<=m;i++)
        scanf("%hd",y+i);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(x[i]==y[j])
            s[i][j]=1+s[i-1][j-1];
        else
            s[i][j]=s[i-1][j]<s[i][j-1]?s[i][j-1]:s[i-1][j];
    printf("%hd\n",s[n][m]);
    for(i=n,j=m;i;)
        if(x[i]==y[j])
            v[++k]=x[i],i--,j--;
        else if(s[i-1][j]<s[i][j-1])
            j--;
        else
            i--;
    for(i=k;i;i--)
        printf("%hd ",v[i]);
}

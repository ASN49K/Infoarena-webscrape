#include <stdio.h>
#include <vector>
using namespace std;
vector<int>v;
int n,m,a[1025],b[1025],c[1025][1025];

inline int max(int a,int b){ return a>b?a:b; }

void great(){
    int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j])c[i][j]=1+c[i-1][j-1]; else
    c[i][j]=max(c[i][j-1],c[i-1][j]); }

void common(int i,int j){
    if(c[i][j]>0)
    if(a[i]==b[j]){
        v.push_back(a[i]);
        common(i-1,j-1); } else {
    if(c[i][j-1]>c[i-1][j])common(i,j-1); else common(i-1,j); }
}

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    great();
    common(n,m);
    printf("%d\n",c[n][m]);
    for(;v.size()>0;){
        printf("%d ",v.back());
        v.pop_back(); }
}

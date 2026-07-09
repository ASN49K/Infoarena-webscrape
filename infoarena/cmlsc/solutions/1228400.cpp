#include <cstdio>
#define max_l 1024

using namespace std;
int n,m,a[max_l],b[max_l];
int lcs[max_l][max_l];
int s[max_l],bst;
/*
struct qu{
int x;
qu *next;
} *fi;
*/
int max(int x,int y){
if(x>y)return x;
return y;
}
/*
void add(int x){
qu *c=new qu;
c->x=x;
c->next=fi;
fi=c;
}
*/
int main(void){
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d%d",&n,&m);
int i=1,j;
while(i<=n){
scanf("%d",&a[i]);
++i;
}
i=1;
while(i<=n){
scanf("%d",&b[i]);
i++;
}
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
if(a[i]==b[j])
lcs[i][j]=lcs[i-1][j-1]+1;
else          
lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
//printf("%d\n",lcs[n][m]);
i=n;j=m;
/*
fi=NULL;
while(i||j){
if(a[i]==b[j]){
add(a[i]);
i--;j--;
}
else 
if(lcs[i-1][j]<lcs[i][j-1])
j--;
else 
i--;
}
while(fi){
printf("%d ",fi->x);
fi=fi->next;
}
*/
while(i&&j){
if(a[i]==b[j]){
s[++bst]=a[i];
i--;j--;
}
else 
if(lcs[i-1][j]>lcs[i][j-1])
i--;
else
j--;
}
printf("%d\n",bst);
for(i=bst;i>0;i--)
printf("%d ",s[i]);
}
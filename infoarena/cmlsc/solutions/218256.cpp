#include"stdio.h"
int s,v2[1025],v[1025], n, m, x;
void add(int x){v2[s]=x;s++;}void print(){printf("%d\n",s);for(int g=0;g<s;g++)printf("%d ",v2[g]);}
int main(){freopen("cmlsc.in","r",stdin);freopen("cmlsc.out","w",stdout);scanf("%d%d",&n,&m);
for(int g=1;g<=n;g++)scanf("%d ",&v[g]);
for(int h=1;h<=m;h++){scanf("%d",&x);for(int q=1;q<=n;q++)if(x==v[q]){add(x);v[q]=-1;}}print();return 0;}

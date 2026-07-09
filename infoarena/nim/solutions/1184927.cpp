#include <cstdio>
using namespace std;
int t,n,v[10001];
int main(){
    int i,s;
   freopen("nim.in","r",stdin);
   freopen("nim.out","w",stdout);
   scanf("%d",&t);
   while(t--){
    scanf("%d",&n);
    for(i=1,s=0;i<=n;i++)
        {scanf("%d",&v[i]); s^=v[i];}
     if(s) printf("DA\n");
     else printf("NU\n");
   }
    return 0;
}

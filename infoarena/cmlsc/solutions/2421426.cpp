#include<cstdio>
#include<vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz size
#define F first
#define S second
const int S=512,M=2048;
int x[M],y[M],n,m,p,s[M],i,j,k,e,f,u,v;
vector<int> a[S];
vector<pair<int,int>> b[M];
void R(int l,int c,int d)
{
	if(d<=0)
    {
        printf("%d ",x[l]);
        return;
    }
    int i,j;
	for(j=b[d].sz(),i=0;i<j;++i)
		if(b[d][i].F<l&&b[d][i].S<c)
            R(b[d][i].F,b[d][i].S,d-1);
}
int main()
{
	freopen("cmlsc.in","r",stdin),freopen("cmlsc.out","w",stdout),scanf("%d%d",&n,&m);
	for(i=0;i<n;++i)
        scanf("%d",x+i);
	for(i=0;i<m;++i)
        scanf("%d",y+i);
	for(i=0;i<m;++i)
        a[y[i]].pb(i);
	for(i=0;i<M;++i)
        s[i]=m;
	for(i=0;i<n;s[e]=f,++i)
		for(k=x[i],e=1,f=s[e],u=a[k].sz(),j=0;j<u;)
		{
			v=a[k][j],p=max(p,e);
			if(v<=s[e])
				b[e].pb(mp(i,v)),f=min(f,v),++j;
			else
				s[e]=f,++e,f=s[e];
		}
	printf("%d\n",p),R(b[p][0].F,b[p][0].S,p-1);
}

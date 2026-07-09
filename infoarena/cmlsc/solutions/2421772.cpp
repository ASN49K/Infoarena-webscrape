#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1025;
int a[N],b[N],s[N],n,m,i,j,v;
vector<int> h[257],c,f,l;
vector<int>::iterator d,e;
bool C(const int a,const int b)
{
    return a>b;
}
int main()
{
	freopen("cmlsc.in","r",stdin),freopen("cmlsc.out","w",stdout),scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=m;i++)
		scanf("%d",b+i),h[b[i]].push_back(i);
	for(i=0;i<257;i++)
		sort(h[i].begin(),h[i].end(),C);
	for(i=1;i<=n;i++)
		for(d=h[a[i]].begin();d!=h[a[i]].end();d++)
			c.push_back(*d);
	for(e=c.begin();e!=c.end();e++)
	{
		d=lower_bound(f.begin(),f.end(),*e);
		if(d!=f.end())
			*d=*e,l.push_back(d-f.begin()+1);
		else
			f.push_back(*e),l.push_back(f.size());
	}
	d=max_element(l.begin(),l.end()),i=d-l.begin(),v=*d,
	printf("%d\n",v),s[++s[0]]=b[c[i]];
	for(--i;i>=0;i--)
		if(l[i]==v-1)
			--v,s[++s[0]]=b[c[i]];
	for(i=s[0];i;i--)
		printf("%d ",s[i]);
}

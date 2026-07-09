#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int L=2000000,N=1025;
int a[N],b[N],l[N],s[N],n,m,i,j,k,t=-1,v;
vector<int> h[257],c,f;
vector<int>::iterator d,e;
char p[L];
bool C(const int a,const int b)
{
    return a>b;
}
inline int A()
{
  	int s=0;
  	for(t++;p[t]>47;t++)
  		s=s*10+p[t]-48;
  	return s;
}
inline void S(int b)
{
    if(b<10)
        p[k++]=b+48;
    else if(b<100)
        p[k++]=b/10+48,p[k++]=b%10+48;
    else
        p[k++]=b/100+48,p[k++]=(b/10)%10+48,p[k++]=b%10+48;
}
int main()
{
	freopen("cmlsc.in","r",stdin),freopen("cmlsc.out","w",stdout),fread(p,1,L,stdin),n=A(),m=A();
	for(i=1;i<=n;i++)
		a[i]=A();
	for(i=1;i<=m;i++)
		b[i]=A(),h[b[i]].push_back(i);
	for(i=0;i<257;i++)
		sort(h[i].begin(),h[i].end(),C);
	for(i=1;i<=n;i++)
		for(d=h[a[i]].begin();d!=h[a[i]].end();d++)
			c.push_back(*d);
	for(e=c.begin();e!=c.end();e++)
	{
		d=lower_bound(f.begin(),f.end(),*e);
		if(d!=f.end())
			*d=*e,//l.push_back(d-f.begin()+1);
			l[++l[0]]=d-f.begin()+1;
		else
			f.push_back(*e),//l.push_back(f.size());
			l[++l[0]]=f.size();
	}
	for(i=v=0,j=1;j<=l[0];j++)
        if(l[j]>v)
            v=l[j],i=j-1;
	//d=max_element(l.begin(),l.end()),i=d-l.begin(),v=*d,
	S(v),p[k++]=10,s[++s[0]]=b[c[i]];
	for(;i;i--)
		if(l[i]==v-1)
			--v,s[++s[0]]=b[c[i-1]];
	for(i=s[0];i;i--)
		S(s[i]),p[k++]=32;
    fwrite(p,1,k,stdout);
	return 0;
}

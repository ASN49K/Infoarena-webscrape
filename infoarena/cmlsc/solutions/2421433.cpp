#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define N_MAX 1030
const int L=2000000;
int a[N_MAX],b[N_MAX];
vector<int> h[260];
int n,m,i,j,k,t=-1;
vector<int> c;
vector<int> ::iterator it,it1;
vector<int> bin,l,sol;
unsigned char p[L];
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
inline void S(int b,char c)
{
    if(b<10)
        p[k++]=b+48;
    else if(b<100)
        p[k++]=b/10+48,p[k++]=b%10+48;
    else
        p[k++]=b/100+48,p[k++]=(b/10)%10+48,p[k++]=b%10+48;
	p[k++]=c;
}
int main()
{
	freopen("cmlsc.in","r",stdin),freopen("cmlsc.out","w",stdout),fread(p,1,L,stdin),n=A(),m=A();
	for(i=1;i<=n;i++)
		a[i]=A();
	for(i=1;i<=m;i++)
	{
		b[i]=A();
		h[b[i]].push_back(i);
	}
	for(i=0;i<=256;i++)
		sort(h[i].begin(),h[i].end(),C);
	for(i=1;i<=n;i++)
		for(it=h[a[i]].begin();it!=h[a[i]].end();it++)
			c.push_back(*it);
	for(it1=c.begin();it1!=c.end();it1++)
	{
		it=lower_bound(bin.begin(),bin.end(),*it1);
		if(it!=bin.end())
		{
			*it=*it1;
			l.push_back(it-bin.begin()+1);
		}
		else
		{
			bin.push_back(*it1);
			l.push_back(bin.size());
		}
	}
	it=max_element(l.begin(),l.end());
	int i=it-l.begin(),val=*it;
	S(val,'\n');
	sol.push_back(b[c[i]]);
	for(--i;i>=0;i--)
	{
		if(l[i]==val-1)
		{
			--val;
			sol.push_back(b[c[i]]);
		}
	}
	for(;!sol.empty();sol.pop_back())
		S(sol.back(),' ');
    fwrite(p,1,k,stdout);
	return 0;
}

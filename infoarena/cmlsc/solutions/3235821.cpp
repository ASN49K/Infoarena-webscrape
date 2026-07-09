#include<bits/stdc++.h>
using namespace std;
ifstream F("cmlsc.in");
ofstream G("cmlsc.out");
short a[1024],b[1024],s[1024],n,m,i,j,k,v;
vector<short> h[257],c,f,l;
vector<short>::iterator d,e;
bool C(const int a,const int b)
{
    return a>b;
}
int main()
{
	for(F>>n>>m;i<n;F>>a[i++]);
	for(i=0;i<m;F>>b[i],h[b[i]].push_back(i),++i);
	for(i=0;i<257;sort(h[i].begin(),h[i].end(),C),++i);
	for(i=0;i<n;++i)
		for(d=h[a[i]].begin();d!=h[a[i]].end();c.push_back(*d++));
	for(e=c.begin();e!=c.end();d=lower_bound(f.begin(),f.end(),*e),d!=f.end()?*d=*e,l.push_back(d-f.begin()+1):(f.push_back(*e),l.push_back(f.size())),++e);
	for(d=max_element(l.begin(),l.end()),i=d-l.begin(),v=*d,G<<v<<'\n',s[k++]=b[c[i--]];i>=0;--i)
		if(l[i]==v-1)
			--v,s[k++]=b[c[i]];
	for(;k;G<<s[--k]<<' ');
    return 0;
}

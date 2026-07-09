#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,i,j,ii,jj,zx,xc,K,f[100009],g[100009],DP[100009],dep[100009],msh[100009],msh2[100009],pas;
vector <pair <long long, long long> > v[100009];
void dfsst(long long q, long long w){
	msh[q]=w;
	for(vector <pair <long long, long long> >::iterator it=v[q].begin(); it!=v[q].end(); it++){
		if((*it).first==w) continue;
		dep[(*it).first]=dep[q]+(*it).second;
		msh2[(*it).first]=(*it).second;
		dfsst((*it).first,q);
	}
}
void dfs(long long q, long long w){
	DP[q]=q;
	for(vector <pair <long long, long long> >::iterator it=v[q].begin(); it!=v[q].end(); it++){
		if((*it).first==w) continue;
		dfs((*it).first,q);
		g[(*it).first]=DP[(*it).first];
		if(dep[DP[q]]<dep[DP[(*it).first]]) DP[q]=DP[(*it).first];
	}
}
int main(){
	freopen("paths.in","r",stdin);
	freopen("paths.out","w",stdout);
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>K;
	for(i=1; i<a; i++){
		cin>>c>>d>>e;
		v[c].push_back(make_pair(d,e));
		v[d].push_back(make_pair(c,e));
	}
	for(ii=1; ii<=a; ii++){
		for(i=0; i<=a+1; i++){
			f[i]=0;
		}
		dep[ii]=0;msh2[ii]=0;
		dfsst(ii,0);
		dfs(ii,0);
		for(i=1; i<=a; i++){
			f[g[i]]+=msh2[i];
		}
		sort(f+1,f+a+1);pas=0;
		for(i=a; i>=a-K+1; i--){
			pas+=f[i];
		}
		cout<<pas<<"\n";
	}
	return 0;
}

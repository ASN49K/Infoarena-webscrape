#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,i,j,ii,jj,zx,xc,K,f[100009],g[100009],DP[100009],dep[100009],msh[100009],msh2[100009],pas,ans[100009],I;
pair <pair <long long, long long>, pair <long long, long long> > dp[100009],dp2[100009];
vector <pair <long long, long long> > v[100009];
set <pair <long long, long long> > s;
set <pair <long long, long long> >::iterator IT,tt,TT;
void dfsst(long long q, long long w){
	msh[q]=w;
	DP[q]=q;
	for(vector <pair <long long, long long> >::iterator it=v[q].begin(); it!=v[q].end(); it++){
		if((*it).first==w) continue;
		dep[(*it).first]=dep[q]+(*it).second;
		msh2[(*it).first]=(*it).second;
		dfsst((*it).first,q);
		g[(*it).first]=DP[(*it).first];f[g[(*it).first]]+=msh2[(*it).first];
		if(dep[DP[q]]<dep[DP[(*it).first]]) DP[q]=DP[(*it).first];
	}
}
void upd(long long q, long long w, long long rr){
	if(dp[q].first.first<w){
		dp[q].second=dp[q].first;
		dp[q].first={w,rr};
	}else{
		if(dp[q].second.first<w){
			dp[q].second={w,rr};
		}
	}
}
void dfsst2(long long q, long long w){
	dp[q].first={0,q};
	for(vector <pair <long long, long long> >::iterator it=v[q].begin(); it!=v[q].end(); it++){
		if((*it).first==w) continue;
		dfsst2((*it).first,q);
		upd(q,dp[(*it).first].first.first+(*it).second,dp[(*it).first].first.second);
	}
}
void upd2(long long q, long long w, long long rr){
	if(dp2[q].first.first<w){
		dp2[q].second=dp2[q].first;
		dp2[q].first={w,rr};
	}else{
		if(dp2[q].second.first<w){
			dp2[q].second={w,rr};
		}
	}
}
void dfsst3(long long q, long long w){
	upd2(q,dp[q].first.first,dp[q].first.second);
	upd2(q,dp[q].second.first,dp[q].second.second);
	if(w!=0){
		if(dp2[w].first.second!=dp[q].first.second){
			upd2(q,dp2[w].first.first+msh2[q],dp2[w].first.second);
		}else{
			upd2(q,dp2[w].second.first+msh2[q],dp2[w].second.second);
		}
	}
	for(vector <pair <long long, long long> >::iterator it=v[q].begin(); it!=v[q].end(); it++){
		if((*it).first==w) continue;
		dfsst3((*it).first,q);
	}
}
void Plus(long long q, long w){
	s.insert({q,w});
	if(q>(*IT).first||(q==(*IT).first&&w>(*IT).second)){
		pas-=(*IT).first;
		IT++;
		pas+=q;
	}
}
void Minus(long long q, long long w){
	tt=s.lower_bound({q,w});
	if(tt==IT){
		pas-=(*tt).first;
		IT--;
		pas+=(*IT).first;
		s.erase(tt);
		return;
	}
	if((*tt).first>(*IT).first||((*tt).first==(*IT).first&&(*tt).second>(*IT).second)){
		pas-=(*tt).first;
		IT--;
		pas+=(*IT).first;
	}
	s.erase(tt);
}
void dfs(long long q, long long w){
	ans[q]=pas;
	for(vector <pair <long long, long long> >::iterator it=v[q].begin(); it!=v[q].end(); it++){
		if((*it).first==w) continue;
		Minus(f[g[(*it).first]],g[(*it).first]);
		f[g[(*it).first]]-=(*it).second;
		Plus(f[g[(*it).first]],g[(*it).first]);
		long long Q=0;
		if(dp2[q].first.second!=dp[(*it).first].first.second){
			Q=dp2[q].first.second;
		}else{
			Q=dp2[q].second.second;
		}
		long long QW=g[(*it).first];
		g[(*it).first]=Q;
		Minus(f[g[(*it).first]],g[(*it).first]);
		f[g[(*it).first]]+=(*it).second;
		Plus(f[g[(*it).first]],g[(*it).first]);
		dfs((*it).first,q);
		Minus(f[g[(*it).first]],g[(*it).first]);
		f[g[(*it).first]]-=(*it).second;
		Plus(f[g[(*it).first]],g[(*it).first]);
		g[(*it).first]=QW;
		Minus(f[g[(*it).first]],g[(*it).first]);
		f[g[(*it).first]]+=(*it).second;
		Plus(f[g[(*it).first]],g[(*it).first]);
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
	dfsst(1,0);
	dfsst2(1,0);
	dfsst3(1,0);
	/*for(i=1; i<=a; i++){
		cout<<dp2[i].first.first<<" "<<dp2[i].first.second<<"    "<<dp2[i].second.first<<" "<<dp2[i].second.second<<"\n";
	}
	exit(0);*/
	//
	for(i=1; i<=a; i++){
		s.insert(make_pair(f[i],i));
	}
	s.insert({0,0});
	IT=s.end();pas=0;
	for(i=1; i<=K; i++){
		IT--;pas+=(*IT).first;
	}
	I=K;
	dfs(1,0);
	for(i=1; i<=a; i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}

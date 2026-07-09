#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,i,j,ii,jj,zx,xc,K,p[100009],pi,msh[100009],LEF,RIG,S,EE,pas,RIGdp,F[100009];
//long long dp[209][209],dp2[209];
long long dp[100009],dp2[100009];
vector <pair <long long, long long> > v[100009];
void dfsst(long long q, long long w){
	msh[q]=w;
	if(q!=ii&&v[q].size()==1){
		F[q]=1;
	}else{
		F[q]=0;
	}
	for(vector <pair <long long, long long> >::iterator it=v[q].begin(); it!=v[q].end(); it++){
		if((*it).first==w) continue;
		dfsst((*it).first,q);
	}
	pi++;p[pi]=q;
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
		pi=0;
		dfsst(ii,0);pas=0;
		LEF=0;RIG=1000000000000004;
		EE=0;
		while(1){
			if(LEF+1>=RIG) break;
			S=(LEF+RIG)/2;
			if(EE==0) S=0;
			for(i=0; i<=a+1; i++){
				dp[i]=0;dp2[i]=0;
			}
			for(jj=1; jj<=a; jj++){
				i=p[jj];
				for(vector <pair <long long, long long> >::iterator it=v[i].begin(); it!=v[i].end(); it++){
					if((*it).first==msh[i]) continue;
					if(dp[(*it).first]+(*it).second>0){
						dp[i]+=dp[(*it).first]+(*it).second;
						dp2[i]+=dp2[(*it).first];
					}
				}
				if(F[i]==1){
					dp[i]=-S;dp2[i]=1;
				}else{
					if(dp2[i]==0){
						zx=-1000000000000004;xc=0;
						for(vector <pair <long long, long long> >::iterator it=v[i].begin(); it!=v[i].end(); it++){
							if((*it).first==msh[i]) continue;
							if(dp[(*it).first]+(*it).second>zx){
								zx=dp[(*it).first]+(*it).second;xc=dp2[(*it).first];
							}else{
								if(dp[(*it).first]+(*it).second==zx){
									xc=min(xc,dp2[(*it).first]);
								}
							}
						}
						dp[i]=zx;dp2[i]=xc;
					}
				}
			}
			if(EE==0){
				EE=1;K=min(K,dp2[ii]);
				continue;
			}
			if(dp2[ii]<=K){
				//pas=max(pas,dp[ii]+dp2[ii]*S);
				RIG=S;RIGdp=dp[ii];
			}else{
				LEF=S;
			}
		}
		pas=RIGdp+K*RIG;
		cout<<pas<<"\n";
	}
	return 0;
}

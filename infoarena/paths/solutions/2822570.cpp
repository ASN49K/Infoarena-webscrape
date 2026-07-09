#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,i,j,ii,jj,zx,xc,K,dp[209][209],p[100009],pi,msh[100009],dp2[209];
vector <pair <long long, long long> > v[100009];
void dfsst(long long q, long long w){
	msh[q]=w;
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
		for(i=0; i<=a+1; i++){
			for(j=0; j<=K+1; j++){
				dp[i][j]=0;
			}
		}
		pi=0;
		dfsst(ii,0);
		/*for(jj=1; jj<=a; jj++){
			cout<<p[jj]<<" ";
		}
		cout<<"\n";*/
		for(jj=1; jj<=a; jj++){
			i=p[jj];
			for(j=0; j<=K+1; j++){
				dp2[j]=0;
			}
			for(vector <pair <long long, long long> >::iterator it=v[i].begin(); it!=v[i].end(); it++){
				if((*it).first==msh[i]) continue;
				for(j=0; j<=K; j++){
					for(int J=1; J<=K; J++){
						if(j+J>K) continue;
						//dp[i][j]=max(dp[i][j],dp[(*it).first][J]+dp[i][j-J]+(*it).second);
						dp2[j+J]=max(dp[i][j]+dp[(*it).first][J]+(*it).second,dp2[j+J]);
					}
				}
				for(j=0; j<=K+1; j++){
					dp[i][j]=dp2[j];
				}
			}
		}
		zx=0;
		for(j=1; j<=K; j++){
			zx=max(zx,dp[ii][j]);
		}
		cout<<zx<<"\n";
		//exit(0);
	}
	return 0;
}

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
/*#pragma GCC optimization("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma comment(linker,"/STACK: 20000000005")*/
using namespace std;
long long a,b,c,d,e,i,j,ii,jj,zx,xc,K,lf[1009],rg[1009],tim,seg[4009],seg2[4009],l,r,z,zz,za,dep[1009],rt,pas,L,R;
int SEG[4009];
int msh[1009],bo[1009],msh2[1009];
vector <pair <int, int> > v[1009];
void dfsst(int q, int w){
	tim++;
	lf[q]=rg[q]=tim;
	msh[q]=w;
	for(vector <pair <int, int> >::iterator it=v[q].begin(); it!=v[q].end(); it++){
		if((*it).first==w) continue;
		msh2[(*it).first]=(*it).second;
		dep[(*it).first]=dep[q]+(*it).second;
		dfsst((*it).first,q);
		if(rg[q]<rg[(*it).first]) rg[q]=rg[(*it).first];
	}
}
void pushdown(int q, int w, int rr){
	if(q!=w){
		seg2[rr*2]+=seg2[rr];
		seg2[rr*2+1]+=seg2[rr];
	}
	seg[rr]+=seg2[rr];seg2[rr]=0;
}
void upd(int q, int w, int rr){
	pushdown(q,w,rr);
	if(q>r||w<l) return;
	if(q>=l&&w<=r){
		seg2[rr]=z;
		pushdown(q,w,rr);
		return;
	}
	upd(q,(q+w)/2,rr*2);
	upd((q+w)/2+1,w,rr*2+1);
	//seg[rr]=max(seg[rr*2],seg[rr*2+1]);
	if(seg[rr*2]>=seg[rr*2+1]){
		seg[rr]=seg[rr*2];SEG[rr]=SEG[rr*2];
	}else{
		seg[rr]=seg[rr*2+1];SEG[rr]=SEG[rr*2+1];
	}
}
void read(int q, int w, int rr){
	pushdown(q,w,rr);
	if(q>r||w<l) return;
	if(q>=l&&w<=r){
		//z=max(z,seg[rr]);
		if(z<seg[rr]){
			z=seg[rr];zz=SEG[rr];
		}
		return;
	}
	read(q,(q+w)/2,rr*2);
	read((q+w)/2+1,w,rr*2+1);
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
	for(rt=1; rt<=a; rt++){
		tim=0;
		for(i=1; i<=a; i++){
			bo[i]=0;dep[i]=0;
		}
		dfsst(rt,0);
		za=1;
		while(za<a) za*=2;
		for(i=1; i<=za*2; i++){
			seg2[i]=0;seg[i]=0;SEG[i]=0;
		}
		for(i=1; i<=a; i++){
			seg[za+lf[i]-1]=dep[i];SEG[za+lf[i]-1]=i;
		}
		for(i=za-1; i>=1; i--){
			//seg[i]=max(seg[i*2],seg[i*2+1]);
			if(seg[i*2]>=seg[i*2+1]){
				seg[i]=seg[i*2];SEG[i]=SEG[i*2];
			}else{
				seg[i]=seg[i*2+1];SEG[i]=SEG[i*2+1];
			}
		}
		pas=0;
		for(ii=1; ii<=K; ii++){
			l=1;r=a;z=0;zz=0;
			read(1,za,1);
			if(z<=0) break;
			pas+=z;c=zz;zx=z;
			L=0;R=0;
			while(c!=rt){
				if(bo[c]==1) break;
				bo[c]=1;
				l=lf[c];r=rg[c];z=-zx;
				upd(1,za,1);
				if(L!=0){
					l=L;r=R;z=zx;
					upd(1,za,1);
				}
				
				
				L=lf[c];R=rg[c];
				zx-=msh2[c];
				c=msh[c];
			}
		}
		cout<<pas<<"\n";
	}
	return 0;
}

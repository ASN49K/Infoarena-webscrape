#include<bits/stdc++.h>
#define L nod<<1
#define R L|1
#define NMAX 265000
using namespace std;

int H[NMAX];
int n,m,x,l,r,idx;
long long rs;
map<int,vector<int> >M;

int gcd(int a, int b) {
	if (b==0) return a;
	else return gcd(b,a%b);
}

void update(int st, int dr, int nod) {
	if (st==dr) {
		H[nod]=x;
		return;
	}
	int mid= st+dr >> 1;
	if (idx<=mid) update(st, mid, L);
	else update(mid+1, dr, R);
	H[nod]=gcd(H[L],H[R]);
}

int query(int st, int dr, int nod) {
	if (st>=l && dr<=r) return H[nod];
	
	int mid = st+dr >> 1, left=0, right=0;
	if (l<=mid) left=query(st, mid, L);
	if (r>mid) right=query(mid+1, dr, R);
	return gcd(left, right);
}
int main() {
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>x; idx=i;
		update(1,n,1); //construim arborele actualizind cite un element
		M[x].push_back(i);
	}
	cin>>m;
	for (int i=1; i<=m; i++) {
		cin>>l>>r; rs=0;
		int dc=query(1,n,1); //interogare pe intervalul [l, r]
		int nr1=lower_bound(M[dc].begin(), M[dc].end(), l)-M[dc].begin()+1;
		int nr2=upper_bound(M[dc].begin(), M[dc].end(), r)-M[dc].begin();
		//nr2-nr1 - numarul de numere = gcd cuprinse in intervalul [l, r]
		rs=r-l-(nr2-nr1);
		cout<<rs<<'\n';	
	}
	return 0;
}

#include<bits/stdc++.h>
#define NMAX 263000
#define L nod<<1
#define R L|1
using namespace std;

int n,m,r,idx, val;
int H[NMAX];

void update(int st, int dr, int nod) {
	if (st==dr) {
		H[nod]=val; 
		r=0;
	} else {
		int mid = st+dr >> 1;
		if (idx<=mid) update(st,mid,R);
		else update(mid+1,dr,L);
		
		r++; // r - distanta nodului pina la frunze
		if (r%2==1) H[nod]=(H[R] | H[L]);
		else if (r%2==0) H[nod]=(H[R] ^ H[L]);
	}
}


int main() {
	cin>>n>>m;
	
	//atribuim n = 2^n
	int x=1; for (int i=1; i<=n; i++) x*=2; n=x;
	
	for (int i=1; i<=n; i++) {
		cin>>val; idx=i;
		//cream arborele adaugind in el cite 1 element
		update(1,n,1); 
	}
	
	for (int i=1; i<=m; i++) {
		cin>>idx>>val; 
	
		update(1,n,1);
		cout<<H[1]<<'\n'; //afisam valoarea v = radacina arborelui
	}
	return 0;
}

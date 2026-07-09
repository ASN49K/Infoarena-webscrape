#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

#define lmax 1066
#define vv vector<int>
#define pb(y) push_back(y)
int ll[lmax][lmax];

int n,m,x,y;
vv aa(1),bb(1);

void cmlsc(vv &aa, vv &bb){
	int l1 = aa.size(), l2 = bb.size();
	for(int i=1;i<l1;i++)
		for(int j=1;j<l2;j++)
			if(aa[i]==bb[j]) ll[i][j] = 1 + ll[i-1][j-1]; else
				ll[i][j] = max(ll[i-1][j], ll[i][j-1]);
}

void afis(int n,int m){
	if(ll[n][m]==0)return;
	if(aa[n]==bb[m]){
		afis(n-1,m-1);
		g << aa[n] << " ";
	} else {
		if(ll[n-1][m]>ll[n][m-1])afis(n-1,m); else 
			afis(n,m-1);
	}
}

int main(){
	f >> n >> m;
	for(int i=0;i<n;i++)
	{
		f >> x;
		aa.pb(x);
	}
	for(int j=0;j<m;j++)
	{
		f >> x;
		bb.pb(x);
	}
	cmlsc(aa,bb);
	x=y=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ll[i][j]>ll[x][y])x=i,y=j;
	g << ll[x][y] << endl;
	afis(x,y);
	
	return 0;
}

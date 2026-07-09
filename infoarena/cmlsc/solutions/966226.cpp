#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
ifstream ff("cmlsc.in");
ofstream gg("cmlsc.out");

int n, m, aa[1025], bb[1025], dd[1025][1025];

void gmx(){
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(aa[i]==bb[j]) dd[i][j]=1+dd[i-1][j-1]; else
		dd[i][j]=max(dd[i-1][j],dd[i][j-1]);
}

void pth(int n, int m){
	if(dd[n][m]){
		if(aa[n]==bb[m]){ pth(n-1,m-1); cout << aa[n] << " "; } else
		dd[n-1][m]>dd[n][m-1]?pth(n-1,m):pth(n,m-1);
	}
}

int main(){
	ff >> n >> m;
	for(int i=1;i<=n;i++) ff >> aa[i];
	for(int i=1;i<=m;i++) ff >> bb[i];
	gmx();
	gg << dd[n][m] << "\n";
	pth(n,m);
	return 0;
}

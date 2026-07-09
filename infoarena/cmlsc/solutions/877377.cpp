#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int main() {
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	int m,n;
	fin >> m >> n;
	vector<int> a(m+1),b(n+1);
	vector<vector<iii> > lcp(m+1,vector<iii>(n+1));// last common pair
	for (int i=1; i<=m; ++i) fin >> a[i];
	for (int j=1; j<=n; ++j) fin >> b[j];
	for (int i=1; i<=m; ++i) {
		for (int j=1; j<=n; ++j) {
			if (a[i]==b[j]) lcp[i][j]=iii(lcp[i-1][j-1].first+1, ii(i,j));
			else lcp[i][j]=max(lcp[i-1][j], lcp[i][j-1]);
		}
	}
	deque<int> lcs;// longest common subsequence
	for (iii i=lcp[m][n]; i.first!=0; ) {
		lcs.push_front(a[i.second.first]);
		i=lcp[i.second.first-1][i.second.second-1];
	}
	fout << lcs.size() << '\n';
	for (size_t i=0; i<lcs.size(); ++i) fout << lcs[i] << ' ';
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;
int n, m, a[1025], b[1025];
vector<int>rez;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	if (n <= m) {
		int st = 1;
		for(int i=st;i<=n;++i)
			for(int j=1;j<=m;++j)
				if (b[j] == a[i]) {
					rez.push_back(a[i]), st = j + 1;
					break;
				}
	}
	else {
		int st = 1;
		for(int i=st;i<=m;++i)
			for(int j=1;j<=n;++j)
				if (a[j] == b[i]) {
					rez.push_back(b[i]), st = j + 1;
					break;
				}
	}
	cout << rez.size() << "\n";
	for (auto x : rez)
		cout << x << " ";
	return 0;
}
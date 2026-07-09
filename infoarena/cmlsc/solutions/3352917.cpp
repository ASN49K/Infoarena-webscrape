// Doamne ajuta!!!
#include <bits/stdc++.h>
using namespace std;

vector<int> a(1050);
vector<int> b(1050);
vector<vector<int>> com(1050, vector<int>(1050));
vector<int> recons;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	int m;
	int n;

	cin >> m;
	cin >> n;


	for(int i = 1; i <= m; i++){
		cin >> a[i];
	}

	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[j] == b[i]){
				com[i][j] = 1 + com[i - 1][j - 1];
			}
			else{
				com[i][j] = max(com[i - 1][j], com[i][j - 1]);
			}
		}
	}

	cout << com[n][m] << "\n";

	int i = n;
	int j = m;

	while(i > 0 && j > 0){
		if(a[j] == b[i]){
			recons.push_back(a[j]);
			i--;
			j--;
		}
		else{
			if(com[i - 1][j] > com[i][j - 1]){
				i--;
			}
			else{
				j--;
			}
		}
	}

	for(int i = (int)recons.size() - 1; i >= 0; i--){
		cout << recons[i] << " ";
	}

	return 0;
}
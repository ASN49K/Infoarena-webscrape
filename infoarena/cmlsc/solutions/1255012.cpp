#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<bitset>
using namespace std;
bitset <100001> viz;
vector <int> v[100001];
vector <int> niv(100001, 0);
vector <int> sol(100001, 0);
vector <int> a(100001, 0);
int n = -1;
void dfs(int top)
{
	viz[top] = 1;
	n++;
	niv[n] = top;
	if (a[top] != 0)
		sol[top] = sol[niv[n - a[top]]] + 1;
	for (int i = 0; i < v[top].size(); i++)
	if (viz[v[top][i]] == 0)
		dfs(v[top][i]);
	n--;
}
int main()
{

	ifstream f("cerere.in");
	ofstream g("cerere.out");
	register int n, i, j;
	f >> n;
	for (i = 1; i <= n; i++) f >> a[i];
	while (!f.eof()) {
		f >> i >> j;
		v[i].push_back(j);
		viz[j] = 1;
	}

	for (i = 1; i <= n; i++) if (viz[i] != 1)  break;
	viz.reset();
	dfs(i);
	for (int i = 1; i <= n; i++)
		g << sol[i] << " ";

	//cin.get();
	f.close();
	g.close();
	return 0;
}
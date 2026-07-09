#include <fstream>
#include <vector>
#include <utility>
using namespace std;

int main(){
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	int n, m;
	f >> n >> m;
	vector<int> v1(n+1), v2(m+1);
	for(int i = 1; i <= n; ++i){
		f >> v1[i]; }
	for(int i = 1; i <= m; ++i){
		f >> v2[i]; }
	vector<vector<int> > dinamic(n+1, vector<int>(m+1, 0));
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			dinamic[i][j] = (v1[i]==v2[j] ?
				dinamic[i-1][j-1]+1 :
				max(dinamic[i][j-1], dinamic[i-1][j])); } }
	vector<int> secventa_invers;
	for(int i = n, j = m; i > 0 && j > 0; ){
		if(v1[i] == v2[j]){
			secventa_invers.push_back(v1[i]);
			--i, --j; }
		else if(dinamic[i][j-1] > dinamic[i-1][j]){
			--j; }
		else{
			--i; } }
	g << secventa_invers.size() << '\n';
	for(auto it = secventa_invers.rbegin(); it != secventa_invers.rend(); ++it){
		g << *it << ' '; }
	return 0; }

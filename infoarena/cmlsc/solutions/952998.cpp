#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int memo[1025][1025];
vector<int> ret,a,b;
int ans(int m,int n){
	if(m==0||n==0)return 0;
	if(memo[m][n]!=-1)return memo[m][n];
	if(a[m]==b[n])
		return memo[m][n]=ans(m-1,n-1)+1;
	else return memo[m][n]=max(ans(m-1,n),ans(m,n-1));
}
void backtrack(int m,int n){
	if(m==0||n==0)return;
	else if(a[m]==b[n]){
		ret.push_back(a[m]);
		// cout<<"At ("<<m<<", "<<n<<"), adding "<<a[m]<<'\n';
		backtrack(m-1,n-1);
	}
	else{
		if(memo[m][n-1]>memo[m-1][n])
			backtrack(m,n-1);
		else backtrack(m-1,n);
	}
}
int main(){
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	memset(memo,-1,sizeof memo);
	int m,n,tmp;
	in>>m>>n;
	for(int i=0;i<=n;i++)memo[0][i]=0;
	for(int i=0;i<=m;i++)memo[i][0]=0;
	a.push_back(0);b.push_back(0);
	for(int i=0;i<m;i++){
		in>>tmp;
		a.push_back(tmp);
	}
	for(int i=0;i<n;i++){
		in>>tmp;
		b.push_back(tmp);
	}
	out<<ans(m,n)<<'\n';
	backtrack(m,n);
	for(int i=0;i<ret.size();i++)
		out<<ret[ret.size()-1-i]<<" ";
	return 0;
}
	
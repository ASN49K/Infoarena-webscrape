#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int memo[1025][1025];
vector<int> ret,a,b;
int ans(int m,int n){
	if(m==-1||n==-1)return 0;
	if(memo[m][n]!=-1)return memo[m][n];
	if(a[m]==b[n]){
		ret.push_back(a[m]);
		return memo[m][n]=ans(m-1,n-1)+1;
	}
	else return memo[m][n]=max(ans(m-1,n),ans(m,n-1));
}
int main(){
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	memset(memo,-1,sizeof memo);
	int m,n,tmp;
	in>>m>>n;
	for(int i=0;i<m;i++){
		in>>tmp;
		a.push_back(tmp);
	}
	for(int i=0;i<n;i++){
		in>>tmp;
		b.push_back(tmp);
	}
	out<<ans(m-1,n-1)<<'\n';
	for(int i=0;i<ret.size();i++)
		out<<ret[ret.size()-1-i]<<" ";
	return 0;
}
	
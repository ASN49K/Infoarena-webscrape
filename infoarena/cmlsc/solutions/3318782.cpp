#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int maxn=1050;
int n,m;
int v1[maxn],v2[maxn];
vector<int> rsp;
int solve(int l,int r,vector<int> &rsp1){
    if(r==0 || l==0){
        return 0;
    }
    if(v1[l]==v2[r]){
        rsp1.push_back(v1[l]);
        return solve(l-1,r-1,rsp1)+1;
    }
    vector<int> rsp2=rsp1;
    vector<int> rsp3=rsp1;
    int a=solve(l-1,r,rsp2);
    int b=solve(l,r-1,rsp3);
    if(a>b)rsp1=rsp2;
    else rsp1=rsp3;
    return max(a,b);
}
signed main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>v1[i];
	for (int i = 1; i <=m; i++)cin>>v2[i];
	cout<<solve(n,m,rsp)<<endl;
	reverse(rsp.begin(),rsp.end());
	for(auto elem:rsp)cout<<elem<<" ";
	return 0;
}
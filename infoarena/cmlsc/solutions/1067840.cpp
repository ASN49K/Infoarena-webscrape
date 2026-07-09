#include <fstream>
#include <vector>
using namespace std;
#define maxim 1030
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int main()
{
	int v[maxim], a[maxim],b[maxim],n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
	v[i]=-1;
	cin>>a[i];
}
	for(int i=0; i<m; i++)
	cin>>b[i];
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	if(a[i]==b[j]) v[j]=a[i];
	int s=0;
	vector<int> h;
	for(int i=0; i<m; i++)
	if(v[i]!=-1) 
	{
		s++;
		h.push_back(v[i]);
	}
	cout<<s<<'\n';
	for(int i=0; i<s; i++)
	cout<<h[i]<<' ';
	return 0;
}

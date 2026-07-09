#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int v[256];
int main() {
	int m,n,i,s=0,x;
	in>>m>>n;
	in>>s1>>s2;
	for(i=1;i<=m;++i)
	     cin>>x,++v[x];
	for(i=1;i<=n;++i){
	     cin>>x;
	     if(v[x]) ++s,--v[x];
	}
	out<<s<<" ";
	s=0;
	return 0;
}
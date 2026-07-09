#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int v1[1024];
int v[256];
int main() {
	int m,n,i,s=0,x,k=0;
	in>>m>>n;
	in>>s1>>s2;
	for(i=1;i<=m;++i)
	     in>>x,++v[x];
	for(i=1;i<=n;++i){
	     in>>x;
	     if(v[x]) ++s,--v[x],v1[++k]=x;
	}
	out<<s<<" ";
	for(i=1;i<=k;++i)
		out<<v1[i]<<" ";
	s=0;
	return 0;
}
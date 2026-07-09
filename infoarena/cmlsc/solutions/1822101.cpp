#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
	int A[257],B[257],C[257],m,n,mx,v;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=m;i++) cin>>B[i];
	   for(int i=1;i<=max(m,n);i++)
	      for(int j=1;j<=max(n,m);j++){
	      	  if(A[i]==B[j]){
	      	  	mx++;
				C[++v]=A[i];
				}
	      }
	      cout<<mx<<endl;
	      for(int i=1;i<=mx;i++) cout<<C[i]<<" ";
	      return 0;
}

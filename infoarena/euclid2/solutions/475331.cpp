#include<fstream.h>
ifstream f("euclid2.in"); ofstream g("euclid2.out");
long a,b,n,i;
long cmmdc(long a,long b){
	if(!b)
		return a;
	return cmmdc(b,a%b);
}
int main(){
	f>>n;
	for(i=1;i<=n;i++){
		f>>a>>b;
		g<<cmmdc(a,b)<<'\n';
	}
return 0;
}
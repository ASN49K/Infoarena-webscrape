#include <fstream>
using namespace std;
int cmmdc(int a,int b){
int max,i;
	if(a>b){max=a;a=b;b=max;}
	for(i=a;i>=2;i--)
		if(a%i==0&&b%i==0)return i;
return 1;
}
int main(){
int n,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for(int i=1;i<=n;i++)
	{f>>a>>b;
	g<<cmmdc(a,b)<<"\n";}
return 1;}
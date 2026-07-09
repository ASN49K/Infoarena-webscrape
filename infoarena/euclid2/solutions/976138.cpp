#include <fstream>
using namespace std;
int cmmdc(int a,int b){
int i;
	if(a>b){a+=b;b=a-b;a=a-b;}
	if(b%a==0)return a;
	for(i=a/2;i>=2;i--)
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
f.close();g.close();
return 0;}
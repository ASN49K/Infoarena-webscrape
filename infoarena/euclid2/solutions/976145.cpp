#include <fstream>
using namespace std;
int cmmdc(int a,int b){
if(!b) return a;
return cmmdc(b,a%b);
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
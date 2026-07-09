#include<fstream>
using namespace std;
int m,n,v[1025],x[1025],lsc[1025][1025];
ofstream g("cmlsc.out");
void citire(){
int i,j,k;
ifstream f("cmlsc.in");
f>>m>>n;
for(i=1;i<=m;i++)
	f>>v[i];
for(i=1;i<=n;i++)
	f>>x[i];
f.close();



}
void afisare(int a[1025],int l){
int i;
g<<"\n";
for(i=1;i<=l;i++)
	g<<a[i]<<" ";
g<<"\n";
}
int max(int a,int b)
{
if(a>b)
	return a;
return b;

}
int cmlsc(int i,int j){
	if(i==0||j==0)
		return 0;
	if(v[i]==x[j])
		return 1+cmlsc(i-1,j-1);
	else
		return max(cmlsc(i-1,j),cmlsc(i,j-1));


}
int main(){
citire();
//afisare(x,n);
g<<cmlsc(m,n)<<"\n";
g.close();
}

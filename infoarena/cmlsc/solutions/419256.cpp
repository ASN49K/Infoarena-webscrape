#include<fstream>
using namespace std;
int m,n,v[1025],x[1025],lsc[1025][1025],d[1025];
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
/*void afisare(){
int i,j;
g<<"\n";
for(i=1;i<=m;i++,g<<"\n")
	for(j=1;j<=n;j++)
		
	g<<lsc[i][j]<<" ";
g<<"\n";
}*/
int max(int a,int b)
{
if(a>b)
	return a;
return b;

}
int cmlsc(){
int k,h;
for(k=1;k<=m;k++)
	for(h=1;h<=n;h++){
	if(v[k]==x[h])
	{
	lsc[k][h]=lsc[k-1][h-1]+1;
	
	}
	else
	{
	lsc[k][h]=max(lsc[k-1][h],lsc[k][h-1]);
	}
	
	}
return 0;
}
int main(){
int i,h,k;
	citire();

cmlsc();
g<<lsc[m][n]<<"\n";
//afisare();
i=0;
h=m;
k=n;
while(h>=1&&k>=1)
{
	if(v[h]==x[k]){
d[i++]=v[h];

k--;
h--;

}
else{
	
	if(lsc[h][k]==lsc[h][k-1])
	k--;
	else
	h--;
}
}
for(k=i-1;k>=0;k--)
	g<<d[k]<<" ";

g.close();
}

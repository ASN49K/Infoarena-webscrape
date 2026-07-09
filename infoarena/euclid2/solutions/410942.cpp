#include <fstream.h>
#include<math.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,r,v[100001][3];
int  divide(int x, int y)
{
    if (!y) return x;
    return divide(y, x % y);
}
int main(){
	f>>n;
	for(int i=1;i<=n;i++){f>>v[i][1]>>v[i][2];
	g<<divide(v[i][1],v[i][2])<<'\n';
	/*r=v[i][1]%v[i][2];
while(r){v[i][1]=v[i][2];v[i][2]=r;r=v[i][1]%v[i][2];}
	g<<v[i][2]<<'\n';*/}
g.close();
f.close();
return 0;
}

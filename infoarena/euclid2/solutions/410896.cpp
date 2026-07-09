#include <fstream.h>
#include<math.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,r,v[100001][3];
void divizor (int x, int y){ r=x%y;
while(r){x=y;y=r;r=x%y;}
	g<<y<<'\n';

}
int main(){
	f>>n;
	for(int i=1;i<=n;i++)f>>v[i][1]>>v[i][2],divizor(v[i][1],v[i][2]);

g.close();
f.close();
return 0;
}

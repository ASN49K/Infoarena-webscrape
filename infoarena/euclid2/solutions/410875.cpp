#include <fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,v[100001][3];
void divizor (int x, int y){
	while(x!=y){if(x>y)x-=y;
			else if(x<y)y-=x;}
	g<<x<<'\n';


}
int main(){
	f>>n;
	for(int i=1;i<=n;i++)f>>v[i][1]>>v[i][2],divizor(v[i][1],v[i][2]);

g.close();
f.close();
return 0;
}

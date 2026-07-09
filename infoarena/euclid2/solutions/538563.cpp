#include <fstream.h>
int i,n,x,y;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
	int divizor(int x,int y){
	while(x!=y)if(x>y)x=x-y;else y=y-x;
	
	return x;
	}	
int main(){f>>n;
for(i=1;i<=n;i++){f>>x>>y; g<<divizor(x,y)<<'\n';
}
		g<<'\n';
		
			
		g.close();
		f.close();
		return 0;}
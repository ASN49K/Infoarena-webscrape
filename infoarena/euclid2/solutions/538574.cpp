#include <fstream.h>
int i,n,x,y,d;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
	int divizor(int x,int y){if(x>y)x=x%y;else y=y%x;
	while(x!=0&&y!=0)if(x>y)x=x%y;
	else y=y%x;
	if(x) return x ; else return y;
	}	
int main(){f>>n;
for(i=1;i<=n;i++){f>>x>>y; g<<divizor(x,y)<<'\n';
}
		g<<'\n';
		
			
		g.close();
		f.close();
		return 0;}
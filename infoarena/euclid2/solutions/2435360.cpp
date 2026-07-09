#include <fstream>

using namespace std;


ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int x, int y){
	int r;
	while(y){
		r=x%y;
		x=y;
		y=r;
	}
return x;

}


int main(){
int n, i, x, y;
	f>>n;
for(i=1;i<=n;i++){
	f>>x>>y;
	g<<cmmdc(x,y)<<"\n";
}





}
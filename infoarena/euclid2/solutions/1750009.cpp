#include <iostream>
using namespace std;

int main() {
	File* file,fileo;
	file=freopen("euclid2.in", "r", stdin);
	fileo=	file=freopen("euclid2.out", "w", stdout);
	int x,y,r,t;

	cin>>t;
	for(int i=0;i<t;i++){
		cin>>x>>y;
		while(y!=0){
			r=x%y,x=y,y=r;
		}
		cout<<x;
	}
	
	fclose(file);
	fclose(fileo);
	
	return 0;
}
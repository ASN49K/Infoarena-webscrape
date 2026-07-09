#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	FILE *file,*fileo;
	file=freopen("euclid2.in", "r", stdin);
	fileo=freopen("euclid2.out", "w", stdout);
	int x,y,r,t;

	cin>>t;
	for(int i=0;i<t;i++){
		cin>>x>>y;
		while(y!=0){
			r=x%y,x=y,y=r;
		}
		cout<<x<<endl;
	}
	
	fclose(file);
	fclose(fileo);
}
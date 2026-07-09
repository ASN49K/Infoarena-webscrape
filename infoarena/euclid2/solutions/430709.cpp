#include <iostream>

using namespace std;

void euclid(int a,int b,int& d,int &x,int &y){
	if(b==0){
		d=a;
		x=1,y=0;
	}else{
		int x0,y0;
		euclid(b,a%b,d,x0,y0);
		y=x0-(a/b)*y0;
		x=y0;
	}
}
int main(){
	int x,y,a,b,c,d;
	a=24,b=15,c=147;
	euclid(a,b,c,x,y);
	cout<<x<<" "<<y;
}
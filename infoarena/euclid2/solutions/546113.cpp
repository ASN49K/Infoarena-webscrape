#include<iostream.h>
int u,v;
int euclid (int a, int b){
	int r;
	if(b==0) return a;
	else{
		r=a%b;
		while(r) {
			a=b;
			b=r;
			r=a%b;
		}
		return b;
	}
}
int main() {
	cout<<"u=";
	cin>>u;
	cout<<"v=";
	cin >>v;
	cout<<"cmmdc("<<u<<", "<<v<<")="<<euclid(u,v)<<"\n";
	return 0;
}

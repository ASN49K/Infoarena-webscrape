#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int nr1,int nr2){
	if(nr2==0)
		return (nr1);
	return euclid(nr2,nr1%nr2);
}
int main(){
	int contor;
	int nr1;
	int nr2;

	f >> contor;
	while(contor > 0){
		f>>nr1>>nr2;
		g<<euclid(nr1,nr2)<<"\n";
		--contor;
	}
	return (0);
}
	

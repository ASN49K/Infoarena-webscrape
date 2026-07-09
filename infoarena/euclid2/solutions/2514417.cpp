#include <iostream>
#include <fstream>
using namespace std;

ifstream ci("euclid2.in");
ofstream cou("euclid2.out");

int t,a,b,c;
int main(){
ci >> t;
for(int i=0;i<t;i++){
	ci>>a>>b;
	while(b !=0){
	c=a%b;
	a=b;
	b=c;	
		
	}
	cou << a;
}

}


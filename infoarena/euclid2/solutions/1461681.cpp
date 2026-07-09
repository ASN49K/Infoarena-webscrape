#include <iostream>
#include <fstream>
using namespace std;
int n1,n2,T,i;
int cmmdc(int a,int b){
	if(!b) return a;
	return cmmdc(b,a%b); 
}


int main(){
ifstream f("euclid2.in");
ofstream g("euclid2.out");

f>>T;
for(i=1;i<=T;i++){
	f>>n1>>n2;
	g<<cmmdc(n1,n2)<<"\n";
	
}
f.close();
g.close();
return 0;	
}

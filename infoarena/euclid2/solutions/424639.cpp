#include<iostream>
#include<fstream>
using namespace std;
int cmmdc(int a, int b){
if(b==0)return a; 
else
return cmmdc(b,a%b);}
int main(){
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int n,a,b;
	f>>n;
	for(int i=0;i<n;i++){
		f>>a>>b;
		if(a>b)g<<cmmdc(a,b)<<endl;
		if(b>a)g<<cmmdc(b,a)<<endl;}
	f.close();g.close();
}

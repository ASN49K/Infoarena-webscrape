#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");

int d=1,law=1;
void dosomething(int a,int b){
	if(a%d==0 && b%d==0)
	law=d;
	if(d<=a &&d <=b){
	d++;
	dosomething(a,b);
	}
}
int main() {
	int a,b,c;
	fin>>c;
	for(int i=0;i<c;i++){
		fin>>a>>b;
		dosomething(a,b);
		fout<<law<<endl;
		law=1;
		d=1;
	}
	
}